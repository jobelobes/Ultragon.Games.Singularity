// 3/29
// Image.h
// A 2d sprite displayed on the screen that is not interactable.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class Image : public Singularity::Gui::Control
		{
			public:
				#pragma region Constructors and Deconstructors
				Image(String name) : Control(name) { };
				Image(String name, NinePatch* texture, Vector2 position, Vector2 size) : Control(name, texture, position, size) { };
				~Image() { };
				#pragma endregion
		};
	}
}