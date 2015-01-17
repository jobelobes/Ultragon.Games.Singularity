#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class Collider : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Nested Classes
				class InternalContactResultCallback : public btCollisionWorld::ContactResultCallback
				{
					public:
						btCollisionObject* Body;
						DynamicList<Collider*> Colliders;

						btScalar addSingleResult(btManifoldPoint& cp, const btCollisionObject* colObj0, int partId0, int index0, const btCollisionObject* colObj1, int partId1, int index1);
				};
				#pragma endregion

				#pragma region Variables
				unsigned				m_pCurrentIndex;
				DynamicSet<Collider*>*	m_pPrevCollidingObjects;
				DynamicSet<Collider*>*	m_pCurrCollidingObjects;
				#pragma endregion

				#pragma region Methods
				void NotifyOfCollision(Collider* collider);
				void NotifyOfCompletion();
				#pragma endregion

			protected:
				#pragma region Variables
				btCollisionShape*		m_pCollisionShape;
				btRigidBody*			m_pRigidBody;
				PhysicsMotionState*		m_pMotionState;

				Vector3					m_kCenter;
				#pragma endregion

				#pragma region Constructors and Finalizers
				Collider(String name = "", Vector3 center = Vector3(0,0,0));
				#pragma endregion

				#pragma region Methods
				virtual void OnCollisionEnter(Singularity::Physics::Collider* target);
				virtual void OnCollisionExit(Singularity::Physics::Collider* target);
				virtual void OnCollisionStay(Singularity::Physics::Collider* target);
				#pragma endregion

				#pragma region Overriden Methods
				void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Properties
				Vector3& Get_Center();
				void Set_Center(const Vector3& value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				~Collider() {};
				#pragma endregion

				#pragma region Events
				DelegateHandler CollisionEnter;
				DelegateHandler CollisionExit;
				DelegateHandler CollisionStay;
				#pragma endregion

				#pragma region Methods
				void Rotate(Quaternion rotation);
				void Set_Rotation(Quaternion rotation);
				void Translate(Vector3 direction);
				void Set_Position(Vector3 position);
				Quaternion Get_Rotation();
				Vector3 Get_Position();
				void Set_Scale(Vector3 scale);
				#pragma endregion

				#pragma region Static Methods
				static Collider* Raycast(Vector3 start, Vector3 direction, float& dt);
				static DynamicList<Collider*> SphereCast(Vector3 centerpoint, float radius, int& count);
				#pragma endregion

			friend class PhysicsTask;
			friend class PhysicsSubTask;
			friend class RigidBody;
			friend class CollisionDispatcher;
		};

		#include "physics\Collider.inc"
	}
}