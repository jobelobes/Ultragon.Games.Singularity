#include "gui\Singularity.Gui.h"

using namespace Singularity::Inputs;

namespace Singularity
{
	namespace Gui
	{				
				
		ListBox::ListBox(String name) 
			: TextControl(name, ""), m_pOptionTexture(NULL), m_pOptionHighlightTexture(NULL), m_cOptionColor(Color(1,1,1,1)), m_cOptionHighlightColor(Color(1,1,1,1)), m_bMouseDown(false)
		{
			Set_OptionTexture(this->Get_Texture());
			m_pListPanel = new ListPanel(this->Get_Name() + "_ListElementPanel");
			this->AddChildControl(m_pListPanel);
			m_pListPanel->Set_Position(Vector2(0, this->Get_Size().y));
			m_pListPanel->Set_Size(Vector2(0, 0));

			this->m_pOptionTexture = this->Get_Texture();
			this->m_pOptionHighlightTexture = this->Get_Texture();
			
			// just to make sure we're actually never drawing the panel itself
			m_pListPanel->Set_Texture(new NinePatch(Texture2D::LoadTextureFromFile("..\\..\\..\\Assets\\Textures\\Gui\\Transparent.png"), Vector4(0,0,0,0)));
			m_pListPanel->Set_Visible(false);

		}

		void ListBox::Clear()
		{
			this->m_pListPanel->Clear();
		}

		// becomes un-extended so the user doesn't see the removal /
		void ListBox::RemoveOption(int optionNum)
		{

			this->m_pListPanel->RemoveListElement(optionNum);


			this->RebuildControl();
			m_bNeedToRecalc = true;

			// todo: we still need to update everything's position and all that jazz
		}

		void ListBox::RemoveOption(String optionName)
		{
			this->m_pListPanel->RemoveListElement(optionName);

			this->RebuildControl();
			m_bNeedToRecalc = true;

		}

		void ListBox::AddOption(String optionName)
		{

			m_pListPanel->Set_Position(Vector2(0, this->Get_Size().y));
			
			ListBoxElement* element = NULL;
			m_pListPanel->AddOption(optionName);
			//m_pListPanel->AddListElement((CreateListElement(optionName)));  
			m_pListPanel->RepositionElements();
			this->RebuildControl();
			m_bNeedToRecalc = true;

			if (m_pText == "")
			{				
				this->Set_Text(optionName);
			}
		}

		void ListBox::AddOption(String optionName, int insertLocation)
		{

			m_pListPanel->AddListElement((CreateListElement(optionName)), insertLocation);
			this->RebuildControl();
			m_bNeedToRecalc = true;
		
			if (m_pText == "")
			{
				this->Set_Text(optionName);
			}

			m_pListPanel->RepositionElements();
			this->RebuildControl();		
		}

		void ListBox::OnMouseDown(Vector2 position)
		{
			if (this->Get_Visible())
				this->m_bMouseDown = true;
		}

		void ListBox::OnMouseUp(Vector2 position)
		{
			if(this->m_bMouseDown)
				this->OnClick();			

			this->m_bMouseDown = false;
		}

		void ListBox::OnClick()
		{
			m_pListPanel->Set_Visible(!m_pListPanel->Get_Visible());
			m_pListPanel->RebuildControl(true);
		}

		void ListBox::OnFocusLost()
		{
			// we're never getting here... :/
			this->m_bMouseDown = false;
			m_pListPanel->Set_Visible(false);
			this->RebuildControl();
		}

		void ListBox::InitializeListBox()
		{
			for (int i = 0; i < SINGULARITY_GUI_MAX_LISTBOX_ELEMENT_COUNT; i++)
			{
				m_pListPanel->AddListElement((CreateListElement("")));
			}
		}

		ListBoxElement* ListBox::CreateListElement(String text)
		{
			ListBoxElement* retval = new ListBoxElement(text, this);
			
			retval->Set_OptionTexture(m_pOptionTexture);
			retval->Set_HighlightTexture(m_pOptionHighlightTexture);
			
			retval->Set_Size(this->Get_Size());
			retval->Set_Position(Vector2(0, m_pListPanel->Get_NumberOfChildren() * this->Get_Size().y));

			retval->Set_Font(this->Get_Font());
			retval->Set_OptionColor(m_cOptionColor);
			retval->Set_OptionHighlightColor(m_cOptionHighlightColor);
			
			return retval;
		}

		void ListBox::Set_Extended(bool extended)
		{
			m_pListPanel->Set_Visible(extended);
			m_pListPanel->RebuildControl(true);
		}

		void ListBox::ItemSelected(ListBoxElement* item)
		{
			this->Set_Text(item->Get_Text());
			this->Set_Extended(false);

			for(unsigned i = 0; i < this->Select.Count(); ++i)
				((ListBoxDelegate*)this->Select[i])->Invoke(this, item);
		}

	}
}