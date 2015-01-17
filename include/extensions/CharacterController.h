#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Extensions
	{
		class CharacterController : public Singularity::Physics::Collider
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				Vector3 m_kVelocity;

				Vector3	m_kSize;
				Vector3 m_kCenter;

				float	m_fSlopeLimit;
				float	m_fStepOffset;

				bool	m_bDetectCollisions;
				#pragma endregion

			public:
				#pragma region Properties
				Vector3& Get_Center();
				void Set_Center(const Vector3& value);
				
				Vector3& Get_Size();
				void Set_Size(const Vector3& value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				CharacterController(String name = "", Vector3 center = Vector3(0,0,0), Vector3 size = Vector3(1,1,1))
					:Collider(name), m_kCenter(center), m_kSize(size) { }

				~CharacterController() { }
				#pragma endregion

				#pragma region Methods
				void SimpleMove(Vector3 speed);
				void Move(Vector3 motion);
				#pragma endregion
		};
		
		//#include "physics\BoxCollider.inc"
	}
}