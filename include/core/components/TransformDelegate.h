#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		typedef void (*TransformCallback)(Transform* transform);

		class TransformDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				TransformCallback m_pCallback;

			public:
				TransformDelegate(TransformCallback callback);
				virtual void Invoke(Transform* transform);
		};
	}
}