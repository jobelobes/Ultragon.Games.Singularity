#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Animations
	{
		struct AnimationState
		{
			public:
				#pragma region Variables
				float ElapsedTime;
				float Speed;
				#pragma endregion

				#pragma region Constructors and Finalizers
				AnimationState(float elapsedTime = 1.0f, float speed = 1.0f/100.0f) : ElapsedTime(elapsedTime), Speed(speed) { }
				#pragma endregion
		};
	}
}