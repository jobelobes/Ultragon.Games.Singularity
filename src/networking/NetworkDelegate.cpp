#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Networking, NetworkDelegate, Singularity::IDelegate);

		NetworkDelegate::NetworkDelegate(NetworkCallback callback) 
			: m_pCallback(callback) { }

		void NetworkDelegate::Invoke(Packet* packet) 
		{ 
			try
			{
				this->m_pCallback(packet); 
			}
			catch(SingularityException ex)
			{
			}
		}
	}
}