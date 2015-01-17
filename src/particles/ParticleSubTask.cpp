#include "particles\Singularity.Particles.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Particles
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Particles, ParticleSubTask, Task);

		#pragma region Constructors and Deconstructors
		ParticleSubTask::ParticleSubTask()
			: RenderExtension("Particle Sub Task"), m_pState(NULL), m_iStart(0), m_iEnd(0) { }

		ParticleSubTask::~ParticleSubTask() { }
		#pragma endregion

		#pragma region Methods
		void ParticleSubTask::Update(ParticleState* state, unsigned start, unsigned end)
		{
			this->m_pState = state;
			this->m_iStart = start;
			this->m_iEnd = end;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void ParticleSubTask::OnRenderExecute(GraphicsDevice* device)
		{
			unsigned index;

			ParticleExtension* extension;

			if((this->m_iStart - this->m_iEnd) <= 0)
				return;

			extension = (ParticleExtension*)this->Get_ParentTask();
			for(index = this->m_iStart; index < this->m_iEnd; ++index)
			{
				if(extension->m_pEmitters[index]->Get_Enabled())
					extension->m_pEmitters[index]->OnRender(device);
			}
		}
		#pragma endregion
	}
}