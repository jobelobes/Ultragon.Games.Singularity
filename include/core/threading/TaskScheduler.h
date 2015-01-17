#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Threading
	{
		class TaskScheduler
		{
			private:
				#pragma region Static Variables
				static __int64				CounterFrequency;
				static TaskScheduler*		g_pInstance;
				#pragma endregion

				#pragma region Variables
				unsigned					m_iTLSindex;
				unsigned					m_iState;
				unsigned					m_iThreadCount;
				WorkerThread*				m_pThreads;
				#pragma endregion

				#pragma region Constructors and Finalizers
				TaskScheduler();
				~TaskScheduler();
				#pragma endregion

				#pragma region Methods	
				void _Initialize(int options);
				void _Start();
				void _Stop();
				void _Pause();

				Task* PopTask();
				void PushTask(Task* task);
				#pragma endregion

			public:
				#pragma region Static Methods
				static void Create(int options = 0);
				static void Push(Task* task);
				static void Start();
				static void Stop();

				static unsigned GetProcessorCount();
				#pragma endregion

				friend class WorkerThread;
				friend class Task;
		};
	}
}