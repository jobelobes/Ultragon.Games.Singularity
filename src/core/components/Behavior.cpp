#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, Behavior, Singularity::Components::Component);

		#pragma region Methods
		void Behavior::OnComponentAdded(GameObject* gameObject)
		{
			BehaviorTask::Instantiate()->RegisterComponent(this);
		}

		void Behavior::OnComponentRemoved(GameObject* gameObject)
		{
			BehaviorTask::Instantiate()->UnregisterComponent(this);
		}
		#pragma endregion
	}
}