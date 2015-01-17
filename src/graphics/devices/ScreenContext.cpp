#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		ScreenContext* ScreenContext::Instance = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		ScreenContext::ScreenContext(String title, const unsigned width, const unsigned height) 
			: m_kWndClass(ScreenContext::RegisterClass("SINGULARITY_WINCLS")), m_hWnd(NULL), m_pTitle(title)
		{
			unsigned windowWidth, windowHeight;
			unsigned screenWidth, screenHeight;
			
			screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
			screenHeight = ::GetSystemMetrics(SM_CYSCREEN);

			// just in case someone puts in a size greater than the screen size
			windowWidth = screenWidth < width? screenWidth : width;
			windowHeight = screenHeight < height? screenHeight : height;

			this->m_kDisplayRect.left = (screenWidth - windowWidth) / 2;
			this->m_kDisplayRect.top = (screenHeight - windowHeight) / 2;
			this->m_kDisplayRect.right = this->m_kDisplayRect.left + windowWidth;
			this->m_kDisplayRect.bottom = this->m_kDisplayRect.top + windowHeight;
			this->m_dwExStyles = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	
			this->m_dwStyles = WS_OVERLAPPEDWINDOW;	

			// make any adjustments to the display rect to handle the styles
			::AdjustWindowRectEx(&this->m_kDisplayRect, this->m_dwStyles, FALSE, this->m_dwExStyles);

			// create the actual window from the style def and class
			this->m_hWnd = ::CreateWindowEx(
				this->m_dwExStyles,
				this->m_kWndClass.lpszClassName,
				this->m_pTitle.c_str(),
				this->m_dwStyles | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
				this->m_kDisplayRect.left,
				this->m_kDisplayRect.top,
				this->m_kDisplayRect.right - this->m_kDisplayRect.left,
				this->m_kDisplayRect.bottom - this->m_kDisplayRect.top,
				NULL,
				NULL,
				this->m_kWndClass.hInstance,
				NULL);
			if (!this->m_hWnd)
				throw SingularityException("Unable to create window.");

			// set user data
			::SetWindowLongPtr(this->m_hWnd, GWLP_USERDATA, (long)this);

			ScreenContext::Instance = this;
		}

		ScreenContext::~ScreenContext() 
		{ 
			if (this->m_hWnd && !::DestroyWindow(this->m_hWnd))
				this->m_hWnd = NULL;

			if(this->m_kWndClass.hInstance != NULL)
				::UnregisterClass(this->m_kWndClass.lpszClassName, this->m_kWndClass.hInstance);
		}
		#pragma endregion

		#pragma region Methods
		void ScreenContext::Show()
		{
			::ShowWindow(this->m_hWnd, SW_SHOW);
			::SetForegroundWindow(this->m_hWnd);
			::SetFocus(this->m_hWnd);
		}

		void ScreenContext::Hide()
		{
			::ShowWindow(this->m_hWnd, SW_HIDE);
		}

		void ScreenContext::Resize(const unsigned width, const unsigned height)
		{
			unsigned screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
			unsigned screenHeight = ::GetSystemMetrics(SM_CYSCREEN);

			this->m_kDisplayRect.left = (screenWidth - width) / 2;
			this->m_kDisplayRect.top = (screenHeight - height) / 2;
			this->m_kDisplayRect.right = this->m_kDisplayRect.left + width;
			this->m_kDisplayRect.bottom = this->m_kDisplayRect.top + height;

			::MoveWindow(this->m_hWnd, this->m_kDisplayRect.left, this->m_kDisplayRect.top, width, height, true);
		}

		void ScreenContext::SetTitle(String title)
		{
			this->m_pTitle = title;
			::SetWindowText(this->m_hWnd, (LPCTSTR)this->m_pTitle.c_str());
		}
		#pragma endregion

		#pragma region Static Methods
		WNDCLASS ScreenContext::RegisterClass(String classname)
		{
			WNDCLASS wndclass;
			char* buffer;

			buffer = new char[classname.length() + 1];
			memcpy(buffer, classname.c_str(), classname.length() + 1);

			wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
			wndclass.lpfnWndProc = (WNDPROC)(ScreenContext::_WndProc);
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

		LRESULT ScreenContext::_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			ScreenContext* window = (ScreenContext*)::GetWindowLongPtr(hWnd, GWLP_USERDATA);
			switch( uMsg )
			{
				case WM_ERASEBKGND:
					break;
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
					::PostQuitMessage(0);
					ExitProcess(0);
					return 0;
				}
				case WM_EXITSIZEMOVE:
				{
					WINDOWINFO info;
					::GetWindowInfo(hWnd, &info);
					memcpy(&window->m_kDisplayRect, &info.rcClient, sizeof(RECT));
					window->Resize(info.rcClient.right - info.rcClient.left, info.rcClient.bottom - info.rcClient.top);
				}
			}

			return ::DefWindowProc(hWnd, uMsg, wParam, lParam);;
		}
		#pragma endregion
	}
}