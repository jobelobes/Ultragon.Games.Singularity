#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, CollisionDelegate, Singularity::IDelegate);

		CollisionDelegate::CollisionDelegate(CollisionCallback callback) 
			: m_pCallback(callback) { }

		void CollisionDelegate::Invoke(Collider* collider, Collider* target) 
		{ 
			try
			{
				this->m_pCallback(collider, target); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}