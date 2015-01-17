#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class SATNarrowPhaseCollider
		{
			private: 
				#pragma region Methods
				#pragma endregion

			public: 
				#pragma region Methods
				void Collide(Collider* collider0, Collider* collider1, ContactSet* contactSet);
				bool Intersect(Collider* collider0, Vector3& point);
				#pragma endregion
		};
	}
}