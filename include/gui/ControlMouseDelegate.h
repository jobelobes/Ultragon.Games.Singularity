#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		typedef void (*ControlMouseCallback)(Control* control, Vector2 position);

		class ControlMouseDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				ControlMouseCallback m_pCallback;

			public:
				ControlMouseDelegate(ControlMouseCallback callback);
				virtual void Invoke(Control* control, Vector2 position);
		};
	}
}