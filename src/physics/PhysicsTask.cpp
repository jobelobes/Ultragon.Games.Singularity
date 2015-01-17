#include "physics\Singularity.Physics.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, PhysicsTask, Singularity::Threading::Task);

		#pragma region Static Variables
		PhysicsTask* PhysicsTask::g_pInstance = NULL;
		#pragma endregion

		void PhysicsTask::NearCallback(btBroadphasePair& collisionPair, btCollisionDispatcher& dispatcher, const btDispatcherInfo& dispatchInfo)
		{
                btCollisionObject* colObj0 = (btCollisionObject*)collisionPair.m_pProxy0->m_clientObject;
                btCollisionObject* colObj1 = (btCollisionObject*)collisionPair.m_pProxy1->m_clientObject;

                if (dispatcher.needsCollision(colObj0,colObj1))
               {
                        //dispatcher will keep algorithms persistent in the collision pair
                        if (!collisionPair.m_algorithm)
                        {
                                collisionPair.m_algorithm = dispatcher.findAlgorithm(colObj0,colObj1);
                        }

                        if (collisionPair.m_algorithm)
                        {
                                btManifoldResult contactPointResult(colObj0,colObj1);
                                
                                if (dispatchInfo.m_dispatchFunc ==              btDispatcherInfo::DISPATCH_DISCRETE)
                                {
                                        //discrete collision detection query
                                        collisionPair.m_algorithm->processCollision(colObj0,colObj1,dispatchInfo,&contactPointResult);
                                } else
                                {
                                        //continuous collision detection query, time of impact (toi)
                                        btScalar toi = collisionPair.m_algorithm->calculateTimeOfImpact(colObj0,colObj1,dispatchInfo,&contactPointResult);
                                        if (dispatchInfo.m_timeOfImpact > toi)
                                                dispatchInfo.m_timeOfImpact = toi;

                                }

								if(contactPointResult.getPersistentManifold()->getNumContacts() == 0)
									return;

								Collider* ptr0 = (Collider*)(((btRigidBody*)colObj0)->getCollisionShape()->getUserPointer());
								Collider* ptr1 = (Collider*)(((btRigidBody*)colObj1)->getCollisionShape()->getUserPointer());

								if(ptr0 && ptr1)
								{
									ptr0->NotifyOfCollision(ptr1);
									ptr1->NotifyOfCollision(ptr0);
								}
                        }
                }

		}

		#pragma region Constructors and Finalizers
		PhysicsTask::PhysicsTask()
			: Task("Physics Extension")
		{
			unsigned index;

			this->Set_Frequency(1 / 80.0f);

			for(index = 0; index < SINGULARITY_PHYSICS_MAX_SUBTASKS; ++index)
				this->m_pSubTasks[index] = new PhysicsSubTask();

			this->m_pCollisionConfiguration = new btDefaultCollisionConfiguration();
			this->m_pDispatcher = new CollisionDispatcher(this->m_pCollisionConfiguration);
			this->m_pDispatcher->setNearCallback(NearCallback);
			this->m_pBroadphase = new btDbvtBroadphase();
			this->m_pSolver = new btSequentialImpulseConstraintSolver();
			this->m_pDynamicsWorld = new btDiscreteDynamicsWorld(this->m_pDispatcher, this->m_pBroadphase, this->m_pSolver, this->m_pCollisionConfiguration);
			this->m_pDynamicsWorld->setGravity(btVector3(0, -10, 0));
		}
		#pragma endregion

		#pragma region Methods
		void PhysicsTask::RegisterComponent(Component* component)
		{
			Autolock(this->m_kLock)
			{
				btRigidBody* body;

				if(component->GetType().IsSubClassOf(CharacterController::Type))
					body = ((CharacterController*)component)->m_pRigidBody;
				else if(component->GetType().IsSubClassOf(Collider::Type))
				{
					body = ((Collider*)component)->m_pRigidBody;
					this->m_pColliders.insert((Collider*)component);
				}
				else if(component->GetType().IsSubClassOf(RigidBody::Type))
				{
					Collider* collider = (Collider*)component->Get_GameObject()->GetComponent(Collider::Type);
					body = ((RigidBody*)component)->m_pRigidBody;
					if(collider != NULL)
						this->m_pColliders.insert(collider);
				}

				this->m_pDynamicsWorld->addRigidBody(body);
			}
		}
		
		void PhysicsTask::UnregisterComponent(Component* component)
		{
			Autolock(this->m_kLock)
			{
				btRigidBody* body;

				if(component == NULL)
					throw SingularityException("\"component\" cannot be null or empty.");

				if(component->GetType().IsSubClassOf(CharacterController::Type))
					body = ((CharacterController*)component)->m_pRigidBody;
				else if(component->GetType().IsSubClassOf(Collider::Type))
				{
					body = ((Collider*)component)->m_pRigidBody;
					this->m_pColliders.erase((Collider*)component);
				}
				else if(component->GetType().IsSubClassOf(RigidBody::Type))
				{
					Collider* collider = (Collider*)component->Get_GameObject()->GetComponent(Collider::Type);
					body = ((RigidBody*)component)->m_pRigidBody;
					if(collider != NULL)
						this->m_pColliders.erase(collider);
				}

				this->m_pDynamicsWorld->removeCollisionObject(body);
			}
		}
		#pragma endregion

		#pragma region Event Methods
		void PhysicsTask::OnExecute()
		{
			DynamicSet<Collider*>::iterator it;

			#if _DEBUG
			//printf("Physics Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif

			Autolock(m_kLock)
			{
				//printf("Start Sim\n");
				this->m_pDynamicsWorld->stepSimulation(this->Get_ElapsedTime());
				for(it = this->m_pColliders.begin(); it != this->m_pColliders.end(); ++it)
					(*it)->NotifyOfCompletion();
			}

			

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		PhysicsTask* PhysicsTask::Instantiate()
		{
			if(PhysicsTask::g_pInstance == NULL)
				PhysicsTask::g_pInstance = new PhysicsTask();
			return PhysicsTask::g_pInstance;
		}
		#pragma endregion
	}
}