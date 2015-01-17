#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			class ScreenContext
			{
				private:
					#pragma region Static Variables
					static ScreenContext* Instance;
					#pragma endregion

					#pragma region Variables
					HWND		m_hWnd;
					DWORD		m_dwStyles;
					DWORD		m_dwExStyles;
					String		m_pTitle;
					WNDCLASS	m_kWndClass;
					RECT		m_kDisplayRect;		
					#pragma endregion

					#pragma region Constructors and Finalizers
					ScreenContext(String title, const unsigned width, const unsigned height);
					~ScreenContext();
					#pragma endregion

					#pragma region Static Methods
					static LRESULT CALLBACK _WndProc(HWND, UINT, WPARAM, LPARAM);
					#pragma endregion

				public:
					#pragma region Properties
					const HWND Get_Handle() const { return this->m_hWnd; };
					#pragma endregion

					#pragma region Methods
					void Show();
					void Hide();

					void Resize(const unsigned width, const unsigned height);
					void SetTitle(String title);
					#pragma endregion

					#pragma region Static Methods
					static WNDCLASS RegisterClass(String classname);
					#pragma endregion

					friend class Screen;
					friend class RenderTask;
			};
		}
	}
}