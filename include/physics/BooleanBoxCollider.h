#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class BooleanBoxCollider : public BooleanCollider
		{
			public:
				#pragma region Variables
				Vector3 Center;
				Vector3 Orientation[3];	//local rotation axis
				Vector3 HalfLength;
				#pragma endregion

			protected:
				#pragma region Event Methods
				bool TestCollision(Collider* collider, CollisionInfo* collisionInfo);

				virtual void OnCollisionEnter(CollisionInfo collision) = 0;
				virtual void OnCollisionExit(CollisionInfo collision) = 0;
				virtual void OnCollisionStay(CollisionInfo collision) = 0;
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				BooleanBoxCollider(String name, bool isPositiveSpace) : BooleanCollider(name, isPositiveSpace) {}
				~BooleanBoxCollider() { }
				#pragma endregion
		};
	}
}