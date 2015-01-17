#include "core\Singularity.Core.h"
 
using namespace Singularity;
 
namespace Singularity
{
	namespace Threading
	{
		#pragma region Static Variables
		__int64 TaskScheduler::CounterFrequency = 0;

		TaskScheduler* TaskScheduler::g_pInstance = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		TaskScheduler::TaskScheduler()
			: m_iTLSindex(TLS_OUT_OF_INDEXES), m_iThreadCount(0), m_pThreads(NULL), m_iState(TASKPOOL_STATE_UNINITIALIZED)
		{
			if(TaskScheduler::CounterFrequency == 0)
				::QueryPerformanceFrequency((LARGE_INTEGER*)&TaskScheduler::CounterFrequency);
		}

		TaskScheduler::~TaskScheduler()
		{
			// release the TLS and set the index to invalid value
			if(this->m_iTLSindex != TLS_OUT_OF_INDEXES)
			{
				TlsFree(this->m_iTLSindex); 
				this->m_iTLSindex = TLS_OUT_OF_INDEXES;
			}
		}
		#pragma endregion

		#pragma region Methods
		void TaskScheduler::_Initialize(int options)
		{
			if(this->m_iState != TASKPOOL_STATE_UNINITIALIZED)
				throw SingularityException("TaskScheduler is already initialized!");

			// initialize Thread Local Storage
			// TLS allows us to have a unified heap across all of the threads
			this->m_iTLSindex = ::TlsAlloc();
			if (this->m_iTLSindex == TLS_OUT_OF_INDEXES)
				throw SingularityException("Unable to allocate local storage.");

			// create the worker threads for the tasking
			// determine the correct thread limit for the process
			this->m_iThreadCount = TaskScheduler::GetProcessorCount();
			if(options == TASKPOOL_OPTION_SINGLETHREADED)
				this->m_iThreadCount = 1;
			else if (this->m_iThreadCount > SINGULARITY_THREADING_MAX_THREADS)
				this->m_iThreadCount = SINGULARITY_THREADING_MAX_THREADS;
			this->m_pThreads = new WorkerThread[this->m_iThreadCount];

			// update the pool's state
			this->m_iState = TASKPOOL_STATE_INITIALIZED;
		}

		void TaskScheduler::_Start()
		{
			unsigned int index;

			if(this->m_iState != TASKPOOL_STATE_INITIALIZED && 
				this->m_iState != TASKPOOL_STATE_IDLE &&
				this->m_iState != TASKPOOL_STATE_STOPPED)
				throw SingularityException("TaskScheduler is already running or cannot be started!");

			// intermediate update to the pool's state
			this->m_iState = TASKPOOL_STATE_STARTING;

			// start up all the threads
			this->m_pThreads[0].Attach(this);
			for( index = 1; index < this->m_iThreadCount; index++)
				this->m_pThreads[index].Start(this);

			// update the pool's state
			this->m_iState = TASKPOOL_STATE_STARTED;

			this->m_pThreads[0].ProcessTasks();
		}

		void TaskScheduler::_Stop()
		{
			unsigned index;

			if(this->m_iState != TASKPOOL_STATE_STARTED && this->m_iState != TASKPOOL_STATE_IDLE)
				throw SingularityException("TaskScheduler is either already stopped or cannot be stopped!");

			// intermediate update to the pool's state
			this->m_iState = TASKPOOL_STATE_STOPPING;

			// spin wait for them to finish
			for( index = 0; index < this->m_iThreadCount; index++)
			{
				while(this->m_pThreads[index].m_iState != TASKPOOL_STATE_STOPPED)
					::Sleep(0);
			}

			// update the pool's state
			this->m_iState = TASKPOOL_STATE_STOPPED;
		}

		void TaskScheduler::PushTask(Task* task)
		{
			unsigned index, thread, threadCount;
			double util, threadUtil;
			
			thread = 0;
			threadUtil = this->m_pThreads[0].Get_Utilization();
			threadCount = this->m_pThreads[0].m_iCount;
			for(index = 1; index < this->m_iThreadCount; index++)
			{
				util = this->m_pThreads[index].Get_Utilization();
				if(util <= threadUtil && this->m_pThreads[index].m_iCount < threadCount)
				{
					thread = index;
					threadUtil = util;
					threadCount = this->m_pThreads[index].m_iCount;
				}
			}

			task->m_eState = TaskState::Ready;
			this->m_pThreads[thread]._PushTask(task);
		}
		#pragma endregion

		#pragma region Static Methods
		void TaskScheduler::Create(int options)
		{
			if(TaskScheduler::g_pInstance != NULL)
				return;

			TaskScheduler::g_pInstance = new TaskScheduler();
			TaskScheduler::g_pInstance->_Initialize(options);
		}

		void TaskScheduler::Push(Task* task)
		{
			if(TaskScheduler::g_pInstance == NULL)
				throw SingularityException("Unable to add task, no scheduler has been created.");

			TaskScheduler::g_pInstance->PushTask(task);
		}

		void TaskScheduler::Start()
		{
			if(TaskScheduler::g_pInstance == NULL)
				throw SingularityException("Unable to start scheduler, no scheduler has been created.");

			TaskScheduler::g_pInstance->_Start();
		}

		void TaskScheduler::Stop()
		{
			if(TaskScheduler::g_pInstance == NULL)
				throw SingularityException("Unable to start scheduler, no scheduler has been created.");

			TaskScheduler::g_pInstance->_Stop();
		}

		unsigned TaskScheduler::GetProcessorCount()
		{
			SYSTEM_INFO si;
			::GetSystemInfo(&si);
			return si.dwNumberOfProcessors;
		}
		#pragma endregion
	}
}