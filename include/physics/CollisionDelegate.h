#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		typedef void (*CollisionCallback)(Collider* collider, Collider* target);

		class CollisionDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				CollisionCallback m_pCallback;

			public:
				CollisionDelegate(CollisionCallback callback);
				virtual void Invoke(Collider* collider, Collider* target);
		};
	}
}