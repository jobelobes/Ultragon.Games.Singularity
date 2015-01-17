#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			class HardwareDevice
			{
				private:
					#pragma region Static Variables
					static HardwareDevice* Instance;
					#pragma endregion

					#pragma region Variables
					HWND						m_hWnd;
					WNDCLASS					m_kWndClass;

					ID3D10Device*				m_pDevice;
					IDXGISwapChain*				m_pSwapChain;
					ID3D10RenderTargetView*		m_pCurrRenderTarget;
					ID3D10DepthStencilView*		m_pDepthStencilView;
					ID3D10Texture2D*			m_pDepthStencilBuffer;
					#pragma endregion

					#pragma region Methods
					void _CreateWindow(String title, const unsigned width, const unsigned height);
					void _CreateSwapBuffer(const HWND handle, const unsigned width, const unsigned height);
					void _CreateBackbuffer();
					void _CreateDepthStencil(const unsigned width, const unsigned height);
					void _ShowWindow();
					#pragma endregion

					#pragma region Constructors and Finalizers
					HardwareDevice(const unsigned width = 640, const unsigned height = 480);
					~HardwareDevice();
					#pragma endregion

					#pragma region Static Methods
					static WNDCLASS RegisterClass(String classname);
					static LRESULT CALLBACK _WndProc(HWND, UINT, WPARAM, LPARAM);
					#pragma endregion

				public:
					#pragma region Methods
					void GetResolution(unsigned& width, unsigned& height);
					void SetResolution(const unsigned width, const unsigned height, const bool fullscreen);

					void GetSize(unsigned& x, unsigned& y, unsigned& width, unsigned& height);
					void SetSize(const unsigned x, const unsigned y, const unsigned width, const unsigned height);

					void GetViewport(int& left, int& top, unsigned& width, unsigned& height, float& minDepth, float& maxDepth);
					void SetViewport(const int left, const int top, const unsigned width, const unsigned height, const float minDepth = 0.0f, const float maxDepth = 1.0f);
					#pragma endregion

					#pragma region Static Methods
					static HardwareDevice* Instantiate();
					#pragma endregion

					friend class GraphicsDevice;
					friend class Screen;

					friend class Texture2D;
					friend class RenderTexture;

					friend class InternalMaterial;
					friend class InternalVertexBuffer;
					friend class InternalIndexBuffer;

					friend class DrawingContext;
					friend class DeferredDrawingContext;

					friend class RenderTask;
			};
		}
	}
}