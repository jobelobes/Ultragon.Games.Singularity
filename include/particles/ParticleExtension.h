#include "particles\Singularity.Particles.h"

namespace Singularity
{
	namespace Particles
	{
		class ParticleExtension : public Singularity::Components::Extension
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static ParticleExtension*		g_pInstance;
				#pragma endregion

				#pragma region Variables
				CriticalSection					m_kLock;
				Timer							m_kTimer;

				ParticleState*					m_pState;
				DynamicList<ParticleEmitter*>	m_pEmitters;
				DynamicList<ParticleEmitter*>	m_pIdleEmitters;
				ParticleSubTask*				m_pSubTasks[SINGULARITY_PARTICLES_MAX_SUBTASKS];
				#pragma endregion

				#pragma region Constructors and Finalizers
				ParticleExtension();
				#pragma endregion

				#pragma region Methods
				void RegisterEmitter(ParticleEmitter* emitter);
				void UnregisterEmitter(ParticleEmitter* emitter);
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnInitialize();
				virtual void OnExecute();
				virtual void OnComplete() { };
				virtual void OnUninitialize() { };
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				~ParticleExtension();						
				#pragma endregion

				#pragma region Properties
				inline ParticleState* Get_ParticleState() { return this->m_pState; }
				#pragma endregion

				#pragma region Static Methods
				static ParticleExtension* Instantiate();
				#pragma endregion

				friend class ParticleEmitter;
				friend class ParticleSubTask;
		};
	}
}