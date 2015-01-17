#include "ai\Singularity.AI.h"

namespace Singularity
{
	namespace AI
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.AI, FlockingMover, Component);

		#pragma region Overriden Methods
		void FlockingMover::OnComponentAdded()
		{
			FlockingExtension::Instantiate()->Register(this);
		}

		void FlockingMover::OnComponentRemoved()
		{
			FlockingExtension::Instantiate()->Unregister(this);
		}
		#pragma endregion
	}
}