#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class INarrowPhaseCollider
		{
			public: 
				#pragma region Methods
				virtual void Collide(Collider* collider0, Collider* collider1, ContactSet* contactSet) = 0;
				virtual bool Intersect(Collider* collider0, Vector3& point) = 0;
				#pragma endregion
		};
	}
}