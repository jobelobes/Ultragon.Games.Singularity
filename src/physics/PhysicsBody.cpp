#include "physics\Singularity.Physics.h"

using namespace Singularity::Physics::Core;

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, PhysicsBody, Singularity::Components::Component);

		#pragma region Overriden Methods
		void PhysicsBody::OnComponentAdded(GameObject* gameObject)
		{
			PhysicsTask::Instantiate()->RegisterComponent(this);
		}

		void PhysicsBody::OnComponentRemoved(GameObject* gameObject)
		{
			PhysicsTask::Instantiate()->UnregisterComponent(this);
		}
		#pragma endregion
	}
}