// 3/21
// Checkbox.h
// Draws a checked or unchecked and holds a bool.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class Checkbox : public Singularity::Gui::Control
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				bool					m_bIsChecked;
				NinePatch*				m_pCheckedTexture;
				NinePatch*				m_pUncheckedTexture;
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				virtual void OnMouseDown(Vector2 position); // Called when clicked upon.
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				Checkbox(String name, bool isChecked = false) : Control(name), m_bIsChecked(isChecked) {this->m_pCheckedTexture = this->Get_Texture(); this->m_pUncheckedTexture = this->Get_Texture();};
				Checkbox(String name, NinePatch* uncheckedTexture, NinePatch* checkedTexture, Vector2 position, Vector2 size, bool isChecked = false);
				~Checkbox() { };
				#pragma endregion

				#pragma region Properties
				const bool Get_IsChecked() const;
				void Set_IsChecked(const bool value);

				void Set_UncheckedTexture(NinePatch* value);
				void Set_CheckedTexture(NinePatch* value);
				#pragma endregion
		};

		#include "gui\Checkbox.inc"
	}
}