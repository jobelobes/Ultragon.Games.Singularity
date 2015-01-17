#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Threading
	{
		class TaskQueue
		{
			private:
				#pragma region Variables
				unsigned		m_iCount;
				unsigned		m_iCapacity;
				Task**			m_pNodes;

				SRWLOCK			m_sSRWLock;
				#pragma endregion

				#pragma region Methods
				double _calculateWeight(Task* task, unsigned __int64& now);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				TaskQueue(int capacity);
				~TaskQueue();
				#pragma endregion

				#pragma region Methods
				Task* Pop();
				void Push(Task* task);
				#pragma endregion

				friend class Task;
				friend class TaskPool;
		};
	}
}