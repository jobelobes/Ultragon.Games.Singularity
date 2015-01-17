#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, TransformDelegate, Singularity::IDelegate);

		TransformDelegate::TransformDelegate(TransformCallback callback) 
			: m_pCallback(callback) { }

		void TransformDelegate::Invoke(Transform* transform) 
		{ 
			try
			{
				this->m_pCallback(transform); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}