// 3/21
// InputControl.h
// Can tell if it's pressed or a mouse is on it.

#include "Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class ClickableControl : public Singularity::Gui::Control
		{
			private:
				#pragma region Variables
				bool			m_bIsPressed;
				bool			m_bIsMouseOver;
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnPress(Vector2 position); // Called when clicked upon.
				virtual void OnRelease() {} // Called when the mouse is released.
				virtual void HandleKeyboardInput() {} // Called when focused.
				#pragma endregion

			public:

				#pragma region Constructors and Deconstructors
				ClickableControl(String name);
				ClickableControl(String name, NinePatch* texture, Vector2 position, Vector2 size) : Control(name, texture, position, size), m_pClickCallback(NULL), m_pMouseoverCallback(NULL), m_bIsMouseOver(false), m_bHasFocus(false) {}
				ClickableControl(String name, Material* material) : Control(name, material), m_pClickCallback(NULL), m_pMouseoverCallback(NULL), m_bIsMouseOver(false), m_bHasFocus(false) {}
				~ClickableControl();
				#pragma endregion

				friend class GuiExtension;
		};

		#include "gui\InputControl.inc"
	}
}