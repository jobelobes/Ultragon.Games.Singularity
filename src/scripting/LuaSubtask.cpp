#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaSubTask, Task);

		#pragma region Methods
		void LuaSubTask::Update(LuaRuntime* runtime, unsigned start, unsigned end, float elapsed)
		{
			this->m_pRuntime = runtime;
			this->m_iStart = start;
			this->m_iEnd = end;
			this->m_fElapsed = elapsed;
		}
		#pragma endregion

		#pragma region Event Methods
		void LuaSubTask::OnExecute()
		{
			/*unsigned index;
			LuaTask* task;

			if((this->m_iStart - this->m_iEnd) <= 0)
				return;

			lock (m_kLock)
			{
				task = (LuaTask*)this->Get_ParentTask();
				for(index = this->m_iStart; index < this->m_iEnd; ++index)
				{
					if(task->m_pBinders[index]->Get_Enabled())
						task->m_pBinders[index]->OnExecute(this->m_pRuntime->Stack, this->m_fElapsed);
				}

				for(index = 0; index < task->m_pDelegates.size(); ++index)
					task->m_pDelegates[index]->InternalInvoke(this->m_pRuntime->Stack);
			}*/
		}
		#pragma endregion
	}
}