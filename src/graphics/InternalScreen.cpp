#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		InternalScreen* InternalScreen::g_pInstance = NULL;
		#pragma endregion

		#pragma region Static Methods
		LRESULT InternalScreen::_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			InternalScreen* screen = (InternalScreen*)::GetWindowLongPtr(hWnd, GWLP_USERDATA);
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
				case WM_CLOSE:
				{
					::PostQuitMessage(0);
					return 0;
				}
				case WM_EXITSIZEMOVE:
				{
					WINDOWINFO info;
					::GetWindowInfo(hWnd, &info);
					memcpy(&screen->m_kDisplayRect, &info.rcClient, sizeof(RECT));
					screen->Resize(info.rcClient.right - info.rcClient.left, info.rcClient.bottom - info.rcClient.top);
				}
			}
			return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		InternalScreen::InternalScreen()
		{
			unsigned screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
			unsigned screenHeight = ::GetSystemMetrics(SM_CYSCREEN);

			this->m_hInst = 0;
			this->m_hWnd = 0;
			this->m_pTitle = "Singularity Engine InternalScreen";
			this->m_kDisplayRect.left = screenWidth / 2 - 320;
			this->m_kDisplayRect.top = screenHeight / 2 - 240;
			this->m_kDisplayRect.right = this->m_kDisplayRect.left + 640;
			this->m_kDisplayRect.bottom = this->m_kDisplayRect.top + 480;
		}

		InternalScreen::~InternalScreen() { }
		#pragma endregion

		#pragma region Methods
		void InternalScreen::CreateScreen()
		{
			this->m_hInst = ::GetModuleHandle(NULL);

			// create and initialize the window class
			this->m_sWndClass.style				= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
			this->m_sWndClass.lpfnWndProc		= (WNDPROC)(InternalScreen::_WndProc);
			this->m_sWndClass.cbClsExtra		= 0;
			this->m_sWndClass.cbWndExtra		= 0;
			this->m_sWndClass.hInstance			= this->m_hInst;
			this->m_sWndClass.hIcon				= ::LoadIcon(NULL, IDI_WINLOGO);
			this->m_sWndClass.hCursor			= ::LoadCursor(NULL, IDC_ARROW);
			this->m_sWndClass.hbrBackground		= NULL;
			this->m_sWndClass.lpszMenuName		= NULL;
			this->m_sWndClass.lpszClassName		= (LPCTSTR)"Singularity Engine";
			if (!::RegisterClass(&this->m_sWndClass))
				throw SingularityException("Unable to register Window class.");

			// change the styles for fullInternalScreen or windowed mode
			this->m_dwExStyles = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	
			this->m_dwStyles = WS_OVERLAPPEDWINDOW;	

			::AdjustWindowRectEx(&this->m_kDisplayRect, this->m_dwStyles, FALSE, this->m_dwExStyles);

			// create the actual window from the style def and class
			this->m_hWnd = ::CreateWindowEx(
				this->m_dwExStyles,
				this->m_sWndClass.lpszClassName,
				this->m_pTitle.c_str(),
				this->m_dwStyles | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
				this->m_kDisplayRect.left,
				this->m_kDisplayRect.top,
				this->m_kDisplayRect.right - this->m_kDisplayRect.left,
				this->m_kDisplayRect.bottom - this->m_kDisplayRect.top,
				NULL,
				NULL,
				this->m_hInst,
				NULL);
			if (!this->m_hWnd)
				throw SingularityException("Unable to create window.");

			// set user data
			::SetWindowLongPtr(this->m_hWnd, GWLP_USERDATA, (long)this);

			// get the device context
			if (!(this->m_hDeviceContext = ::GetDC(this->m_hWnd)))
				throw SingularityException("Unable to get device context for window.");

			// bring all the window stuff up to the front
			::ShowWindow(this->m_hWnd, SW_SHOW);
			::SetForegroundWindow(this->m_hWnd);
			::SetFocus(this->m_hWnd);

			//GraphicsDevice::Current->_CreateDevice(this->m_hWnd, this->m_kDisplayRect);
		}

		void InternalScreen::DestroyScreen()
		{
			// release the contexts
			if (this->m_hDeviceContext && !ReleaseDC(this->m_hWnd, this->m_hDeviceContext))	
				this->m_hDeviceContext = NULL;

			if (this->m_hWnd && !::DestroyWindow(this->m_hWnd))
				this->m_hWnd = NULL;

			if (!::UnregisterClass(this->m_sWndClass.lpszClassName, this->m_hInst))
				this->m_hInst = NULL;
		}
		#pragma endregion

		#pragma region Methods
		void InternalScreen::Resize(const unsigned width, const unsigned height)
		{
			unsigned screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
			unsigned screenHeight = ::GetSystemMetrics(SM_CYSCREEN);

			this->m_kDisplayRect.left = (screenWidth - width) / 2;
			this->m_kDisplayRect.top = (screenHeight - height) / 2;
			this->m_kDisplayRect.right = this->m_kDisplayRect.left + width;
			this->m_kDisplayRect.bottom = this->m_kDisplayRect.top + height;
			::AdjustWindowRectEx(&this->m_kDisplayRect, this->m_dwStyles, FALSE, this->m_dwExStyles);
		}

		void InternalScreen::SetTitle(String title)
		{
			this->m_pTitle = title;
			::SetWindowText(this->m_hWnd, (LPCTSTR)this->m_pTitle.c_str());
		}
		#pragma endregion
	}
}