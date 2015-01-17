#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{				
		void ListBoxElement::OnMouseEnter(Vector2 position)
		{
			// this->ListPanel->ListBox
			this->Set_Texture(m_pHighlightTexture);
			this->Set_FontColor(m_cOptionHighlightColor);
		}

		void ListBoxElement::OnMouseDown(Vector2 position)
		{
			//this->m_pListBoxParent->Set_Text(this->m_pText);
			//this->m_pListBoxParent->Set_Extended(false);
			if (this->Get_Visible() && this->Get_Enabled())
				this->m_pListBoxParent->ItemSelected(this);
		}

		void ListBoxElement::OnMouseLeave(Vector2 position)
		{
			this->Set_Texture(m_pOptionTexture);
			this->Set_Color(m_cOptionColor);
		}

		void ListBoxElement::Set_OptionTexture(NinePatch* value) 
		{ 
			this->m_pOptionTexture = value; 
			this->Set_Texture(value); 
		}

		void ListBoxElement::Set_HighlightTexture(NinePatch* value) 
		{ 
			this->m_pHighlightTexture = value; 
		}

		void ListBoxElement::Set_OptionColor(Color value) 
		{ 
			this->m_cOptionColor = value; 
			this->Set_FontColor(value); 
		}
		void ListBoxElement::Set_OptionHighlightColor(Color value) 
		{ 
			this->m_cOptionHighlightColor = value; 
		}

	}
}