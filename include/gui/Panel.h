// 3/21
// Panel.h
// Groups together GUI elements with a possibly visible border. Replaces FrameWindow, HAH!

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class Panel : public Singularity::Gui::Control
		{
			private:
				#pragma region Variables
				Vector4		m_ClientRegion;
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				Panel(String name) : Control(name) { };
				Panel(String name, NinePatch* texture, Vector2 position, Vector2 size) : Control(name, texture, position, size) { };
				~Panel() { }
				#pragma endregion

				#pragma region Methods
				void AddControl(Control* control);
				void RemoveControl(Control* control);

				void SetPadding(unsigned left, unsigned top, unsigned right, unsigned bottom);
				#pragma endregion
		};
	}
}