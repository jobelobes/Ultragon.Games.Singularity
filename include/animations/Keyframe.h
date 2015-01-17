#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		struct Keyframe
		{
			#pragma region Variables
			int			JointIndex;
			int			FrameNumber;
			Vector3		Translation;
			Quaternion	Rotation;
			Vector3		Scale;
			Vector4		RotTanX;		//Do we need these last bits anymore?
			Vector4		RotTanY;
			Vector4		RotTanZ;
			Vector4		TransTanX;
			Vector4		TransTanY;
			Vector4		TransTanZ;
			#pragma endregion
		};
	}
}