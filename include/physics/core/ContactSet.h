#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		struct Contact
		{
			Vector3		Normal;
			Vector3		Point;
			float		Separation;
		};

		struct ContactSet
		{
			unsigned	Count;
			Contact		Contacts[8];

			ContactSet() : Count(0) { };
		};
	}
}