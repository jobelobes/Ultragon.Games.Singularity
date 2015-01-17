#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		struct NetworkPlayer
		{
			UUID		Id;
			int			PlayerId;
			float		Lag;
			char		Name[256];
		};
	}
}