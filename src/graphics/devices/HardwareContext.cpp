#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			#pragma region Static Variables
			HardwareContext* HardwareContext::Instance = NULL;
			#pragma endregion

			#pragma region Constructors and Finalizers
			HardwareContext::HardwareContext(const HWND hwnd)
				: m_hWnd(hwnd)
			{
				RECT displayRect;
				long width, height;

				if(!hwnd)
					throw SingularityException("No window found to bind the device to.");

				::GetClientRect(this->m_hWnd, &displayRect);

				width = displayRect.right - displayRect.left;
				height = displayRect.bottom - displayRect.top;

				this->_CreateSwapBuffer(this->m_hWnd, width, height);
				this->_CreateBackbuffer();
				this->_CreateDepthStencil(width, height);
				
				this->SetViewport(0, 0, width, height, 0.0f, 1.0f);

				HardwareContext::Instance = this;
			}

			HardwareContext::~HardwareContext()
			{
				if(this->m_pDevice != NULL)
					this->m_pDevice->Release();

				if(this->m_pCurrRenderTarget != NULL)
					this->m_pCurrRenderTarget->Release();

				if(this->m_pSwapChain != NULL)
					this->m_pSwapChain->Release();
			}
			#pragma endregion

			#pragma region Methods
			void HardwareContext::_CreateSwapBuffer(const HWND handle, const unsigned width, const unsigned height)
			{
				HRESULT hr;
				IDXGIFactory* pFactory;
				DXGI_SWAP_CHAIN_DESC sd;

				// generate swap chain(double buffer) description 
				sd.BufferDesc.Width = width;
				sd.BufferDesc.Height = height;
				sd.BufferDesc.RefreshRate.Numerator = 60;
				sd.BufferDesc.RefreshRate.Denominator = 1;
				sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

				sd.SampleDesc.Count = 1;
				sd.SampleDesc.Quality = 0;

				sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				sd.BufferCount = 1;
				sd.OutputWindow = handle;
				sd.Windowed = TRUE;
				sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
				sd.Flags = 0;

				hr = D3D10CreateDeviceAndSwapChain(NULL, D3D10_DRIVER_TYPE_HARDWARE, NULL, NULL, D3D10_SDK_VERSION, &sd, &this->m_pSwapChain, &this->m_pDevice);
				if(FAILED(hr))
					throw SingularityException("Unable to create swap buffer.", hr);
			}

			void HardwareContext::_CreateBackbuffer()
			{
				HRESULT hr;
				ID3D10Texture2D* backbuffer;

				hr = this->m_pSwapChain->GetBuffer(0, __uuidof(ID3D10Texture2D), reinterpret_cast<void**>(&backbuffer));
				if(FAILED(hr))
					throw Singularity::SingularityException("Failed to get swap chain buffer.", hr);

				hr = this->m_pDevice->CreateRenderTargetView(backbuffer, 0, &this->m_pCurrRenderTarget);
				if(FAILED(hr))
					throw Singularity::SingularityException("Failed to create render target.", hr);

				backbuffer->Release();
			}

			void HardwareContext::_CreateDepthStencil(const unsigned width, const unsigned height)
			{
				HRESULT hr;

				D3D10_TEXTURE2D_DESC td;
				td.Width = width;
				td.Height = height;
				td.MipLevels = 1;
				td.ArraySize = 1;
				td.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
				td.SampleDesc.Count = 1;
				td.SampleDesc.Quality = 0;
				td.Usage = D3D10_USAGE_DEFAULT;
				td.BindFlags = D3D10_BIND_DEPTH_STENCIL;
				td.CPUAccessFlags = 0;
				td.MiscFlags = 0;

				if(FAILED(hr = this->m_pDevice->CreateTexture2D(&td, 0, &this->m_pDepthStencilBuffer)))
					throw SingularityException("Unable to create texture 2D for stencil buffer.", hr);

				if(FAILED(hr = this->m_pDevice->CreateDepthStencilView(this->m_pDepthStencilBuffer, 0, &this->m_pDepthStencilView)))
					throw SingularityException("Unable to create stencil buffer.", hr);

				this->m_pDevice->OMSetRenderTargets(1, &this->m_pCurrRenderTarget, this->m_pDepthStencilView);
			}

			void HardwareContext::_ExecuteCommand(CommandType type, CommandData data)
			{
				HRESULT hr;
				unsigned offset;
				ID3D10BlendState* blendstate;
				ID3D10RasterizerState* rasterizerstate;
				D3D10_PASS_DESC passDesc;
				ID3D10InputLayout* inputlayout;
				ID3D10EffectPass* effectpass;

				switch(type)
				{
					case CommandType::NullCommand:
						break;
					case CommandType::SetLayer:
						break;
					case CommandType::SetTopology:
						this->m_pDevice->IASetPrimitiveTopology(data.Topology);
						break;
					case CommandType::SetBlendState:
						hr = this->m_pDevice->CreateBlendState(&data.BlendState.Description, &blendstate);
						if(FAILED(hr))
							throw SingularityException("Unable to create blend state.", hr);

						this->m_pDevice->OMSetBlendState(blendstate, &data.BlendState.BlendFactors[0], data.BlendState.SampleMask);
						break;
					case CommandType::SetRasterizerState:
						hr = this->m_pDevice->CreateRasterizerState(&data.RasterizerState, &rasterizerstate);
						if(FAILED(hr))
							throw SingularityException("Unable to create rasterizer state.", hr);

						this->m_pDevice->RSSetState(rasterizerstate);
						break;
					case CommandType::SetMaterial:
						data.Materials.Material->ApplyLayout(this->m_pDevice, data.Materials.Declaration);
						break;
					case CommandType::SetVertexBuffer:
						this->m_pDevice->IASetVertexBuffers(0, 1, &data.Vertices.Buffer, &data.Vertices.Stride, &data.Vertices.Offset);
						break;
					case CommandType::SetIndexBuffer:
						if(data.Indices.Buffer != NULL)
							this->m_pDevice->IASetIndexBuffer(data.Indices.Buffer, data.Indices.Format, data.Indices.Offset);
						break;
					case CommandType::SetMaterialParameters:
						data.PassParameters->Apply();
						break;
					case CommandType::SetPass:
						if(FAILED(data.Pass.Material->GetPassByIndex(data.Pass.Index)->Apply(0)))
							throw SingularityException("Unable to apply effect pass.");
						break;
					case CommandType::DrawCommand:
						if(data.Draw.Indexed)
							this->m_pDevice->DrawIndexed(data.Draw.Count, data.Draw.Start, data.Draw.BaseVertex);	
						else
							this->m_pDevice->Draw(data.Draw.Count, data.Draw.Start);
						break;
				}
			}

			void HardwareContext::SetResolution(unsigned width, unsigned height, bool fullscreen)
			{
				this->m_pDevice->OMSetRenderTargets(0, NULL, NULL);

				this->m_pCurrRenderTarget->Release();
				this->m_pDepthStencilView->Release();

				this->m_pSwapChain->ResizeBuffers(1, width, height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);

				this->_CreateBackbuffer();
				this->_CreateDepthStencil(width, height);
				
				this->SetViewport(0, 0, width, height);

				this->m_pSwapChain->SetFullscreenState(fullscreen, NULL);
			}

			void HardwareContext::SetViewport(unsigned left, unsigned top, unsigned width, unsigned height, float minDepth, float maxDepth)
			{
				this->m_pViewport.TopLeftX = left;
				this->m_pViewport.TopLeftY = top;
				this->m_pViewport.Width = width;
				this->m_pViewport.Height = height;
				this->m_pViewport.MinDepth = max(minDepth, 0.01f);
				this->m_pViewport.MaxDepth = maxDepth;

				this->m_pDevice->RSSetViewports(1, &this->m_pViewport);
			}
			#pragma endregion

			#pragma region IDeviceContext Methods
			void HardwareContext::Clear(const Color color)
			{
				this->m_pDevice->ClearRenderTargetView(this->m_pCurrRenderTarget, color);
				this->m_pDevice->ClearDepthStencilView(this->m_pDepthStencilView, D3D10_CLEAR_DEPTH | D3D10_CLEAR_STENCIL, 1.0f, 0);
				//this->m_pDevice->OMSetDepthStencilState(0,0);
			}

			void HardwareContext::Flush()
			{
				HRESULT hr;
				hr = this->m_pSwapChain->Present(0,0);
				if(FAILED(hr))
					throw SingularityException("Failed to flush the graphics buffer to the screen.", hr);
			}

			void HardwareContext::Execute(CommandBuffer* buffer, Camera* camera)
			{
				CommandNode* current;
				
				if(camera == NULL)
					camera = Camera::Get_Current();

				this->Clear(camera->Get_BackgroundColor());
				{
					current = buffer->Get_Root();
					do
					{
						this->_ExecuteCommand(current->Type, current->Command);
					}
					while((current = current->Next) != NULL);
				}
				this->Flush();
			}
			#pragma endregion

			#pragma region IDrawingContext Methods
			void HardwareContext::SetView(Matrix& projection, Matrix& view)
			{
				this->m_kProjection = projection;
				this->m_kView = view;
			}

			void HardwareContext::SetRenderState(RenderState& renderstate)
			{
				ID3D10BlendState* blendstate;
				ID3D10RasterizerState* rasterizerstate;
				this->m_kRenderState = renderstate;

				this->m_pDevice->IASetPrimitiveTopology((D3D10_PRIMITIVE_TOPOLOGY)renderstate.PrimitiveType);

				this->m_pDevice->CreateBlendState(&renderstate.BlendDesc, &blendstate);
				this->m_pDevice->OMSetBlendState(blendstate, (float*)renderstate.BlendFactors, renderstate.SampleMask);

				this->m_pDevice->CreateRasterizerState(&renderstate.RasterizerDesc, &rasterizerstate);
				this->m_pDevice->RSSetState(rasterizerstate);
			}

			void HardwareContext::Draw(Material* material, Matrix& world, VertexBuffer* vertices, int start, int length, int pass)
			{
				unsigned			index, count, offset;
				VertexDeclaration*	declaration;
				ID3D10EffectPass*	effectPass;

				if(!this->m_pMaterial)
					throw SingularityException("No material has been set.");

				if(pass != -1 && (pass <= 0 || pass > this->m_pMaterial->m_pInternal->m_sTechniqueDesc.Passes))
					throw SingularityException("Pass index is out of range.");

				offset = 0;
				declaration = vertices->Get_VertexDeclaration();
				start = (start == -1) ? vertices->m_iStart : start;
				length = (length == -1) ? vertices->m_iLength : length;

				this->m_pMaterial = material;
				this->m_pMaterial->m_pInternal->ApplyLayout(this->m_pDevice, declaration);
				this->m_pMaterial->SetVariable("world", world);
				this->m_pMaterial->SetVariable("view", this->m_kView);
				this->m_pMaterial->SetVariable("projection", this->m_kProjection);
				this->m_pMaterial->Apply();

				this->m_pDevice->IASetVertexBuffers(0, 1, &vertices->m_pInternal->m_iBuffer, &declaration->m_iStride, &offset);

				if(pass == -1)
				{
					count = this->m_pMaterial->m_pInternal->m_sTechniqueDesc.Passes;
					for(index = 0; index < count; index++)
					{
						if(FAILED(this->m_pMaterial->m_pInternal->m_pTechnique->GetPassByIndex(index)->Apply(0)))
							throw SingularityException("Unable to render effect pass.");
					}
				}
				else if(FAILED(this->m_pMaterial->m_pInternal->m_pTechnique->GetPassByIndex(pass)->Apply(0)))
					throw SingularityException("Unable to render effect pass.");

				this->m_pDevice->Draw(length, start);
			}

			void HardwareContext::DrawIndexed(Material* material, Matrix& world, VertexBuffer* vertices, IndexBuffer* indices, int start, int length, int vertexOffset, int pass)
			{
				unsigned index, count, offset;
				VertexDeclaration* declaration;
				HRESULT hr;

				if(!this->m_pMaterial)
					throw SingularityException("No material has been set.");

				if(pass != -1 && (pass <= 0 || pass > this->m_pMaterial->Get_PassCount()))
					throw SingularityException("Pass index is out of range.");

				offset = 0;
				declaration = vertices->Get_VertexDeclaration();
				start = (start == -1) ? indices->m_iStart : start;
				length = (length == -1) ? indices->m_iLength : length;
				vertexOffset = (vertexOffset == -1) ? vertices->m_iStart : vertexOffset;

				this->m_pDevice->IASetVertexBuffers(0, 1, &vertices->m_pInternal->m_iBuffer, &declaration->m_iStride, &offset);
				this->m_pDevice->IASetIndexBuffer(indices->m_pInternal->m_iBuffer, DXGI_FORMAT_R32_UINT, indices->m_iStart);

				this->m_pMaterial = material;
				this->m_pMaterial->m_pInternal->ApplyLayout(this->m_pDevice, declaration);
				this->m_pMaterial->SetVariable("world", world);
				this->m_pMaterial->SetVariable("view", this->m_kView);
				this->m_pMaterial->SetVariable("projection", this->m_kProjection);
				this->m_pMaterial->Apply();

				if(pass > -1)
				{
					if(FAILED(this->m_pMaterial->GetPassByIndex(pass)->Apply(0)))
						throw SingularityException("Unable to render effect pass.");

					this->m_pDevice->DrawIndexed(length, start, vertexOffset);
					return;
				}

				count = this->m_pMaterial->Get_PassCount();
				for(index = 0; index < count; ++index)
				{
					if(FAILED(this->m_pMaterial->GetPassByIndex(index)->Apply(0)))
						throw SingularityException("Unable to render effect pass.");

					this->m_pDevice->DrawIndexed(length, start, vertexOffset);
				}
			}
			#pragma endregion
		}
	}
}