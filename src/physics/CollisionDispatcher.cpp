#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{	
		#pragma region Overriden Methods
		bool CollisionDispatcher::needsResponse(btCollisionObject* body0, btCollisionObject* body1)
		{
			return btCollisionDispatcher::needsResponse(body0, body1);
			
			/*if(!value)
				return false;

			Collider* ptr0 = (Collider*)(((btRigidBody*)body0)->getCollisionShape()->getUserPointer());
			Collider* ptr1 = (Collider*)(((btRigidBody*)body1)->getCollisionShape()->getUserPointer());

			if(ptr0 == NULL || ptr1 == NULL)
				return true;

			ptr0->NotifyOfCollision(ptr1);
			ptr1->NotifyOfCollision(ptr0);
			return true;*/
		}
		#pragma endregion
	}
}