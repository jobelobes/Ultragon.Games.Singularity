#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class CollisionPair
		{
			public:
				#pragma region Variables
				float			ElapsedTime;
				Collider*		Colliders[2];
				ContactSet		Contacts;
				#pragma endregion

				#pragma region Constructors and Finalizers
				CollisionPair(Collider* collider0, Collider* collider1, float elapsedTime);
				#pragma endregion

				#pragma region Methods
				void Collide();
				#pragma endregion

				#pragma region Overloaded Operators
				bool operator==(const CollisionPair &other) const;
				bool operator<(const CollisionPair &other) const;
				#pragma endregion
		};
	}
}