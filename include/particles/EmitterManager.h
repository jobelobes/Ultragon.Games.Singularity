#include "particles\Singularity.Particles.h"

namespace Singularity
{
	namespace Particles
	{
		class EmitterManager
		{
			private:
				#pragma region Variables
				DynamicList<ParticleEmitter*>		m_pDeadEmitters;
				DynamicList<ParticleEmitter*>		m_pLiveEmitters;
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				EmitterManager();
				~EmitterManager() {}
				#pragma endregion

				#pragma region Methods
				ParticleEmitter* CreateEmitter(EmitterType type, float lifeTime);		//returns an emitter based on the type passed
				void KillEmitter(ParticleEmitter* emitter);								//kills an active emitter
				#pragma endregion
		};
	}
}