#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, BehaviorDelegate, Singularity::IDelegate);

		BehaviorDelegate::BehaviorDelegate(BehaviorCallback callback) 
			: m_pCallback(callback) { }

		void BehaviorDelegate::Invoke(Behavior* behavior, float elapsedTime) 
		{ 
			try
			{
				this->m_pCallback(behavior, elapsedTime); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}