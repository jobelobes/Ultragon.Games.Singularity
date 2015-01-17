#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			#pragma region Static Variables
			HardwareDevice* HardwareDevice::Instance = new HardwareDevice(800, 600);
			#pragma endregion

			#pragma region Constructors and Finalizers
			HardwareDevice::HardwareDevice(const unsigned width, const unsigned height)
				: m_hWnd(NULL)
			{
				this->_CreateWindow("Singularity Window", width, height);
				this->_CreateSwapBuffer(this->m_hWnd, width, height);
				this->_CreateBackbuffer();
				this->_CreateDepthStencil(width, height);
				
				this->SetViewport(0, 0, width, height, 0, 1);

				this->_ShowWindow();
			}

			HardwareDevice::~HardwareDevice()
			{
				if(this->m_pDevice != NULL)
					this->m_pDevice->Release();

				if(this->m_pCurrRenderTarget != NULL)
					this->m_pCurrRenderTarget->Release();

				if(this->m_pSwapChain != NULL)
					this->m_pSwapChain->Release();

				if (this->m_hWnd && !::DestroyWindow(this->m_hWnd))
					this->m_hWnd = NULL;

				if(this->m_kWndClass.hInstance != NULL)
					::UnregisterClass(this->m_kWndClass.lpszClassName, this->m_kWndClass.hInstance);
			}
			#pragma endregion

			#pragma region Methods
			void HardwareDevice::_CreateWindow(String title, const unsigned width, const unsigned height)
			{
				unsigned windowWidth, windowHeight;
				unsigned screenWidth, screenHeight;
				RECT displayRect;
				
				screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
				screenHeight = ::GetSystemMetrics(SM_CYSCREEN);

				// just in case someone puts in a size greater than the screen size
				windowWidth = screenWidth < width? screenWidth : width;
				windowHeight = screenHeight < height? screenHeight : height;
				displayRect.left = (screenWidth - windowWidth) / 2;
				displayRect.top = (screenHeight - windowHeight) / 2;
				displayRect.right = displayRect.left + windowWidth;
				displayRect.bottom = displayRect.top + windowHeight;

				this->m_kWndClass = HardwareDevice::RegisterClass("Singularity.Window");

				// make any adjustments to the display rect to handle the styles
				::AdjustWindowRectEx(&displayRect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);

				// create the actual window from the style def and class
				this->m_hWnd = ::CreateWindowEx(
					WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
					this->m_kWndClass.lpszClassName,
					title.c_str(),
					WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
					displayRect.left,
					displayRect.top,
					displayRect.right - displayRect.left,
					displayRect.bottom - displayRect.top,
					NULL,
					NULL,
					this->m_kWndClass.hInstance,
					NULL);
				if (!this->m_hWnd)
					throw SingularityException("Unable to create window.");

				// set user data
				::SetWindowLongPtr(this->m_hWnd, GWLP_USERDATA, (long)this);
			}

			void HardwareDevice::_CreateSwapBuffer(const HWND handle, const unsigned width, const unsigned height)
			{
				HRESULT hr;
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

			void HardwareDevice::_CreateBackbuffer()
			{
				HRESULT hr;
				ID3D10Texture2D* backbuffer;

				hr = this->m_pSwapChain->GetBuffer(0, __uuidof(ID3D10Texture2D), reinterpret_cast<void**>(&backbuffer));
				if(FAILED(hr))
					throw SingularityException("Failed to get swap chain buffer.", hr);

				hr = this->m_pDevice->CreateRenderTargetView(backbuffer, 0, &this->m_pCurrRenderTarget);
				if(FAILED(hr))
					throw SingularityException("Failed to create render target.", hr);

				backbuffer->Release();
			}

			void HardwareDevice::_CreateDepthStencil(const unsigned width, const unsigned height)
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

			void HardwareDevice::_ShowWindow()
			{
				::ShowWindow(this->m_hWnd, SW_SHOW);
				::SetForegroundWindow(this->m_hWnd);
				::SetFocus(this->m_hWnd);
			}

			void HardwareDevice::SetResolution(const unsigned width, const unsigned height, const bool fullscreen)
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

			void HardwareDevice::GetResolution(unsigned& width, unsigned& height)
			{
				unsigned index = 1;
				D3D10_VIEWPORT viewport;
				this->m_pDevice->RSGetViewports(&index, &viewport);
				width = viewport.Width;
				height = viewport.Height;
			}

			void HardwareDevice::GetSize(unsigned& x, unsigned& y, unsigned& width, unsigned& height)
			{
				WINDOWINFO info;
				::GetWindowInfo(this->m_hWnd, &info);
				x = info.rcClient.left;
				y = info.rcClient.top;
				width = info.rcClient.right - info.rcClient.left;
				height = info.rcClient.bottom - info.rcClient.top;	
			}
			
			void HardwareDevice::SetSize(const unsigned x, const unsigned y, const unsigned width, const unsigned height)
			{
				RECT displayRect;

				// just in case someone puts in a size greater than the screen size
				displayRect.left = x;
				displayRect.top = y;
				displayRect.right = displayRect.left + width;
				displayRect.bottom = displayRect.top + height;

				::AdjustWindowRectEx(&displayRect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);
				::MoveWindow(this->m_hWnd, displayRect.left, displayRect.top, displayRect.right - displayRect.left, displayRect.bottom - displayRect.top, true);
			}

			void HardwareDevice::SetViewport(const int left, const int top, const unsigned width, const unsigned height, const float minDepth, const float maxDepth)
			{
				if(minDepth < 0 || minDepth > 1)
					throw SingularityException("\"minDepth\" out of range; must be between 0 and 1");
				
				if(maxDepth < 0 || maxDepth > 1)
					throw SingularityException("\"maxDepth\" out of range; must be between 0 and 1");

				D3D10_VIEWPORT viewport;
				viewport.TopLeftX = left;
				viewport.TopLeftY = top;
				viewport.Width = width;
				viewport.Height = height;
				viewport.MinDepth = max(minDepth, 0.01f);
				viewport.MaxDepth = maxDepth;

				this->m_pDevice->RSSetViewports(1, &viewport);
				UINT value = 1;
				this->m_pDevice->RSGetViewports(&value, &viewport);
			}

			void HardwareDevice::GetViewport(int& left, int& top, unsigned& width, unsigned& height, float& minDepth, float& maxDepth)
			{
				D3D10_VIEWPORT viewport;
				UINT value = 1;
				this->m_pDevice->RSGetViewports(&value, &viewport);
				left = viewport.TopLeftX;
				top = viewport.TopLeftY;
				width = viewport.Width;
				height = viewport.Height;
				minDepth = viewport.MinDepth;
				maxDepth = viewport.MaxDepth;
			}
			#pragma endregion
			
			#pragma region Static Methods
			WNDCLASS HardwareDevice::RegisterClass(String classname)
			{
				WNDCLASS wndclass;
				char* buffer;

				buffer = new char[classname.length() + 1];
				memcpy(buffer, classname.c_str(), classname.length() + 1);

				wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
				wndclass.lpfnWndProc = (WNDPROC)(HardwareDevice::_WndProc);
				wndclass.cbClsExtra = 0;
				wndclass.cbWndExtra = 0;
				wndclass.hInstance = ::GetModuleHandle(NULL);
				wndclass.hIcon = ::LoadIcon(NULL, IDI_WINLOGO);
				wndclass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
				wndclass.hbrBackground = NULL;
				wndclass.lpszMenuName = NULL;
				wndclass.lpszClassName = (LPCTSTR)buffer;

				// register window class
				if (!::RegisterClass(&wndclass))
					throw SingularityException("Unable to register window class.");

				return wndclass;
			}

			LRESULT HardwareDevice::_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
			{
				HardwareDevice* device = (HardwareDevice*)::GetWindowLongPtr(hWnd, GWLP_USERDATA);
				switch( uMsg )
				{
					case WM_SYSCOMMAND:
					{
						switch (wParam)
						{
							case SC_SCREENSAVE:
							case SC_MONITORPOWER:
							return 0;
						}
						break;
					}
					case WM_DESTROY:
					case WM_CLOSE:
					{
						Game::Exit();
						return 0;
					}
					case WM_EXITSIZEMOVE:
					{
						WINDOWINFO info;
						::GetWindowInfo(hWnd, &info);
						//device->_ResizeWindow(info.rcClient.left, info.rcClient.top, info.rcClient.right - info.rcClient.left, info.rcClient.bottom - info.rcClient.top);
						::MoveWindow(hWnd, info.rcWindow.left, info.rcWindow.top, info.rcWindow.right - info.rcWindow.left, info.rcWindow.bottom - info.rcWindow.top, true);
					}
				}

				return ::DefWindowProc(hWnd, uMsg, wParam, lParam);;
			}

			HardwareDevice* HardwareDevice::Instantiate()
			{
				return HardwareDevice::Instance;
			}
			#pragma endregion
		}
	}
}