#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class BooleanSphereCollider : public BooleanCollider
		{
			public:
				#pragma region Variables
				Vector3 Center;
				float Radius;
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
				BooleanSphereCollider(String name, bool isPositiveSpace) : BooleanCollider(name, isPositiveSpace){ }
				~BooleanSphereCollider() { }
				#pragma endregion
		};
	}
}