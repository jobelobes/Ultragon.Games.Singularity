#include "common\Singularity.Common.h"

namespace Singularity
{
	namespace Threading
	{
		class _AutoLock
		{
			private:
				#pragma region Variables
				bool				m_bRunning;
				CriticalSection&	m_pCritSection;
				#pragma endregion

				#pragma region Constructors and Finalizers
				#pragma warning(disable: 4413)
				_AutoLock(const _AutoLock& lock) : m_pCritSection(CriticalSection()) {}
				#pragma warning(default: 4413)
				#pragma endregion

				#pragma region Operator Methods
				_AutoLock& operator=(const _AutoLock &lock){return *this;}
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				_AutoLock(CriticalSection& critSection) : m_pCritSection(critSection), m_bRunning(true) { this->m_pCritSection.Aquire(); };

				~_AutoLock() { m_pCritSection.Release(); };
				#pragma endregion

				#pragma region Operator Methods
				void _Release() { this->m_bRunning = false; }
				#pragma endregion	

				#pragma region Operator Methods
				operator bool () const { return this->m_bRunning; };
				#pragma endregion	
		};
	}
}