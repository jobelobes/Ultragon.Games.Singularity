#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, ControlKeyboardDelegate, Singularity::IDelegate);

		ControlKeyboardDelegate::ControlKeyboardDelegate(ControlKeyboardCallback callback) 
			: m_pCallback(callback) { }

		void ControlKeyboardDelegate::Invoke(Control* control, bool isShift, bool isControl, int keyIndex) 
		{ 
			try
			{
				this->m_pCallback(control, isShift, isControl, keyIndex); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}