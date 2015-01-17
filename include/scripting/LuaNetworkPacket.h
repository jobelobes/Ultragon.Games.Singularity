#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Networking
	{
		class LuaNetworkPacket : public Packet
		{
			public:
				static LuaNetworkPacket* Create(String data)
				{
					LuaNetworkPacket* packet = (LuaNetworkPacket*)malloc(sizeof(LuaNetworkPacket) + data.size() + 1);
					packet->Index = 0;
					packet->Type = 0x30;
					packet->Command = 0x44;
					packet->DataLength = data.size() + 1;
					memcpy(&packet->Data, data.c_str(), data.size() + 1);
					return packet;
				}
		};
	}
}