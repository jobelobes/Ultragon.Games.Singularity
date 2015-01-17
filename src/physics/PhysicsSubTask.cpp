#include "physics\Singularity.Physics.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, PhysicsSubTask, Singularity::Threading::Task);

		#pragma region Constructors and Finalizers
		PhysicsSubTask::PhysicsSubTask()
			: Task("Physics sub task"), m_pParent(NULL), m_fElapsedTime(0), m_iStart(0), m_iEnd(0){ }
		#pragma endregion

		#pragma region Methods
		void PhysicsSubTask::Update(const float elapsedTime, unsigned start, unsigned end)
		{
			this->m_fElapsedTime = elapsedTime;
			this->m_iStart = start;
			this->m_iEnd = end;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void PhysicsSubTask::OnExecute()
		{

		}
		#pragma endregion
	}
}