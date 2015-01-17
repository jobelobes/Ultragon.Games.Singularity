// 3/21
// List.h
// Rename to GuiList PLEASE. Or RadioButton or something. Select ONE of MANY.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class ListBoxElement : public Singularity::Gui::TextControl
		{

			private:
				#pragma region Variables

				ListBox*					m_pListBoxParent;

				NinePatch*					m_pOptionTexture;
				NinePatch*					m_pHighlightTexture;
				Color						m_cOptionColor;
				Color						m_cOptionHighlightColor;

				#pragma endregion

			protected:

				void OnMouseEnter(Vector2 position);
				void OnMouseLeave(Vector2 position);
				void OnMouseDown(Vector2 position);
				
			public:

				ListBoxElement(String text, ListBox* parent) : TextControl("", text), m_pListBoxParent(parent) {};
				~ListBoxElement() {};

				void Set_OptionTexture(NinePatch* value);
				void Set_HighlightTexture(NinePatch* value);
				void Set_OptionColor(Color value);
				void Set_OptionHighlightColor(Color value);
		};
	}
}	