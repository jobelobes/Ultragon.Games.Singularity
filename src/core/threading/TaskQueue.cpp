#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Threading
	{
		#pragma region Constructors and Finalizers
		TaskQueue::TaskQueue(int capacity)
			: m_iCount(0), m_iCapacity(capacity)
		{
			this->m_pNodes = (Task**)calloc(this->m_iCapacity, sizeof(Task*));

			::InitializeSRWLock(&this->m_sSRWLock);
		}

		TaskQueue::~TaskQueue()
		{
			if(this->m_pNodes != NULL)
				free(this->m_pNodes);
		}
		#pragma endregion

		#pragma region Methods
		double TaskQueue::_calculateWeight(Task* task, unsigned __int64& now)
		{
			float lastExecution;
			double deadline, affinity, processTime;

			deadline =  (task->m_iFrequency > 0) ? task->m_iLastExecution - task->m_iFrequency : 1.0;
			affinity = TASKPOOL_AFFINITY_LOWEST / (double)task->Get_Affinity();
			processTime = (task->Get_ProcessTime() > 0) ? 1.0 / (double)task->Get_ProcessTime() : 0.0;

			return deadline * 5.0;// + affinity * 2.0 + processTime * 1.0;
		}

		Task* TaskQueue::Pop()
		{
			Task *s_task;
			double weight, s_taskWeight;
			unsigned index, s_taskIndex;
			unsigned __int64 now;

			::AcquireSRWLockExclusive(&this->m_sSRWLock);
			::QueryPerformanceCounter((LARGE_INTEGER*)&now);
			{
				s_taskWeight = 0.0f;
				s_task = NULL;

				for(index = 0; index < this->m_iCount; index++)
				{
					// replace if the current task isn't actually ready
					if(this->m_pNodes[index]->m_eState != TaskState::Ready)
						continue;

					weight = this->_calculateWeight(this->m_pNodes[index], now);
					if(weight > s_taskWeight)
					{
						s_taskIndex = index;
						s_task = this->m_pNodes[index];
						s_taskWeight = weight;
					}
				}

				if(s_task != NULL)
				{
					s_task->m_eState = TaskState::PendingExecute;
					::InterlockedDecrement((LONG*)&this->m_iCount);
					this->m_pNodes[s_taskIndex] = (this->m_iCount > 0) ? this->m_pNodes[this->m_iCount] : NULL;
				}
			}
			::ReleaseSRWLockExclusive(&this->m_sSRWLock);

			return s_task;
		}

		void TaskQueue::Push(Task* task)
		{
			if(task == NULL)
				throw SingularityException("\"task\" is a NULL reference and cannot be removed.");

			if(this->m_iCount == this->m_iCapacity)
				throw SingularityException("The queue is currently filled to capacity");
	
			::AcquireSRWLockExclusive(&this->m_sSRWLock);
			this->m_pNodes[this->m_iCount] = task;
			::InterlockedIncrement((LONG*)&this->m_iCount);
			::ReleaseSRWLockExclusive(&this->m_sSRWLock);
		}
		#pragma endregion
	}
}