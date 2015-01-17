#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		struct Packet
		{
			unsigned __int64	Index;
			UUID				From;
			unsigned short		Type;
			unsigned short		Command;
			unsigned			DataLength;
			char*				Data;
		};
	}
}