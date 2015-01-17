#include "collision\Singularity.Collision.h"

using namespace Singularity;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Collision
	{
		struct CollisionInfo
		{
				Collider*									Actor;
				Singularity::Transformation					Transform;
				Singularity::Components::GameObject*		Reactor;
		};
	}
}