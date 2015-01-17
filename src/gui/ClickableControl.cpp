#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{								
		#pragma region Constructors and Deconstructors
		InputControl::InputControl(String name) : Control(name), m_pClickCallback(NULL), m_pMouseoverCallback(NULL), m_bIsMouseOver(false), m_bHasFocus(false)
		{

		}

		InputControl::~InputControl()
		{

		}

		#pragma endregion

		#pragma region Properties

		bool InputControl::Get_IsPressed()
		{
			return m_bIsPressed;
		}

		bool InputControl::Get_IsMouseOver()
		{
			return m_bIsMouseOver;
		}

		void InputControl::OnPress(Vector2 position)
		{
			if(this->m_pClickCallback != NULL)
				this->m_pClickCallback(this);
		}

		void InputControl::OnMouseOver(Vector2 position)
		{
			if (!this->m_bIsMouseOver)
			{
				if(this->m_pMouseoverCallback != NULL)
				{
					m_bIsMouseOver = true;
					this->m_pMouseoverCallback(this);
				}
			}
		}

		void InputControl::OnMouseOff()
		{
			m_bIsMouseOver = false;
			this->m_pMouseoverCallback(this);
		}

		#pragma endregion
	}
}