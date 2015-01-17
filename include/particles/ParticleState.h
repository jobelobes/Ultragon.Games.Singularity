#include "particles\Singularity.Particles.h"

namespace Singularity
{
	namespace Particles
	{
		struct ParticleState
		{
			public:
				#pragma region Variables
				float ElapsedTime;
				float Speed;
				#pragma endregion

				#pragma region Constructors and Finalizers
				ParticleState(float elapsedTime = 1.0f, float speed = 1.0f) : ElapsedTime(elapsedTime), Speed(speed) { }
				#pragma endregion
		};
	}
}