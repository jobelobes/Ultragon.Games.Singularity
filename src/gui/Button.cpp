#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{				
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, Button, Singularity::Gui::TextControl);

		#pragma region Event Methods
		void Button::OnClick(Vector2 position)
		{
			for(unsigned i = 0; i < this->Click.Count(); ++i)
				//if(this->Click[i]->GetType().Equals(ControlMouseDelegate::Type))
					((ControlMouseDelegate*)this->Click[i])->Invoke(this, position);
		}

		void Button::OnMouseDown(Vector2 position)
		{
			this->m_bMouseDown = true;
		}

		void Button::OnMouseUp(Vector2 position)
		{
			if(this->m_bMouseDown)
				this->OnClick(position);			

			this->m_bMouseDown = false;
		}
		#pragma endregion
	}
}