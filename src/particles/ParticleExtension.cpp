#include "particles\Singularity.Particles.h"

using namespace Singularity;
using namespace Singularity::Graphics;
using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Particles
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Particles, ParticleExtension, Extension);

		#pragma region Static Variables
		ParticleExtension* ParticleExtension::g_pInstance = NULL;
		#pragma endregion

		#pragma region Constructors and Deconstructors
		ParticleExtension::ParticleExtension()
			: Extension("Particle Extension"), m_pState(NULL)
		{
			unsigned index = 0;

			this->Set_Frequency(1 / 100.0f);

			for(index = 0; index < SINGULARITY_PARTICLES_MAX_SUBTASKS; ++index)
				this->m_pSubTasks[index] = new ParticleSubTask();
		}
		#pragma endregion

		#pragma region Methods
		void ParticleExtension::RegisterEmitter(ParticleEmitter* emitter)
		{
			if(emitter == NULL)
				throw SingularityException("\"particle emitter\" cannot be null or empty");

			lock(this->m_kLock)
			{
				this->m_pEmitters.push_back(emitter);
			}
		}

		void ParticleExtension::UnregisterEmitter(Singularity::Particles::ParticleEmitter* emitter)
		{
			unsigned index, count;

			if(emitter == NULL)
				throw SingularityException("\"particle emitter\" cannot be null or empty");

			lock(this->m_kLock)
			{
				count = this->m_pEmitters.size();
				for(index = 0; index < count; ++index)
				{
					if(this->m_pEmitters[index] == emitter)
					{
						this->m_pEmitters[index] = this->m_pEmitters[count - 1];
						this->m_pEmitters.pop_back();
					}
				}
			}

		}
		#pragma endregion

		#pragma region Overriden Methods
		void ParticleExtension::OnInitialize()
		{
			this->m_kTimer.Reset();
			this->m_kTimer.Tick();
		}

		void ParticleExtension::OnExecute()
		{
			unsigned index, count, taskCount, emitterCount;
			ParticleState* state;

			#if _DEBUG
			printf("Particle Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif

			if(this->m_pState == NULL)
				this->m_pState = new ParticleState(0.0f);

			this->m_pState->ElapsedTime = this->m_kTimer.Get_ElapsedTime();

			count = this->m_pEmitters.size();
			if(count > 0)
			{
				taskCount = max(min(count / 5, SINGULARITY_PARTICLES_MAX_SUBTASKS), 1);
				emitterCount = taskCount == 0 ? 0 : count / taskCount + 1;

				for(index = 0; index < taskCount; ++index)
				{
					this->m_pSubTasks[index]->Update(this->m_pState, index * emitterCount, min((index + 1) * emitterCount, count));
					this->Spawn(this->m_pSubTasks[index]);
				}
			}
			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		ParticleExtension* ParticleExtension::Instantiate()
		{
			if(!ParticleExtension::g_pInstance)
				ParticleExtension::g_pInstance = new ParticleExtension();

			return ParticleExtension::g_pInstance;
		}
		#pragma endregion
	}
}