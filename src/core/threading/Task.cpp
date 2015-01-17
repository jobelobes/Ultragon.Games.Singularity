#include "core\Singularity.Core.h"

using namespace Singularity;
using namespace Singularity::Threading;

namespace Singularity
{
	namespace Threading
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Tasks, Task, Object);

		#pragma region Constructors and Finalizers
		Task::Task(String identifier)
			: m_pThread(NULL), 
			m_pParent(NULL),
			m_iRefCount(0), 
			m_iAffinity(TASKPOOL_AFFINITY_NORMAL),
			m_eState(TaskState::Ready), 
			m_iFrequency(0), 
			m_iActualFrequency(0),
			m_iProcessTime(0), 
			m_iLastExecution(0),
			m_pIdentifier(identifier)
		{
			::InitializeSRWLock(&this->m_sSRWLock);
			::QueryPerformanceCounter((LARGE_INTEGER*)&this->m_iLastExecution);
		}
		#pragma endregion

		#pragma region Methods
		// spawns a task using the current task as the parent
		//	note: what this means is that the parent will not complete until all its children complete
		void Task::Spawn(Task* task)
		{
			// set the tasks parent to the current task
			task->m_pParent = this;

			// increment the reference count
			++this->m_iRefCount;

			// push the task onto the queue
			TaskScheduler::Push(task);
		}

		void Task::_InternalExecute(WorkerThread* workerthread)
		{
			__int64 timestamp;
			float elapsedTime = 0.0f;

			::QueryPerformanceCounter((LARGE_INTEGER*)&timestamp);

			this->m_pThread = workerthread;
			this->m_iRefCount = 1;
			this->m_eState = TaskState::Executing;
			this->m_iActualFrequency = timestamp - this->m_iLastExecution;
			this->m_iLastExecution = timestamp;

			this->OnExecute();

			::QueryPerformanceCounter((LARGE_INTEGER*)&timestamp);
			this->m_iProcessTime += (timestamp - this->m_iLastExecution - this->m_iProcessTime) / 100;

			this->_DecrementRef();
		}

		void Task::_DecrementRef()
		{
			if(InterlockedDecrement((LONG*)&this->m_iRefCount) <= 0)
			{
				if(this->m_pParent)
					this->m_pParent->_DecrementRef();

				this->OnComplete();

				if(this->m_eState == TaskState::PendingRecycle)
				{
					this->m_pParent = NULL;
					this->m_pThread->PushTask(this);
				}
			}
		}
		#pragma endregion
	}
}