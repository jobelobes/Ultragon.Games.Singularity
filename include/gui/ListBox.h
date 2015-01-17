// 3/21
// List.h
// Rename to GuiList PLEASE. Or RadioButton or something. Select ONE of MANY.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class ListBox : public Singularity::Gui::TextControl
		{
			private:
				#pragma region Variables

				//DynamicList<ListBoxElement*>		m_pListElements;
				NinePatch*							m_pOptionTexture;
				NinePatch*							m_pOptionHighlightTexture;
				Color								m_cOptionColor;
				Color								m_cOptionHighlightColor;
				ListPanel*							m_pListPanel;
				bool								m_bMouseDown;

				ListBoxElement* CreateListElement(String text);

				#pragma endregion
			protected:
				
				/*virtual void HandleKeyboardInput();*/
				virtual void OnClick();
				virtual void OnFocusLost();
				virtual void OnMouseDown(Vector2 position);
				virtual void OnMouseUp(Vector2 position);

			public:
				ListBox(String name);
				~ListBox() {};

				DelegateHandler Select;

				void RemoveOption(int optionNum);
				void RemoveOption(String optionName);
				void AddOption(String optionName);
				void AddOption(String optionName, int insertLocation);

				void Clear();
				
				void Set_Extended(bool extended);

				void ItemSelected(ListBoxElement* item);

				void InitializeListBox();

				//int GetOptionIndex(String optionName);

				// gotta make these both reset the elements if changed later
				inline void Set_OptionTexture(NinePatch* value) {this->m_pOptionTexture = value; } ;
				inline void Set_OptionHighlightTexture(NinePatch* value) {this->m_pOptionHighlightTexture = value; };
				inline void Set_OptionFontColor(Color value) {this->m_cOptionColor = value;};
				inline void Set_OptionHighlightColor(Color value) {this->m_cOptionHighlightColor = value;};
		};
	}
}	