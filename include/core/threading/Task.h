#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Threading
	{
		struct TASK_OPTIONS
		{
			int Iterations;
			float Frequency;
			int Affenity;
		};

		enum TaskState { Ready = 1, PendingExecute = 2, Executing = 3, PendingComplete = 4, Complete = 5, PendingRecycle = 6, Recycle = 7 };

		class Task : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				String				m_pIdentifier;
				unsigned			m_iAffinity;
				unsigned			m_iRefCount;
				TaskState			m_eState;
				
				Task*				m_pParent;
				WorkerThread*		m_pThread;

				__int64				m_iActualFrequency;
				__int64				m_iFrequency;
				__int64				m_iProcessTime;
				__int64				m_iLastExecution;
				__int64				m_iCurrentExecution;

				SRWLOCK				m_sSRWLock;
				#pragma endregion

				#pragma region Methods
				void _DecrementRef();
				void _InternalExecute(WorkerThread* workerthread);
				#pragma endregion

			protected:
				#pragma region Constructors and Finalizers
				Task(String identifier = "");
				#pragma endregion

				#pragma region Properties
				inline const float Get_ProcessTime() const { return this->m_iProcessTime / (float)TaskScheduler::CounterFrequency; };
				inline void Set_ProcessTime(float value) { this->m_iProcessTime = (__int64)floor(value * TaskScheduler::CounterFrequency); };

				inline Task* Get_ParentTask() const { return this->m_pParent; };

				inline const unsigned Get_ReferenceCount() const { return this->m_iRefCount; };
				#pragma endregion

				#pragma region Methods
				void Spawn(Task* task);
				inline void Recycle() { this->m_eState = TaskState::PendingRecycle; }
				
				virtual void OnExecute() = 0;
				virtual void OnComplete() = 0;
				#pragma endregion

			public:
				#pragma region Properties
				inline unsigned Get_Affinity() { return this->m_iAffinity; };
				inline void Set_Affinity(unsigned value) { this->m_iAffinity = min(10, max(0, value)); };

				inline float Get_Frequency() { return this->m_iFrequency / (float)TaskScheduler::CounterFrequency; };
				inline void Set_Frequency(float value) { this->m_iFrequency = (__int64)floor(value * TaskScheduler::CounterFrequency); };

				inline float Get_ActualFrequency() { return (float)TaskScheduler::CounterFrequency/this->m_iActualFrequency; };

				inline float Get_ElapsedTime() { return this->m_iActualFrequency / (float)TaskScheduler::CounterFrequency; };
				#pragma endregion

				friend class WorkerThread;
				friend class TaskScheduler;
				friend class TaskQueue;
		};
	}
}