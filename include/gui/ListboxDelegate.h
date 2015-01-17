#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		typedef void (*ListBoxCallback)(ListBox* control, ListBoxElement* element);

		class ListBoxDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				ListBoxCallback m_pCallback;

			public:
				ListBoxDelegate(ListBoxCallback callback);
				virtual void Invoke(ListBox* control, ListBoxElement* element);
		};
	}
}