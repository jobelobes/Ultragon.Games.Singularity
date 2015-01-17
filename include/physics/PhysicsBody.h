#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		enum ForceMode { Force = 0, VelocityChange = 1, Acceleration = 2, Impulse = 3 };

		class PhysicsBody : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			protected:
				#pragma region Overriden Methods
				void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

				#pragma region Constructors and Finalizers
				PhysicsBody(String name = "") {};
				#pragma endregion

			public:
				#pragma region Properties
				virtual Vector3 Get_Velocity() const = 0;

				virtual Vector3 Get_AngularVelocity() const = 0;
				#pragma endregion

				#pragma region Methods
				virtual void AddForce(Vector3 force, ForceMode mode = Singularity::Physics::ForceMode::Force) = 0;
				virtual void AddTorque(Vector3 force, ForceMode mode = Singularity::Physics::ForceMode::Force) = 0;
				virtual void AddForceAtPosition(Vector3 force, Vector3 position, ForceMode mode = Singularity::Physics::ForceMode::Force) = 0;
				virtual void AddExplosiveForce(float force, Vector3 position, float radius, ForceMode mode = Singularity::Physics::ForceMode::Force) = 0;
				#pragma endregion

				friend class PhysicsTask;
				friend class PhysicsSubTask;
				friend class BruteForceCollider;
		};
	}
}