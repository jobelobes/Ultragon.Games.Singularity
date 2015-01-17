#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class SphereCollider : public Collider
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				float	m_fRadius;
				#pragma endregion

			public:
				#pragma region Properties
				const float Get_Radius() const;
				void Set_Radius(const float value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				SphereCollider(String name, Vector3 center = Vector3(0, 0, 0), float radius = 0.5f) 
					: Collider(name, center), m_fRadius(radius) { }
				~SphereCollider() { }
				#pragma endregion
		};

		#include "physics\SphereCollider.inc"
	}
}