#include "common\Singularity.Common.h"

namespace Singularity
{
	namespace Threading
	{
		class CriticalSection
		{
			private:
				#pragma region Variables
				CRITICAL_SECTION m_sCriticalSection;
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				CriticalSection() { ::InitializeCriticalSection(&this->m_sCriticalSection); };

				~CriticalSection() { ::DeleteCriticalSection(&this->m_sCriticalSection); };
				#pragma endregion

				#pragma region Methods
				inline void Aquire() { ::EnterCriticalSection(&this->m_sCriticalSection); };
				inline void Release() { ::LeaveCriticalSection(&this->m_sCriticalSection); };
				#pragma endregion
		};
	}
}