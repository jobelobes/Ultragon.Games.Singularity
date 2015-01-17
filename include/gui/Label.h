// 3/21
// Label.h
// Displays text. NOT editable by player.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class Label : public Singularity::Gui::TextControl
		{
			private:
				#pragma region Variables
				#pragma endregion

			protected:


			public:
				#pragma region Constructors and Deconstructors
				Label(String name = "", String text = "") : TextControl(name, text) { };
				~Label();
				#pragma endregion
		};
	}
}