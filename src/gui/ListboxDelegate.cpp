#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, ListBoxDelegate, Singularity::IDelegate);

		ListBoxDelegate::ListBoxDelegate(ListBoxCallback callback) 
			: m_pCallback(callback) { }

		void ListBoxDelegate::Invoke(ListBox* control, ListBoxElement* element) 
		{ 
			try
			{
				this->m_pCallback(control, element); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}