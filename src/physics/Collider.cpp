#include "physics\Singularity.Physics.h"

using namespace Singularity;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, Collider, Singularity::Components::Component);

		#pragma region Nested Classes
		btScalar Collider::InternalContactResultCallback::addSingleResult(btManifoldPoint& cp, const btCollisionObject* colObj0, int partId0, int index0, const btCollisionObject* colObj1, int partId1, int index1)
		{
			if(this->Body != colObj0)
				Colliders.push_back((Collider*)colObj0->getCollisionShape()->getUserPointer());
			else if(this->Body != colObj1)
				Colliders.push_back((Collider*)colObj1->getCollisionShape()->getUserPointer());
			return 0;
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		Collider::Collider(String name, Vector3 center) 
			: Component(name), m_kCenter(center), m_pCollisionShape(NULL), m_pRigidBody(NULL), m_pMotionState(NULL), m_pCurrentIndex(0)
		{
			this->m_pPrevCollidingObjects = new DynamicSet<Collider*>();
			this->m_pCurrCollidingObjects = new DynamicSet<Collider*>();
		}
		#pragma endregion

		#pragma region Methods
		void Collider::NotifyOfCollision(Collider* collider)
		{
			this->m_pCurrCollidingObjects->insert(collider);
		}
		void Collider::NotifyOfCompletion()
		{
			DynamicSet<Collider*>* swap;
			DynamicSet<Collider*>::iterator it;
			unsigned nextIndex = (this->m_pCurrentIndex + 1) % 2;

			for(it = this->m_pCurrCollidingObjects->begin(); it != this->m_pCurrCollidingObjects->end(); ++it)
			{
				if(this->m_pPrevCollidingObjects->find(*it) == this->m_pPrevCollidingObjects->end())
					this->OnCollisionEnter(*it);
				else
					this->OnCollisionStay(*it);
			}

			for(it = this->m_pPrevCollidingObjects->begin(); it != this->m_pPrevCollidingObjects->end(); ++it)
			{
				if(this->m_pCurrCollidingObjects->find(*it) == this->m_pCurrCollidingObjects->end())
					this->OnCollisionExit(*it);
			}

			swap = this->m_pPrevCollidingObjects;
			this->m_pPrevCollidingObjects = this->m_pCurrCollidingObjects;
			this->m_pCurrCollidingObjects = swap;
			this->m_pCurrCollidingObjects->clear();
		}

		void Collider::OnCollisionEnter(Collider* target)
		{
			//printf("Ente: %s\n", this->Get_Name().c_str());
			for(unsigned i = 0; i < this->CollisionEnter.Count(); ++i)
				//if(this->CollisionEnter[i]->GetType().Equals(CollisionDelegate::Type))
					((CollisionDelegate*)this->CollisionEnter[i])->Invoke(this, target);
		}

		void Collider::OnCollisionExit(Collider* target)
		{
			//printf("Exit: %s\n", this->Get_Name().c_str());
			for(unsigned i = 0; i < this->CollisionExit.Count(); ++i)
				//if(this->CollisionExit[i]->GetType().Equals(CollisionDelegate::Type))
					((CollisionDelegate*)this->CollisionExit[i])->Invoke(this, target);
		}

		void Collider::OnCollisionStay(Collider* target)
		{
			//printf("Stay: %s\n", this->Get_Name().c_str());
			for(unsigned i = 0; i < this->CollisionStay.Count(); ++i)
				//if(this->CollisionStay[i]->GetType().Equals(CollisionDelegate::Type))
					((CollisionDelegate*)this->CollisionStay[i])->Invoke(this, target);
		}
		#pragma endregion

		#pragma region Overriden Methods
		void Collider::OnComponentAdded(GameObject* gameObject)
		{
			RigidBody* rigidbody = (RigidBody*)gameObject->GetComponent(RigidBody::Type);

			if(this->GetType().Equals(BoxCollider::Type))
			{
				Vector3 halfExtents = ((BoxCollider*)this)->Get_Size() * 0.5f;
				this->m_pCollisionShape = new btBoxShape(btVector3(halfExtents.x, halfExtents.y, halfExtents.z));
			}
			else if(this->GetType().Equals(SphereCollider::Type))
				this->m_pCollisionShape = new btSphereShape(((SphereCollider*)this)->Get_Radius());
			else if(this->GetType().Equals(CapsuleCollider::Type))
				this->m_pCollisionShape = new btCapsuleShape(((CapsuleCollider*)this)->Get_Radius(), ((CapsuleCollider*)this)->Get_Height());
			else
				throw SingularityException("Unknown collider type has been added.");

			this->m_pCollisionShape->setUserPointer(this);

			if(rigidbody != NULL && rigidbody->m_pRigidBody != NULL)
			{
				this->m_pMotionState = rigidbody->m_pMotionState;
				this->m_pRigidBody = rigidbody->m_pRigidBody;
				this->m_pRigidBody->setUserPointer(this);

				rigidbody->OnComponentAdded(gameObject);
			}
			else
			{
				this->m_pMotionState = new PhysicsMotionState(gameObject->Get_Transform(), this->Get_Center());
				this->m_pRigidBody = new btRigidBody(0.0, this->m_pMotionState, this->m_pCollisionShape);
				this->m_pRigidBody->setCollisionFlags(this->m_pRigidBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
				this->m_pRigidBody->setActivationState(DISABLE_DEACTIVATION) ;
				this->m_pRigidBody->setUserPointer(this);

				PhysicsTask::Instantiate()->RegisterComponent(this);
			}
		}

		void Collider::OnComponentRemoved(GameObject* gameObject)
		{
			PhysicsTask::Instantiate()->UnregisterComponent(this);
		}
		#pragma endregion

		#pragma region Static Methods
		Collider* Collider::Raycast(Vector3 from, Vector3 to, float& dt)
		{
			const btVector3 btFrom(from.x, from.y, from.z);
			const btVector3 btTo(to.x, to.y, to.z);

			btCollisionWorld::ClosestRayResultCallback result(btFrom, btTo);
			PhysicsTask::Instantiate()->m_pDynamicsWorld->rayTest(btFrom, btTo, result);

			if(!result.hasHit())
			{
				dt = 0;
				return NULL;
			}

			dt = result.m_closestHitFraction;
			return (Collider*)result.m_collisionObject->getUserPointer();
		}

		DynamicList<Collider*> Collider::SphereCast(Vector3 centerpoint, float radius, int& count)
		{
			Collider::InternalContactResultCallback callback;
			btTransform transform(btQuaternion(0,0,0,1), btVector3(centerpoint.x, centerpoint.y, centerpoint.z));
			btDefaultMotionState state;
			state.setWorldTransform(transform);
			btSphereShape shape(radius);
			btRigidBody body(1.0f, &state, &shape);

			callback.Body = &body;
			PhysicsTask::Instantiate()->m_pDynamicsWorld->contactTest(callback.Body, callback);
			
			count = callback.Colliders.size();
			return callback.Colliders;
		}

		void Collider::Rotate(Quaternion rotation)
		{
			//btQuaternion q = this->m_pRigidBody->getWorldTransform().getRotation();
			//this->m_pRigidBody->getWorldTransform().setRotation(btQuaternion(rotation.x + q.getX(), rotation.y + q.getY(), rotation.z + q.getZ(), rotation.w + q.getW()));
		}

		void Collider::Set_Rotation(Quaternion rotation)
		{
			this->m_pRigidBody->getWorldTransform().setRotation(btQuaternion(rotation.x, rotation.y, rotation.z, rotation.w));
		}

		void Collider::Translate(Vector3 direction)
		{
			this->m_pRigidBody->translate(btVector3(direction.x, direction.y, direction.z));
		}

		void Collider::Set_Position(Vector3 position)
		{
			this->m_pRigidBody->getWorldTransform().setOrigin(btVector3(position.x, position.y, position.z));
		}

		Quaternion Collider::Get_Rotation()
		{
			btQuaternion q = this->m_pRigidBody->getWorldTransform().getRotation();
			return Quaternion(q.getX(), q.getY(), q.getZ(), q.getW());
		}

		Vector3 Collider::Get_Position()
		{
			btVector3 v = this->m_pRigidBody->getWorldTransform().getOrigin();
			return Vector3(v.getX(),v.getY(),v.getZ());
		}

		void Collider::Set_Scale(Vector3 scale)
		{
			this->m_pCollisionShape->setLocalScaling(btVector3(scale.x, scale.y, scale.z));
		}

		#pragma endregion
	}
}