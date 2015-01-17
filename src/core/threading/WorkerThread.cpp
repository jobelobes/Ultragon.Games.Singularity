#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Threading
	{
		#pragma region Constructors and Finalizers
		WorkerThread::WorkerThread(const unsigned capacity)
			: m_iId(0), m_hThread(NULL), m_iCapacity(capacity), m_iStart(0), m_iCount(0), m_pTasks(NULL)
		{
			this->m_pTasks = (Task**)malloc(sizeof(Task*) * this->m_iCapacity);

			this->m_iState = TASKPOOL_STATE_INITIALIZED;

			::InitializeSRWLock(&this->m_kLock);
		}

		WorkerThread::~WorkerThread() { }
		#pragma endregion

		#pragma region Properties
		const double WorkerThread::Get_Utilization()
		{
			unsigned index, curr;
			double utilization = 0;

			::AcquireSRWLockShared(&this->m_kLock);
			{
				for(index = 1; index < this->m_iCount; ++index)
				{
					curr = (this->m_iStart + index) % this->m_iCapacity;
					if(this->m_pTasks[curr]->m_iFrequency > 0)
						utilization += (double)this->m_pTasks[curr]->m_iProcessTime / (double)this->m_pTasks[curr]->m_iFrequency;
				}
			}
			::ReleaseSRWLockShared(&this->m_kLock);

			return utilization;
		}
		#pragma endregion

		#pragma region Methods
		bool WorkerThread::Start(TaskScheduler* scheduler)
		{
			this->m_pTaskScheduler = scheduler;
			this->m_hThread = ::CreateThread(NULL, SINGULARITY_THREADING_STACKSIZE, WorkerThread::DoWork, this, 0, &this->m_iId);
			this->m_iState = TASKPOOL_STATE_STARTED;
			 
			assert(this->m_hThread);

			return m_hThread != NULL;
		}

		Task* WorkerThread::_PopTask()
		{
			Task *currTask, *task;
			__int64 now, prevTTL, currTTL;
			int index, taskIndex, currIndex;

			if(this->m_iCount == 0)
				return NULL;

			::AcquireSRWLockExclusive(&this->m_kLock);
			{
				::QueryPerformanceCounter((LARGE_INTEGER*)&now);

				task = NULL;
				taskIndex = -1;
				prevTTL = _I64_MAX;

				for(index = 0; index < this->m_iCount; ++index)
				{
					currIndex = (this->m_iStart + index) % this->m_iCapacity;
					currTask = this->m_pTasks[currIndex];
					if(currTask->m_iFrequency > 0)
					{
						currTTL = currTask->m_iFrequency - (now - currTask->m_iLastExecution);
						if(currTTL < prevTTL && currTTL < currTask->m_iProcessTime)
						{
							taskIndex = currIndex;
							prevTTL = currTTL;
						}
					}
					else if(currTask->m_iProcessTime < prevTTL)
					{
						taskIndex = currIndex;
						prevTTL = currTask->m_iProcessTime;
					}
				}
			}

			if(taskIndex > -1 && taskIndex < this->m_iCount)
			{
				task = this->m_pTasks[taskIndex];
				this->m_pTasks[taskIndex] = this->m_pTasks[--this->m_iCount];
			}
	
			::ReleaseSRWLockExclusive(&this->m_kLock);

			return task;
		}

		void WorkerThread::_PushTask(Task* task)
		{
			unsigned index;

			if(this->m_iCount == this->m_iCapacity)
				throw SingularityException("Worker thread cannot handle any more tasks.");

			::AcquireSRWLockExclusive(&this->m_kLock);
			{
				index = (this->m_iStart + this->m_iCount) % this->m_iCapacity;
				this->m_pTasks[index] = task;
				++this->m_iCount;
			}
			::ReleaseSRWLockExclusive(&this->m_kLock);
		}

		void WorkerThread::Attach(TaskScheduler* scheduler)
		{
			this->m_pTaskScheduler = scheduler;
			this->m_hThread = ::GetCurrentThread();
			
			::TlsSetValue(this->m_pTaskScheduler->m_iTLSindex, this);
		}

		void WorkerThread::PushTask(Task* task)
		{
			if(task->m_iFrequency > 0)
				this->_PushTask(task);
			else
				this->m_pTaskScheduler->PushTask(task);
		}

		void WorkerThread::ProcessTasks()
		{
			Task* task = NULL;

			// set the workerthread to the global storage area
			::TlsSetValue(this->m_pTaskScheduler->m_iTLSindex, this);

			// prevents while(true) warning during compile
			for(;;)
			{
				// check if we're shutting down
				if (this->m_pTaskScheduler->m_iState >= TASKPOOL_STATE_STOPPING) 
					break;
				
				if((task = this->_PopTask()) != NULL)
					task->_InternalExecute(this);
				else
					::Sleep(0);
			}

			this->m_iState = TASKPOOL_STATE_STOPPED;
		}
		#pragma endregion

		#pragma region Static Methods
		DWORD WINAPI WorkerThread::DoWork(void* value)
		{
			((WorkerThread*)value)->ProcessTasks();
			return 0;
		}
		#pragma endregion
	}
}