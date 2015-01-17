#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			#pragma region Constructors and Finalizers
			DrawingContext::DrawingContext()
				: m_pHardwareDevice(HardwareDevice::Instance), m_pDevice(HardwareDevice::Instance->m_pDevice), m_iLightingCapacity(8), m_iLightingCount(0), m_pLighting(NULL)
			{
				this->m_pLighting = (LIGHT_DESC*)calloc(this->m_iLightingCapacity, sizeof(LIGHT_DESC));
			}

			DrawingContext::~DrawingContext(){};
			#pragma endregion

			#pragma region Methods
			void DrawingContext::SetInputLayout(ID3D10InputLayout* inputlayout)
			{
				this->m_pDevice->IASetInputLayout(inputlayout);
			}

			void DrawingContext::SetVertexBuffer(ID3D10Buffer* buffer, unsigned stride, unsigned start, unsigned length)
			{
				unsigned offset = 0;
				this->m_pDevice->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);		
			}

			void DrawingContext::SetIndexBuffer(ID3D10Buffer* buffer, DXGI_FORMAT format, unsigned start, unsigned length)
			{
				if(buffer)
					this->m_pDevice->IASetIndexBuffer(buffer, format, 0);
			}

			void DrawingContext::SetMaterial(Material* material)
			{
				material->Apply();
			}

			void DrawingContext::SetPass(ID3D10EffectPass* pass)
			{
				if(FAILED(pass->Apply(0)))
					throw SingularityException("Unable to apply effect pass.");
			}

			void DrawingContext::Draw(unsigned length, unsigned start)
			{
				this->m_pDevice->Draw(length, start);
			}

			void DrawingContext::DrawIndexed(unsigned length, unsigned  start, unsigned vertexOffset)
			{
				this->m_pDevice->DrawIndexed(length, start, vertexOffset);
			}

			void DrawingContext::Clear(const Color color)
			{
				this->m_iLightingCount = 0;
				this->m_pDevice->ClearRenderTargetView(this->m_pHardwareDevice->m_pCurrRenderTarget, color);
				this->m_pDevice->ClearDepthStencilView(this->m_pHardwareDevice->m_pDepthStencilView, D3D10_CLEAR_DEPTH | D3D10_CLEAR_STENCIL, 1.0f, 0);
				//this->m_pDevice->OMSetDepthStencilState(0,0);
			}

			void DrawingContext::Flush()
			{
				HRESULT hr;
				if(FAILED(hr = this->m_pHardwareDevice->m_pSwapChain->Present(0,0)))
					throw SingularityException("Failed to flush the graphics buffer to the screen.", hr);
			}

			void DrawingContext::AddLight(Light* light)
			{
				if(this->m_iLightingCount == this->m_iLightingCapacity)
				{
					this->m_iLightingCount = 0;
					throw SingularityException("No more lights available.");
				}

				light->m_kDescription.Position = light->Get_GameObject()->Get_Transform()->Get_Position();
				this->m_pLighting[this->m_iLightingCount++] = light->m_kDescription;
			}

			void DrawingContext::SetRenderState(RenderState& renderstate)
			{	
				ID3D10BlendState* blendstate;
				ID3D10RasterizerState* rasterizerstate;

				this->m_pDevice->IASetPrimitiveTopology((D3D10_PRIMITIVE_TOPOLOGY)renderstate.PrimitiveType);

				this->m_pDevice->CreateBlendState(&renderstate.BlendDesc, &blendstate);
				this->m_pDevice->OMSetBlendState(blendstate, (float*)renderstate.BlendFactors, renderstate.SampleMask);

				this->m_pDevice->CreateRasterizerState(&renderstate.RasterizerDesc, &rasterizerstate);
				this->m_pDevice->RSSetState(rasterizerstate);
			}

			void DrawingContext::Draw(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, int start, int length)
			{
				unsigned offset;
				VertexDeclaration*	declaration;

				if(!material)
					throw SingularityException("No material has been set.");

				offset = 0;
				declaration = vertices->Get_VertexDeclaration();
				start = (start == -1) ? vertices->m_iStart : start + vertices->m_iStart;
				length = (length == -1) ? vertices->Get_Length() : length;

				material->SetVariable("_Camera", &camera->Get_Description(), sizeof(CAMERA_DESC));
				material->SetVariable("_World", world);
				material->SetVariable("_Lights", this->m_pLighting, this->m_iLightingCount * sizeof(LIGHT_DESC));

				this->SetLighting(this->m_pLighting, this->m_iLightingCount);
				this->SetInputLayout(material->m_pShader->GetInputLayout(this->m_pDevice, declaration, material->m_iPass));
				this->SetVertexBuffer(vertices->m_pInternal->m_iBuffer, declaration->m_iStride, vertices->m_iStart, vertices->m_iLength);
				this->SetIndexBuffer(NULL, DXGI_FORMAT_R32_UINT, 0, 0);
				this->SetMaterial(material);
				this->SetPass(material->m_pShader->m_pTechnique->GetPassByIndex(material->m_iPass));
				this->Draw(length, start);
			}

			void DrawingContext::DrawIndexed(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, IndexBuffer* indices, int start, int length, int vertexOffset)
			{
				D3D10_EFFECT_TYPE_DESC desc;
				ID3D10EffectType* type;
				ID3D10EffectVariable* variable;
				unsigned offset;
				VertexDeclaration* declaration;

				if(!material)
					throw SingularityException("No material has been set.");
				if(!vertices)
					throw SingularityException("No vertex buffer has been set.");
				if(!indices)
					throw SingularityException("No index buffer has been set.");

				offset = 0;
				declaration = vertices->Get_VertexDeclaration();
				start = (start == -1) ? indices->m_iStart : start + indices->m_iStart;
				length = (length == -1) ? indices->Get_Length() : length;
				vertexOffset = (vertexOffset == -1) ? vertices->m_iStart : vertexOffset + vertices->m_iStart;

				material->SetVariable("_Camera", &camera->Get_Description(), sizeof(CAMERA_DESC));
				material->SetVariable("_World", world);
				material->SetVariable("_Lights", this->m_pLighting, this->m_iLightingCapacity * sizeof(LIGHT_DESC));

				variable = material->m_pShader->m_pEffect->GetVariableByName("_Lights");
				type = variable->GetType();
				type->GetDesc(&desc);

				this->SetLighting(this->m_pLighting, this->m_iLightingCount);
				this->SetInputLayout(material->m_pShader->GetInputLayout(this->m_pDevice, declaration, material->m_iPass));
				this->SetVertexBuffer(vertices->m_pInternal->m_iBuffer, declaration->m_iStride, vertices->m_iStart, vertices->m_iLength);
				this->SetIndexBuffer(indices->m_pInternal->m_iBuffer, DXGI_FORMAT_R32_UINT, indices->m_iStart, indices->m_iLength);
				this->SetMaterial(material);
				this->SetPass(material->m_pShader->m_pTechnique->GetPassByIndex(material->m_iPass));
				this->DrawIndexed(length, start, vertexOffset);
			}
			#pragma endregion
		}
	}
}
