#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, ControlMouseDelegate, Singularity::IDelegate);

		ControlMouseDelegate::ControlMouseDelegate(ControlMouseCallback callback) 
			: m_pCallback(callback) { }

		void ControlMouseDelegate::Invoke(Control* control, Vector2 position) 
		{ 
			try
			{
				this->m_pCallback(control, position); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}