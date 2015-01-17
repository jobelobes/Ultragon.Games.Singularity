#include "core\Singularity.Core.h"

using namespace Singularity::Tasks;

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, Extension, Task);

		#pragma region Overriden Methods
		void Extension::OnExecute()
		{
			if(!this->m_bInitialized)
			{
				this->m_bInitialized = true;
				this->OnInitialize();
			}
		}
		#pragma endregion
	}
}