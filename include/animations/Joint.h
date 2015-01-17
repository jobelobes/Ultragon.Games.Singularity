#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		struct Joint
		{
			#pragma region Variables
			unsigned		Index;
			int				ParentIndex;
			Vector3			Translation;
			Quaternion		Rotation;
			Vector3			Scale;
			Matrix			Transform;
			Matrix			InvBindpose;
			#pragma endregion
		};
	}
}