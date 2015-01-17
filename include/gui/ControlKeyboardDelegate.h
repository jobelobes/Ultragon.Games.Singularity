#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		typedef void (*ControlKeyboardCallback)(Control* control, bool isShift, bool isControl, int keyIndex);

		class ControlKeyboardDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				ControlKeyboardCallback m_pCallback;

			public:
				ControlKeyboardDelegate(ControlKeyboardCallback callback);
				virtual void Invoke(Control* control, bool isShift, bool isControl, int keyIndex);
		};
	}
}