#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		enum ForceMode { Force = 0, VelocityChange = 1, Acceleration = 2, Impulse = 3 };

		class RigidBody : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				btCollisionShape*	m_pCollisionShape;
				btRigidBody*		m_pRigidBody;
				PhysicsMotionState*	m_pMotionState;

				float				m_fMass;
				bool				m_bFreezeRotation;
				Vector3				m_kCenterOfMass;
				float				m_fDrag;
				float				m_fAngularDrag;
				Vector3				m_kGravity;
				bool				m_bIgnoreGravity;
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Properties
				Vector3 Get_Velocity() const;

				Vector3 Get_AngularVelocity() const;

				const bool Get_FreezeRotation() const;
				void Set_FreezeRotation(const bool value);

				Vector3 Get_CenterOfMass() const;
				void Set_CenterOfMass(const Vector3& value);
				
				float Get_Drag() const;
				void Set_Drag(const float value);

				float Get_AngularDrag() const;
				void Set_AngularDrag(const float value);

				const float Get_Mass() const;
				void Set_Mass(const float value);

				Vector3 Get_Gravity() const;
				void Set_Gravity(const Vector3& value);

				const bool Get_IgnoreGravity();
				void Set_IgnoreGravity(const bool value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				RigidBody(String name = "");
				~RigidBody() {};
				#pragma endregion

				#pragma region Methods
				void AddForce(Vector3 force, ForceMode mode =  Singularity::Physics::ForceMode::Force);
				void AddTorque(Vector3 force, ForceMode mode = Singularity::Physics::ForceMode::Force);
				void AddForceAtPosition(Vector3 force, Vector3 position, ForceMode mode = Singularity::Physics::ForceMode::Force);
				void AddExplosiveForce(float force, Vector3 position, float radius, ForceMode mode = Singularity::Physics::ForceMode::Force);
				void StopAllMovement();
				#pragma endregion

				friend class PhysicsTask;
				friend class Collider;
		};

		#include "physics\RigidBody.inc"
	}
}