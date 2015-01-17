#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		class CollisionDispatcher : public btCollisionDispatcher
		{
			public:
				#pragma region Constructors and Finalizers
				CollisionDispatcher(btCollisionConfiguration* configuration) : btCollisionDispatcher(configuration) {}
				~CollisionDispatcher() {};
				#pragma endregion

				#pragma region Overriden Methods
				//bool needsCollision(btCollisionObject* body0, btCollisionObject* body1);
	
				bool needsResponse(btCollisionObject* body0, btCollisionObject* body1);
	
				//void dispatchAllCollisionPairs(btOverlappingPairCache* pairCache, const btDispatcherInfo& dispatchInfo, btDispatcher* dispatcher);
				#pragma endregion
		};
	}
}