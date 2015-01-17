#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class IBroadPhaseCollider
		{
			public: 
				#pragma region Methods
				virtual void AddCollider(Collider* collider) = 0;
				virtual void RemoveCollider(Collider* collider) = 0;
				virtual void Update(float elapsedTime) = 0;
				#pragma endregion
		};
	}
}