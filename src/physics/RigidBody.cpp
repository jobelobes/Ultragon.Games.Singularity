#include "physics\Singularity.Physics.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, RigidBody, Singularity::Components::Component);

		#pragma region Constructors and Finalizers
		RigidBody::RigidBody(String name) 
			: Component(name), m_pCollisionShape(NULL), m_pRigidBody(NULL), m_pMotionState(NULL), 
			m_fMass(1.0f), m_bFreezeRotation(false), m_kCenterOfMass(0,0,0), m_fDrag(0.001f), m_fAngularDrag(0.001f), m_kGravity(0,-10,0), m_bIgnoreGravity(false)
		{
		}
		#pragma endregion

		#pragma region Overriden Methods
		void RigidBody::OnComponentAdded(Singularity::Components::GameObject* gameObject)
		{
			btVector3 intertia;
			btTransform centerOfMass;
			Collider* collider = (Collider*)gameObject->GetComponent(Collider::Type);
			
			if(collider != NULL && collider->m_pRigidBody != NULL)
			{
				this->m_pCollisionShape = collider->m_pCollisionShape;
				
				PhysicsTask::Instantiate()->UnregisterComponent(collider);

				delete collider->m_pMotionState;
				delete collider->m_pRigidBody;
			}
			else
			{
				if(collider == NULL)
					this->m_pCollisionShape = new btEmptyShape();
				else if(collider->GetType().Equals(BoxCollider::Type))
				{
					Vector3 halfExtents = ((BoxCollider*)collider)->Get_Size() * 0.5f;
					this->m_pCollisionShape = new btBoxShape(btVector3(halfExtents.x, halfExtents.y, halfExtents.z));
				}
				else if(collider->GetType().Equals(SphereCollider::Type))
					this->m_pCollisionShape = new btSphereShape(((SphereCollider*)collider)->Get_Radius());
				else if(collider->GetType().Equals(CapsuleCollider::Type))
					this->m_pCollisionShape = new btCapsuleShape(((CapsuleCollider*)collider)->Get_Radius(), ((CapsuleCollider*)collider)->Get_Height());
				else
					throw SingularityException("Unknown collider type has been added.");

				this->m_pCollisionShape->setUserPointer(collider);
			}


			this->m_pCollisionShape->calculateLocalInertia(this->m_fMass, intertia);
			this->m_pMotionState = new PhysicsMotionState(gameObject->Get_Transform(), (collider == NULL) ? Vector3(0,0,0) : collider->Get_Center());
			this->m_pRigidBody = new btRigidBody(this->m_fMass, this->m_pMotionState, this->m_pCollisionShape, intertia);
			this->m_pRigidBody->setAngularFactor(btVector3(this->m_bFreezeRotation?0.0f:1.0f, this->m_bFreezeRotation?0.0f:1.0f, this->m_bFreezeRotation?0.0f:1.0f));
			this->m_pRigidBody->setDamping(this->m_fDrag, this->m_fAngularDrag);
			this->m_pRigidBody->setGravity(btVector3(this->m_kGravity.x, this->m_kGravity.y, this->m_kGravity.z));
			this->m_pRigidBody->setUserPointer(this);

			PhysicsTask::Instantiate()->RegisterComponent(this);

			if(collider != NULL)
			{
				collider->m_pMotionState = this->m_pMotionState;
				collider->m_pRigidBody = this->m_pRigidBody;
			}
		}

		void RigidBody::OnComponentRemoved(Singularity::Components::GameObject* gameObject)
		{
			PhysicsTask::Instantiate()->UnregisterComponent(this);
		}
		#pragma endregion

		#pragma region Methods
		void RigidBody::AddForce(Vector3 force, ForceMode mode)
		{
			
			switch(mode)
			{
				case ForceMode::Force:
					{
						this->m_pRigidBody->applyCentralForce(btVector3(force.x, force.y, force.z));
						break;
					}
				case ForceMode::Impulse:
					{
						this->m_pRigidBody->applyCentralImpulse(btVector3(force.x, force.y, force.z));
						break;
					}
				case ForceMode::VelocityChange:
					{
						this->m_pRigidBody->setLinearVelocity(btVector3(force.x, force.y, force.z));
						break;
					}
			}
		}

		void RigidBody::AddTorque(Vector3 force, ForceMode mode)
		{
			if(this->m_bFreezeRotation)
				return;

			switch(mode)
			{
				case ForceMode::Force:
					{
						this->m_pRigidBody->applyTorque(btVector3(force.x, force.y, force.z));
						break;
					}
				case ForceMode::Impulse:
					{
						this->m_pRigidBody->applyTorqueImpulse(btVector3(force.x, force.y, force.z));
						break;
					}
			}
		}

		void RigidBody::AddForceAtPosition(Vector3 force, Vector3 position, ForceMode mode)
		{
			switch(mode)
			{
				case ForceMode::Force:
					{
						this->m_pRigidBody->applyForce(btVector3(force.x, force.y, force.z), btVector3(position.x, position.y, position.z));
						break;
					}
				case ForceMode::Impulse:
					{
						this->m_pRigidBody->applyImpulse(btVector3(force.x, force.y, force.z), btVector3(position.x, position.y, position.z));
						break;
					}
			}
		}

		void RigidBody::AddExplosiveForce(float force, Vector3 position, float radius, ForceMode mode)
		{
			Vector3 direction = this->Get_GameObject()->Get_Transform()->Get_Position() - position;
			float distance = direction.length();
			if(distance <= radius)
			{
				force *= (1.0f - distance / radius);
				this->AddForce(direction * force, mode);
			}
		}

		void RigidBody::StopAllMovement()
		{
			this->m_pRigidBody->setAngularVelocity(btVector3(0,0,0));
			this->m_pRigidBody->setLinearVelocity(btVector3(0,0,0));
		}

		#pragma endregion
	}
}