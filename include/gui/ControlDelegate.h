#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		typedef void (*ControlCallback)(Control* control);

		class ControlDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				ControlCallback m_pCallback;

			public:
				ControlDelegate(ControlCallback callback);
				virtual void Invoke(Control* control);
		};
	}
}