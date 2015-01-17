#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, ControlDelegate, Singularity::IDelegate);

		ControlDelegate::ControlDelegate(ControlCallback callback) 
			: m_pCallback(callback) { }

		void ControlDelegate::Invoke(Control* control) 
		{ 
			try
			{
				this->m_pCallback(control); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}