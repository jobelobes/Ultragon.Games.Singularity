#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace Core
		{
			class World : public Singularity::Object
			{
				DECLARE_OBJECT_TYPE;
				private:
					#pragma region Variables
					DynamicSet<Colliders*>			m_pDirtyColliders;
					Singularity::Octree<Colliders*> m_pWorldBSP;
					#pragma endregion

					#pragma region Methods
					#pragma endregion

				public:
					#pragma region Methods
					void AddCollider(Collider* collider);
					void Simulate(float elapsedTime) = 0;
					#pragma endregion
			};
		}
	}
}