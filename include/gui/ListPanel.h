// 3/21
// Panel.h
// Groups together GUI elements with a possibly visible border. Replaces FrameWindow, HAH!

#include "Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class ListPanel : public Singularity::Gui::Control
		{
			protected:
				#pragma region Variables
				
				#pragma endregion

				ListPanel(String name) : Control(name) { };
				ListPanel(String name, NinePatch* texture, Vector2 position, Vector2 size) : Control(name, texture, position, size) { };

				virtual void OnVisible();
				virtual void OnInvisible();

			public:
				#pragma region Constructors and Deconstructors
				
				~ListPanel() {};
				#pragma endregion

				#pragma region Methods
				void AddListElement(ListBoxElement* element);
				void AddListElement(ListBoxElement* element, int position);

				void RemoveListElement(int optionNum);
				void RemoveListElement(String optionName);

				void AddOption(String optionName);
				void RepositionElements();

				void Clear();
				#pragma endregion

			friend ListBox;
		};
	}
}