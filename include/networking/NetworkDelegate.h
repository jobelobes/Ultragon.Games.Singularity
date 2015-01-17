#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		typedef void (*NetworkCallback)(Packet* packet);

		class NetworkDelegate : public IDelegate
		{
			DECLARE_OBJECT_TYPE;
			
			private:
				NetworkCallback m_pCallback;

			public:
				NetworkDelegate(NetworkCallback callback);
				virtual void Invoke(Packet* packet);
		};
	}
}