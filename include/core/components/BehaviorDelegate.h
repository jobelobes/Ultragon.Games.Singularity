#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		typedef void (*BehaviorCallback)(Behavior* behavior, float elapsedTime);

		class BehaviorDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				BehaviorCallback m_pCallback;

			public:
				BehaviorDelegate(BehaviorCallback callback);
				virtual void Invoke(Behavior* behavior, float elapsedTime);
		};
	}
}