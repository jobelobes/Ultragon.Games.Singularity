#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class PhysicsMotionState : public btMotionState
		{
			public:
				#pragma region Variables
				Vector3								m_kCenterOfMass;
				Singularity::Components::Transform* m_pBoundTransform;
				bool								m_bLockRotation;
				#pragma endregion

				#pragma region Constructors and Finalizers
				PhysicsMotionState(Singularity::Components::Transform* transform, Vector3 centerOfMass = Vector3(0,0,0), bool lockRotation = false);
				~PhysicsMotionState() {};
				#pragma endregion

				#pragma region Overriden Methods
				void getWorldTransform(btTransform& worldTrans) const;
				void setWorldTransform(const btTransform& worldTrans);
				#pragma endregion

				friend class RigidBody;
				friend class Collider;
		};
	}
}