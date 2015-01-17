#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class CharacterController : public Singularity::Physics::Collider
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static Mesh* g_pBoundingBox;
				#pragma endregion

				#pragma region Static Methods
				Mesh* CreateBoundingBoxMesh();
				#pragma endregion

				#pragma region Variables
				float					m_fRadius;
				float					m_fHeight;
				float					m_fSlopeLimit;
				float					m_fStepOffset;

				//btCollisionShape*		m_pCollisionShape;
				//PhysicsMotionState*		m_pMotionState;
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Properties
				const float Get_Radius() const;
				void Set_Radius(const float value);

				const float Get_Height() const;
				void Set_Height(const float value);

				const float Get_SlopeLimit() const;
				void Set_SlopeLimit(const float value);

				const float Get_StepOffset() const;
				void Set_StepOffset(const float value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				CharacterController(String name = "");
				~CharacterController() {};
				#pragma endregion

				#pragma region Methods
				void Move(Vector3& direction, float amount);
				void Jump(float amount);
				void Set_Gravity(float amount);
				void Set_Mass(float mass);
				void AddExplosiveForce(float force, Vector3 position, float radius);
				#pragma endregion

				friend class PhysicsTask;
		};

		#include "physics\CharacterController.inc"
	}
}