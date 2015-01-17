#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{				
		#pragma region Methods
		void Panel::AddControl(Control* control)
		{
			this->AddChildControl(control);
		}

		void Panel::RemoveControl(Control* control)
		{
			this->RemoveChildControl(control);
		}

		void Panel::SetPadding(unsigned left, unsigned top, unsigned right, unsigned bottom)
		{
			this->m_ClientRegion = Vector4((float)left, (float)top, (float)right, (float)bottom);
		}
		#pragma endregion
	}
}