#include "particles\Singularity.Particles.h"

//using namespace Singularity::Particles;

namespace Singularity
{
	namespace Particles
	{
		#pragma region Constructors and Deconstructors
		EmitterManager::EmitterManager()
		{
			/*this->m_pDeadEmitters = new DynamicList<ParticleEmitter*>();
			this->m_pLiveEmitters = new DynamicList<ParticleEmitter*>();*/
		}
		#pragma endregion

		#pragma region Methods
		ParticleEmitter* EmitterManager::CreateEmitter(EmitterType type, float lifeTime)
		{
			ParticleEmitter* emitter;

			//checking to see if we have an emitter of the specified type
			//if we have found one, we return that one and move it from the dead list and back to the live list
			for(int i = 0; i < this->m_pDeadEmitters.size(); i++)
				if(this->m_pDeadEmitters[i]->Get_EmitterType() == type)
				{
					emitter = this->m_pDeadEmitters[i];
					emitter->Set_LifeTime(lifeTime);

					unsigned index, size;
				
					// a component was found
					if(index != size)
					{
						// remove the component
						if(size > 1)
							this->m_pDeadEmitters[index] = this->m_pDeadEmitters[size - 1];

						this->m_pDeadEmitters.pop_back();
					}	
					this->m_pLiveEmitters.push_back(emitter);

					//return the emitter
					return emitter;
				}

			//if we can't find an emitter with the specified type, then we have to create a new one
			emitter = new ParticleEmitter(type, lifeTime);
			this->m_pLiveEmitters.push_back(emitter);

			//return the emitter
			return emitter;
		}

		void EmitterManager::KillEmitter(ParticleEmitter* emitter)
		{
			unsigned index, size;

			size = this->m_pLiveEmitters.size();

			if(emitter == NULL || size == 0)
				return;

			// find the component index
			for(index = 0; index < size; index++)
				if(emitter == this->m_pLiveEmitters[index])
					break;
				
			// a component was found
			if(index != size)
			{
				// remove the component
				if(size > 1)
					this->m_pLiveEmitters[index] = this->m_pLiveEmitters[size - 1];
				this->m_pLiveEmitters.pop_back();
			}	

			this->m_pDeadEmitters.push_back(emitter);
		}
		#pragma endregion
	}
}