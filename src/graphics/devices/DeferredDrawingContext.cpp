#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			#pragma region Static Variables
			Material* DeferredDrawingContext::g_pGBufferMaterial = NULL;
			Material* DeferredDrawingContext::g_pLightingMaterial = NULL;
			Material* DeferredDrawingContext::g_pCombineMaterial = NULL;
			#pragma endregion

			#pragma region Constructors and Deconstructors
			DeferredDrawingContext::DeferredDrawingContext()
			{
				unsigned width, height;
				int left, top;
				float minDepth, maxDepth;
				HRESULT hr;

				this->Get_HardwareDevice()->GetViewport(left, top, width, height, minDepth, maxDepth);

				this->m_pHalfPixel = Vector2(0.5f / (float)width, 0.5f / (float)height);
				
				//setting up the three render targets, we ignore the left, top, minDepth, and maxDepth variables from when we retrieve the viewport size
				this->m_pRenderTargets[0] = new RenderTexture(width, height, DXGI_FORMAT_R8G8B8A8_UNORM);	//Diffuse
				this->m_pRenderTargets[1] = new RenderTexture(width, height, DXGI_FORMAT_R8G8B8A8_UNORM);	//Normal Map
				this->m_pRenderTargets[2] = new RenderTexture(width, height, DXGI_FORMAT_R32G32B32A32_FLOAT);		//Depth Map
				this->m_pRenderTargets[3] = new RenderTexture(width, height, DXGI_FORMAT_R8G8B8A8_UNORM);	//Light Map
				this->m_pRenderTargets[4] = new RenderTexture(width, height, DXGI_FORMAT_R8G8B8A8_UNORM);

				/*this->m_pGBufferTextures[0] = 0;
				this->m_pGBufferRenderTargetView[0] = 0;
				this->m_pGBufferShaderResourceView[0] = 0;

				this->m_pGBufferTextures[1] = 0;
				this->m_pGBufferRenderTargetView[1] = 0;
				this->m_pGBufferShaderResourceView[1] = 0;

				this->m_pGBufferTextures[2] = 0;
				this->m_pGBufferRenderTargetView[2] = 0;
				this->m_pGBufferShaderResourceView[2] = 0;

				this->m_pLightTexture = 0;
				this->m_pLightRenderTargetView = 0;
				this->m_pLightShaderResourceView = 0;
				this->m_pLightBlendState = 0;

				this->m_pCombineTexture = 0;
				this->m_pCombineRenderTargetView = 0;
				this->m_pCombineShaderResourceView = 0;*/

				
				//loading in the materials to process through the deferred renderer
				DeferredDrawingContext::CreateDeferredCombineMaterial();
				DeferredDrawingContext::CreateDeferredGBufferMaterial();
				DeferredDrawingContext::CreateDeferredLightingMaterial();

				//setting up the buffers for the quad renderings
				//base vertices
				this->m_pVertices = new VertexPositionTexture[4];
				this->m_pVertices[0] = VertexPositionTexture(Vector3(-1,-1,0), Vector2(0,0));
				this->m_pVertices[1] = VertexPositionTexture(Vector3(1,-1,0), Vector2(1,0));
				this->m_pVertices[2] = VertexPositionTexture(Vector3(-1,1,0), Vector2(0,1));
				this->m_pVertices[3] = VertexPositionTexture(Vector3(1,1,0), Vector2(1,1));

				this->m_pVertexBuffer = new VertexBuffer(VertexPositionTexture::Declaration, 4);
				
				this->m_pVertexBuffer->SetData(&this->m_pVertices[0]);
				unsigned indices[6] = {0, 1, 2, 2, 3, 0};
				

				this->m_pIndexBuffer = new IndexBuffer(6);
				this->m_pIndexBuffer->SetData(&indices[0]);

				////Create the blend state for the light map
				//D3D10_BLEND_DESC blendDesc;
				//memset(&blendDesc, 0, sizeof(D3D10_BLEND_DESC));
				//blendDesc.AlphaToCoverageEnable = false;
				//blendDesc.BlendEnable[0] = true;
				//blendDesc.SrcBlend = D3D10_BLEND_ONE;
				//blendDesc.DestBlend = D3D10_BLEND_ONE;
				//blendDesc.BlendOp = D3D10_BLEND_OP_ADD;
				//blendDesc.SrcBlendAlpha = D3D10_BLEND_SRC_ALPHA;
				//blendDesc.DestBlendAlpha = D3D10_BLEND_INV_SRC_ALPHA;
				//blendDesc.BlendOpAlpha = D3D10_BLEND_OP_ADD;
				//blendDesc.RenderTargetWriteMask[0] = D3D10_COLOR_WRITE_ENABLE_ALL;
			
				//hr = this->Get_InternalDevice()->CreateBlendState(&blendDesc, &this->m_pLightBlendState);
				//if(FAILED(hr))
				//	throw SingularityException("Failed to create light map blend state", hr);

				//Creating the renderstate for the lighting map
				this->m_pLightRenderState;
				this->m_pLightRenderState.Set_PrimitiveType(PrimitiveTopology::TriangleStrip);
				this->m_pLightRenderState.EnableBlend(0);
				this->m_pLightRenderState.Set_EnableAlphaToCoverage(false);
				this->m_pLightRenderState.Set_SourceBlend(Blend::One);
				this->m_pLightRenderState.Set_DestinationBlend(Blend::One);
				this->m_pLightRenderState.Set_BlendFunction(BlendFunction::Add);
				this->m_pLightRenderState.Set_AlphaSourceBlend(Blend::SourceAlpha);
				this->m_pLightRenderState.Set_AlphaDestinationBlend(Blend::InverseSourceAlpha);
				this->m_pLightRenderState.Set_AlphaBlendOperation(BlendFunction::Add);
				this->m_pLightRenderState.SetWriteMask(0, WriteEnable::All);
				//this->_BuildResources(width, height);
			}

			DeferredDrawingContext::~DeferredDrawingContext() {};
			#pragma endregion

			#pragma region Private Methods
			void DeferredDrawingContext::SetGBuffer()
			{
				Color clearColor = Camera::Get_Current()->Get_BackgroundColor();

				//set the render targets to the device
				ID3D10RenderTargetView* rtView[3];
				rtView[0] = this->m_pRenderTargets[0]->Get_RenderTargetView();
				rtView[1] = this->m_pRenderTargets[1]->Get_RenderTargetView();
				rtView[2] = this->m_pRenderTargets[2]->Get_RenderTargetView();
				
				this->Get_InternalDevice()->OMSetRenderTargets(3, rtView, this->Get_HardwareDevice()->m_pDepthStencilView);

				//clearing the three render targets that recieve the first maps
				this->Get_InternalDevice()->ClearRenderTargetView(this->m_pRenderTargets[0]->Get_RenderTargetView(), clearColor);
				this->Get_InternalDevice()->ClearRenderTargetView(this->m_pRenderTargets[1]->Get_RenderTargetView(), clearColor);
				this->Get_InternalDevice()->ClearRenderTargetView(this->m_pRenderTargets[2]->Get_RenderTargetView(), clearColor);
			}

			void DeferredDrawingContext::_ResolveBuffer()
			{
				this->Get_InternalDevice()->OMSetRenderTargets(0, NULL, NULL);
			}

			void DeferredDrawingContext::_RenderLightMap()
			{
				float blendFactors[4] = {0.0f, 0.0f, 0.0f, 0.0f};
				
				//Set the render target and clear the buffer
				ID3D10RenderTargetView* rtView = this->m_pRenderTargets[3]->Get_RenderTargetView();
				this->Get_InternalDevice()->OMSetRenderTargets(1, &rtView, NULL);
				this->Get_InternalDevice()->ClearRenderTargetView(rtView, Camera::Get_Current()->Get_BackgroundColor());

				this->SetRenderState(this->m_pLightRenderState);
				
				DeferredDrawingContext::g_pLightingMaterial->Set_MainTexture(this->m_pRenderTargets[2]);	//Normal Map
				DeferredDrawingContext::g_pLightingMaterial->SetVariable("_DepthMap", (Texture2D*)this->m_pRenderTargets[2]);
				DeferredDrawingContext::g_pLightingMaterial->SetVariable("_HalfPixel", this->m_pHalfPixel);
				DeferredDrawingContext::g_pLightingMaterial->SetVariable("_Lights", this->Get_Lights(), this->Get_LightCount() * sizeof(LIGHT_DESC));
				
				
				Matrix inverseViewProjection, viewProjection;
				viewProjection = Camera::Get_Current()->Get_View() * Camera::Get_Current()->Get_Projection();
				inverseViewProjection = viewProjection.inverse();

				DeferredDrawingContext::g_pLightingMaterial->SetVariable("_InverseViewProjection", viewProjection);

				DeferredDrawingContext::g_pLightingMaterial->Apply();

				this->SetLighting(this->Get_Lights(), this->Get_LightCount());
				this->SetMaterial(DeferredDrawingContext::g_pLightingMaterial);
				this->SetInputLayout(DeferredDrawingContext::g_pLightingMaterial->m_pShader->GetInputLayout(this->Get_InternalDevice(), VertexPositionTexture::Declaration, DeferredDrawingContext::g_pLightingMaterial->m_iPass));
				this->SetPass(DeferredDrawingContext::g_pLightingMaterial->m_pShader->m_pTechnique->GetPassByIndex(DeferredDrawingContext::g_pLightingMaterial->m_iPass));
				this->SetVertexBuffer(this->m_pVertexBuffer->m_pInternal->m_iBuffer, this->m_pVertexBuffer->Get_VertexDeclaration()->m_iStride, this->m_pVertexBuffer->m_iLength, this->m_pVertexBuffer->m_iLength);
				this->Draw(4, 0);

				//Reseting the blend state
				this->Get_InternalDevice()->OMSetBlendState(NULL, blendFactors, 0xffffffff); 
			}

			void DeferredDrawingContext::_RenderFinalScene()
			{
				Color clearColor = Camera::Get_Current()->Get_BackgroundColor();

				//Set the render target
				//this->Get_InternalDevice()->OMSetRenderTargets(1, this->m_pRenderTargets[4]->Get_RenderTargetView(), NULL);
				this->Get_InternalDevice()->ClearRenderTargetView(this->m_pRenderTargets[4]->Get_RenderTargetView(), clearColor);

				//render the final scene with the diffuse render target and the light map
				DeferredDrawingContext::g_pCombineMaterial->SetVariable("_MainTex", this->m_pRenderTargets[0]);
				DeferredDrawingContext::g_pCombineMaterial->SetVariable("_LightMap", this->m_pRenderTargets[3]);
				DeferredDrawingContext::g_pCombineMaterial->SetVariable("_HalfPixel", this->m_pHalfPixel);
				
				this->SetMaterial(DeferredDrawingContext::g_pCombineMaterial);
				this->SetInputLayout(DeferredDrawingContext::g_pCombineMaterial->m_pShader->GetInputLayout(this->Get_InternalDevice(), VertexPositionTexture::Declaration, DeferredDrawingContext::g_pCombineMaterial->m_iPass));
				this->SetPass(DeferredDrawingContext::g_pCombineMaterial->m_pShader->m_pTechnique->GetPassByIndex(DeferredDrawingContext::g_pCombineMaterial->m_iPass));
				this->Draw(4, 0);
			}

			void DeferredDrawingContext::_RenderQuad()
			{
				//Setting the vertex data
				/*this->m_pVertices[0].position.x = bottomRight.x;
				this->m_pVertices[0].position.y = topLeft.y;

				this->m_pVertices[1].position.x = topLeft.x;
				this->m_pVertices[1].position.y = topLeft.y;

				this->m_pVertices[2].position.x = topLeft.x;
				this->m_pVertices[2].position.y = bottomRight.y;

				this->m_pVertices[3].position.x = bottomRight.x;
				this->m_pVertices[3].position.y = bottomRight.y;*/

				//setting the buffers
				this->SetVertexBuffer(this->m_pVertexBuffer->m_pInternal->m_iBuffer, this->m_pVertexBuffer->Get_VertexDeclaration()->m_iStride, this->m_pVertexBuffer->m_iLength, this->m_pVertexBuffer->m_iLength);
				//this->SetIndexBuffer(this->m_pIndexBuffer->m_pInternal->m_iBuffer, DXGI_FORMAT_R32_UINT, this->m_pIndexBuffer->m_iStart, this->m_pIndexBuffer->m_iLength);
				//this->SetIndexBuffer(NULL, DXGI_FORMAT_R32_UINT, 0, 0);
				this->Draw(4, 0);
			}
			#pragma endregion

			#pragma region Methods
			void DeferredDrawingContext::SetLayer(unsigned layer)
			{
				this->m_pLayer = layer;
			}

			void DeferredDrawingContext::Draw(unsigned length, unsigned start)
			{
				this->Get_InternalDevice()->Draw(length, start);
			}

			void DeferredDrawingContext::DrawIndexed(unsigned length, unsigned  start, unsigned vertexOffset)
			{
				this->Get_InternalDevice()->DrawIndexed(length, start, vertexOffset);
			}


			void DeferredDrawingContext::Draw(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, int start, int length)
			{	
				unsigned offset;
				VertexDeclaration*	declaration;

				if(!material)
					throw SingularityException("No material has been set.");
				if(!vertices)
					throw SingularityException("No vertex buffer has been set.");
				
				//printf("%pLayer: ", this->m_pLayer); 

				//If layer that is being drawn is not 0, we use the material being passed in, otherwise we use the deferred material
				if(this->m_pLayer == 0)
				{
					//this->_SetGBuffer();
					//DeferredDrawingContext::g_pGBufferMaterial->Set_MainTexture((Texture2D*)material->Get_MainTexture());
					DeferredDrawingContext::g_pLightingMaterial->Set_MainTexture((Texture2D*)material->Get_MainTexture());
					//material = DeferredDrawingContext::g_pGBufferMaterial;
					material = DeferredDrawingContext::g_pLightingMaterial;
				}

				offset = 0;
				declaration = vertices->Get_VertexDeclaration();
				start = (start == -1) ? vertices->m_iStart : start + vertices->m_iStart;
				length = (length == -1) ? vertices->Get_Length() : length;

				material->SetVariable("_Camera", &camera->Get_Description(), sizeof(CAMERA_DESC));
				material->SetVariable("_World", world);
				material->SetVariable("_Lights", this->Get_Lights(), this->Get_LightCapacity() * sizeof(LIGHT_DESC));
				
				
				//If layer that is being drawn is 
				this->SetInputLayout(material->m_pShader->GetInputLayout(this->Get_InternalDevice(), declaration, material->m_iPass));
				this->SetVertexBuffer(vertices->m_pInternal->m_iBuffer, declaration->m_iStride, vertices->m_iStart, vertices->m_iLength);
				this->SetIndexBuffer(NULL, DXGI_FORMAT_R32_UINT, 0, 0);
				
				material->Apply();
				this->SetMaterial(material);

				this->SetPass(material->m_pShader->m_pTechnique->GetPassByIndex(material->m_iPass));
				this->Draw(length, start);
			}

			void DeferredDrawingContext::DrawIndexed(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, IndexBuffer* indices, int start, int length, int vertexOffset)
			{
				D3D10_EFFECT_TYPE_DESC desc;
				VertexDeclaration* declaration;
				ID3D10EffectType* type;
				ID3D10EffectVariable* variable;

				if(!material)
					throw SingularityException("No material has been set.");
				if(!vertices)
					throw SingularityException("No vertex buffer has been set.");
				if(!indices)
					throw SingularityException("No index buffer has been set.");

				//printf("%pLayer: ", this->m_pLayer); 
				//printf("%pLayer: ", this->m_pLayer); 

				//If layer that is being drawn is not 0, we use the material being passed in, otherwise we use the deferred material
				if(this->m_pLayer == 0)
				{
					//this->SetGBuffer();
					DeferredDrawingContext::g_pGBufferMaterial->Set_MainTexture((Texture2D*)material->Get_MainTexture());
					material = DeferredDrawingContext::g_pGBufferMaterial;

				}
				declaration = vertices->Get_VertexDeclaration();
				start = (start == -1) ? indices->m_iStart : start + indices->m_iStart;
				length = (length == -1) ? indices->Get_Length() : length;
				vertexOffset = (vertexOffset == -1) ? vertices->m_iStart : vertexOffset + vertices->m_iStart;

				material->SetVariable("_Camera", &camera->Get_Description(), sizeof(CAMERA_DESC));
				material->SetVariable("_World", world);
				material->SetVariable("_Lights", this->Get_Lights(), this->Get_LightCapacity() * sizeof(LIGHT_DESC));

				variable = material->m_pShader->m_pEffect->GetVariableByName("_Lights");
				type = variable->GetType();
				type->GetDesc(&desc);

				this->SetLighting(this->Get_Lights(), this->Get_LightCount());
				this->SetInputLayout(material->m_pShader->GetInputLayout(this->Get_InternalDevice(), declaration, material->m_iPass));
				this->SetVertexBuffer(vertices->m_pInternal->m_iBuffer, declaration->m_iStride, vertices->m_iStart, vertices->m_iLength);
				this->SetIndexBuffer(indices->m_pInternal->m_iBuffer, DXGI_FORMAT_R32_UINT, indices->m_iStart, indices->m_iLength);
				this->SetMaterial(material);
				this->SetPass(material->m_pShader->m_pTechnique->GetPassByIndex(material->m_iPass));
				this->DrawIndexed(length, start, vertexOffset);
			}

			void DeferredDrawingContext::Flush()
			{
				//DrawingContext::Clear(Camera::Get_Current()->Get_BackgroundColor());
				//flush 0 renders the light map then the final scene
				this->_RenderLightMap();
				this->_RenderFinalScene();

				DrawingContext::Flush();
			}
			#pragma endregion

			#pragma region Static Methods
			Material* DeferredDrawingContext::CreateDeferredGBufferMaterial()
			{
				HRSRC src;
				HANDLE bytes;
				String basicmaterial;
				char id[5];

				if(DeferredDrawingContext::g_pGBufferMaterial == NULL)
				{
					id[0] = '#';
					_itoa_s(IDR_BINARY12, &id[1], 4, 10);
					src = ::FindResource(NULL, id, "BINARY");
					bytes = ::LoadResource(NULL, src);
					basicmaterial = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
					DeferredDrawingContext::g_pGBufferMaterial = Singularity::Graphics::Material::LoadMaterialFromMemory(String("DeferredGBufferMaterial"),  basicmaterial);
					::FreeResource(bytes);
					return DeferredDrawingContext::g_pGBufferMaterial;
				}
				return DeferredDrawingContext::g_pGBufferMaterial->Clone();
			}

			Material* DeferredDrawingContext::CreateDeferredLightingMaterial()
			{
				HRSRC src;
				HANDLE bytes;
				String basicmaterial;
				char id[5];

				if(DeferredDrawingContext::g_pLightingMaterial == NULL)
				{
					id[0] = '#';
					_itoa_s(IDR_BINARY13, &id[1], 4, 10);
					src = ::FindResource(NULL, id, "BINARY");
					bytes = ::LoadResource(NULL, src);
					basicmaterial = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
					DeferredDrawingContext::g_pLightingMaterial = Singularity::Graphics::Material::LoadMaterialFromMemory(String("DeferredLightingMaterial"),  basicmaterial);
					::FreeResource(bytes);
					return DeferredDrawingContext::g_pLightingMaterial;
				}
				return DeferredDrawingContext::g_pLightingMaterial->Clone();
			}

			Material* DeferredDrawingContext::CreateDeferredCombineMaterial()
			{
				HRSRC src;
				HANDLE bytes;
				String basicmaterial;
				char id[5];

				if(DeferredDrawingContext::g_pCombineMaterial == NULL)
				{
					id[0] = '#';
					_itoa_s(IDR_BINARY14, &id[1], 4, 10);
					src = ::FindResource(NULL, id, "BINARY");
					bytes = ::LoadResource(NULL, src);
					basicmaterial = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
					DeferredDrawingContext::g_pCombineMaterial = Singularity::Graphics::Material::LoadMaterialFromMemory(String("DeferredLightingMaterial"),  basicmaterial);
					::FreeResource(bytes);
					return DeferredDrawingContext::g_pCombineMaterial;
				}
				return DeferredDrawingContext::g_pCombineMaterial->Clone();
			}
		}
	}
}