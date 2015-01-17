#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		/*ScreenContext* Screen::g_pScreenContext = NULL;
		HardwareContext* Screen::g_pHardwareContext = NULL;*/
		#pragma endregion

		#pragma region Static Methods
		void Screen::SetResolution(const unsigned width, const unsigned height, const bool fullscreen)
		{
			unsigned x, y, w, h;
			HardwareDevice::Instance->SetResolution(width, height, fullscreen);

			if(!fullscreen)
			{
				HardwareDevice::Instance->GetSize(x, y, w, h);
				HardwareDevice::Instance->SetSize(x, y, width, height);
			}
		}

		void Screen::GetResolution(unsigned& width, unsigned& height)
		{
			HardwareDevice::Instance->GetResolution(width, height);
		}

		void Screen::SetSize(const unsigned x, const unsigned y, const unsigned width, const unsigned height)
		{
			HardwareDevice::Instance->SetSize(x, y, width, height);
		}

		void Screen::GetSize(unsigned& x, unsigned& y, unsigned& width, unsigned& height)
		{
			HardwareDevice::Instance->GetSize(x, y, width, height);
		}

		void Screen::SetTitle(String title)
		{
			::SetWindowText(HardwareDevice::Instance->m_hWnd, (LPCTSTR)title.c_str());
		}
		#pragma endregion
	}
}