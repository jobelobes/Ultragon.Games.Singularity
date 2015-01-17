#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Threading
	{
		class TaskPool;

		class WorkerThread 
		{
			private:
				#pragma region Variables
				DWORD				m_iId;
				HANDLE				m_hThread;
				unsigned			m_iState;

				const unsigned		m_iCapacity;
				unsigned			m_iStart;
				unsigned			m_iCount;
				Task**				m_pTasks;

				TaskScheduler*		m_pTaskScheduler;

				SRWLOCK				m_kLock;
				#pragma endregion

				#pragma region Methods
				bool Start(TaskScheduler* scheduler);
				
				Task* _PopTask();
				void _PushTask(Task* task);

				void ProcessTasks();
				#pragma endregion

				#pragma region Constructors and Finalizers
				WorkerThread(const unsigned capacity = SINGULARITY_THREADING_MAX_TASKS);
				~WorkerThread();
				#pragma endregion

			public:
				#pragma region Properties
				const double Get_Utilization();
				#pragma endregion

				#pragma region Methods
				void Attach(TaskScheduler* scheduler);

				void PushTask(Task* task);
				#pragma endregion

				#pragma region Static Methods
				static DWORD WINAPI DoWork(void* value);
				#pragma endregion

				friend class Task;
				friend class TaskScheduler;
		};
	}
}