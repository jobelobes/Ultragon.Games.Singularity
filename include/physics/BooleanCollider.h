#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class BooleanCollider : public Collider
		{
			public:
				#pragma region Variables
				bool				IsPositiveSpace;
				BooleanCollider*	Container;
				#pragma endregion

			protected:
				#pragma region Methods
				bool TestCollision(Collider* collider, CollisionInfo* collisionInfo);

				virtual void OnCollisionEnter(CollisionInfo collision) = 0;
				virtual void OnCollisionExit(CollisionInfo collision) = 0;
				virtual void OnCollisionStay(CollisionInfo collision) = 0;
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				BooleanCollider(String name, bool isPositiveSpace) : Collider(name), IsPositiveSpace(isPositiveSpace) {}
				~BooleanCollider() {}
				#pragma endregion
		};
	}
}