// 3/21
// Label.h
// Allows player input through the keyboard.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class TextBox : public Singularity::Gui::TextControl
		{
			protected:
				#pragma region Overriden Methods
				void OnKeyPress(bool shift, bool control, int keyIndex);
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				TextBox(String name, String text = "") : TextControl(name, text) { };
				TextBox(String name, Material* material, Material* fontMaterial, String text = "") : TextControl(name, material, fontMaterial, text) { };
				~TextBox() {};
				#pragma endregion
		};
	}
}