// 3/21
// Button.h
// Does something when pressed.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class Button : public Singularity::Gui::TextControl
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				Vector4					m_sTextOffset;
				bool					m_bMouseDown;
				#pragma endregion
				
			protected:
				#pragma region Event Methods
				virtual void OnClick(Vector2 position);
				virtual void OnMouseDown(Vector2 position);
				virtual void OnMouseUp(Vector2 position);
				#pragma endregion

			public:
				#pragma region Events
				DelegateHandler Click;
				#pragma endregion

				#pragma region Constructors and Deconstructors
				Button(String name, String text) : TextControl(name, text), m_bMouseDown(false) { };
				~Button() { };
				#pragma endregion
		};
	}
}