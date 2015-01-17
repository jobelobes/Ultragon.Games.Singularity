#pragma once

#pragma comment( lib, "Ws2_32.lib" )
#pragma comment( lib, "Rpcrt4.lib" )

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <Rpc.h>

// just to make the compiling go down easier
namespace Singularity 
{
	namespace Networking
	{
		struct NetworkServerDescription;
		struct NetworkPlayer;
		struct NetworkGameDescription;

		class NetworkSession;

		class Network;
		class NetworkGame;

		class NetworkSync;
		class NetworkTask;
	}
}

#include "networking\Singularity.Networking.Defines.h"

// dependencies
#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"

#include "networking\IPAddress.h"
#include "networking\Packet.h"

#include "networking\NetworkDelegate.h"
#include "networking\NetworkSession.h"

#include "networking\NetworkPlayer.h"
#include "networking\NetworkGame.h"
#include "networking\Network.h"

#include "networking\NetworkSync.h"
#include "networking\NetworkTask.h"
