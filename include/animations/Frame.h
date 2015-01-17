#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		struct Frame
		{
			DynamicList<Keyframe>	Keyframes;
			int						Index;
		};
	}
}