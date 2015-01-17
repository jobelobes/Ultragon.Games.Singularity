#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{				
		#pragma region Methods

		void ListPanel::AddListElement(ListBoxElement* element)
		{
			element->Set_Visible(this->Get_Visible());
			this->AddChildControl(element);
			if (element->Get_Text() == "")
				element->Set_Enabled(false);
			//this->Set_Size(Vector2(this->Get_Size().x + element->Get_Size().x, this->Get_Size().y + element->Get_Size().y));
		}

		void ListPanel::AddListElement(ListBoxElement* element, int position)
		{
			if (position > this->m_pChildControls.size())
			{
				this->AddListElement(element); // the user made a mistake, so just add one to the end.
				return;
			}

			DynamicList<Control*>::iterator iter = this->m_pChildControls.begin();
			while (position > 0)
			{
				iter++;
				position--; // gotta make this this loop works works works!
			}

			element->Set_Enabled(false);

			m_pChildControls.insert(iter, element);
		}

		void ListPanel::RemoveListElement(int optionNum)
		{
			this->m_pChildControls[optionNum] = this->m_pChildControls[m_pChildControls.size() - 1];
			this->m_pChildControls.pop_back(); // all good?
		}

		void ListPanel::RemoveListElement(String optionName)
		{
			for(unsigned i = 0; i < m_pChildControls.size(); i++)
			{
				if (((ListBoxElement*)m_pChildControls[i])->Get_Text() == optionName)
				{
					RemoveListElement(i);
					return;
				}
			}
		}

		void ListPanel::OnVisible()
		{
			ListBoxElement* element;
			for (unsigned index = 0; index < this->m_pChildControls.size(); ++index)
			{
				element = (ListBoxElement*)this->m_pChildControls[index];
				element->Set_Visible(true);
				if (element->Get_Text() == "")
				{				
					element->Set_Enabled(false);
				}
			
			}
		}

		void ListPanel::OnInvisible()
		{
			for (unsigned index = 0; index < this->m_pChildControls.size(); ++index)
				this->m_pChildControls[index]->Set_Visible(false);
		}

		void ListPanel::Clear()
		{
			ListBoxElement* element = NULL;
			for (unsigned i = 0; i < m_pChildControls.size(); i++)
			{
				element = (ListBoxElement*)m_pChildControls[i];
				element->Set_Text("");
				element->Set_Enabled(false);
			}
		}

		void ListPanel::RepositionElements()
		{
			int activeElements = 0;
			for (unsigned i = 0; i < m_pChildControls.size(); i++)
			{
				if (m_pChildControls[i]->Get_Enabled())
				{
					m_pChildControls[i]->Set_Position(Vector2(0, activeElements * m_pChildControls[i]->Get_Size().y));
					activeElements++;
				}
			}
			
		}

		void ListPanel::AddOption(String optionName)
		{
			ListBoxElement* element;
			for (unsigned i = 0; i < m_pChildControls.size(); i++)
			{
				element = (ListBoxElement*)m_pChildControls[i];
				if (!element->Get_Enabled())
				{				
					element->Set_Text(optionName);
					element->Set_Enabled(true);
					return;
				}
			}
		}

		#pragma endregion
	}
}