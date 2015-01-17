#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{			
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, Checkbox, Singularity::Gui::Control);

		#pragma region Constructors and Deconstructors
		Checkbox::Checkbox(String name, NinePatch* uncheckedTexture, NinePatch* checkedTexture, Vector2 position, Vector2 size, bool isChecked) 
			: Control(name, uncheckedTexture, position, size), m_bIsChecked(isChecked) 
		{ 
			if (this->m_bIsChecked) 
				this->Set_Texture(this->m_pUncheckedTexture);
		};
		#pragma endregion

		#pragma region Overriden Methods
		void Checkbox::OnMouseDown(Vector2 position)
		{
			this->m_bIsChecked = !this->m_bIsChecked;
			this->Set_Texture(this->m_bIsChecked ? this->m_pCheckedTexture : this->m_pUncheckedTexture);
			this->RebuildControl();
		}
		#pragma endregion
	}
}