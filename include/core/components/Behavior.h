#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		class Behavior : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE

			protected:		
				#pragma region Methods
				void OnComponentAdded(GameObject* gameObject);
				void OnComponentRemoved(GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				Behavior(String name = "") : Component(name) {};
				Behavior(String name, BehaviorDelegate* callback) 
					: Component(name)
				{
					this->Update.Add(callback);
				}
				#pragma endregion

				#pragma region Variables
				DelegateHandler		Update;
				#pragma endregion
		};
	}
}