#include "gui\Singularity.Gui.h"

using namespace Singularity::Inputs;

namespace Singularity
{
	namespace Gui
	{
		#pragma region Methods
		void Window::SetFocus()
		{
			this->Get_GuiParent()->ReorderWindows(this);
			Control::SetFocus();
		}
		#pragma endregion

		#pragma region Overriden Methods
		bool Window::HandleMouseInput(MouseState& state, bool handled)
		{
			if(Control::HandleMouseInput(state, handled))
			{
				if(state.GetMouseButton(0))
					this->Get_GuiParent()->ReorderWindows(this);

				return true;
			}
			return true;
		}
		#pragma endregion

		#pragma region Event Methods
		void Window::OnMouseDown(Vector2 position)
		{
			if(position.x < (this->Get_Position().x + this->Get_Size().x * 0.9) && position.y < (this->Get_Position().y + this->Get_Size().y * 0.2))
			{
				this->m_bDragging = true & this->m_bDraggable;
				this->m_kPrevPosition = position;
			}
		}

		void Window::OnMouseClick(Vector2 position)
		{
			this->m_bDragging = false;
		}

		void Window::OnMouseUp(Vector2 position)
		{
			this->m_bDragging = false;
		}

		void Window::OnMouseMove(Vector2 position)
		{
			if(!this->m_bDragging)
				return;

			Vector2 currPos = this->Get_Position();
			currPos.x += position.x - this->m_kPrevPosition.x;
			currPos.y += position.y - this->m_kPrevPosition.y;
			this->Set_Position(currPos);
			this->m_kPrevPosition = position;
		}
		#pragma endregion
	}
}