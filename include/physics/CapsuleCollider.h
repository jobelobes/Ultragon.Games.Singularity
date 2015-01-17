#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class CapsuleCollider : public Collider
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				float	m_fRadius;
				float	m_fHeight;
				#pragma endregion

			public:
				#pragma region Properties
				const float Get_Radius() const;
				void Set_Radius(const float value);

				const float Get_Height() const;
				void Set_Height(const float value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				CapsuleCollider(String name = "", Vector3 center = Vector3(0,0,0), float radius = 0.5, float height = 2)
					: Collider(name, center), m_fRadius(radius), m_fHeight(height) { }

				~CapsuleCollider() { }
				#pragma endregion
		};
		
		#include "physics\CapsuleCollider.inc"
	}
}