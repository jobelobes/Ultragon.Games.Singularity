#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		typedef void (*PhysicsMotionStateCallback)(PhysicsMotionState* sender);

		#pragma region Constructors and Finalizers
		PhysicsMotionState::PhysicsMotionState(Singularity::Components::Transform* transform, Vector3 centerOfMass, bool lockRotation) 
			: m_pBoundTransform(transform), m_kCenterOfMass(centerOfMass), m_bLockRotation(lockRotation)
		{
		}
		#pragma endregion

		#pragma region Overriden Methods
		void PhysicsMotionState::getWorldTransform(btTransform& worldTrans) const
		{
			Vector3 pos = this->m_pBoundTransform->Get_Position();
			Quaternion rot = this->m_pBoundTransform->Get_Rotation();
			
			worldTrans.setOrigin(btVector3(pos.x, pos.y, pos.z));
			worldTrans.setRotation(btQuaternion(rot.x, rot.y, rot.z, rot.w));
		}

		void PhysicsMotionState::setWorldTransform(const btTransform& worldTrans)
		{
			btVector3 pos = worldTrans.getOrigin();
			btQuaternion rot = worldTrans.getRotation();
			
			this->m_pBoundTransform->Set_Position(Vector3(pos.x(), pos.y(), pos.z()));
			if(!this->m_bLockRotation)
				this->m_pBoundTransform->Set_Rotation(Quaternion(rot.x(), rot.y(), rot.z(), rot.w()));
		}
		#pragma endregion
	}
}