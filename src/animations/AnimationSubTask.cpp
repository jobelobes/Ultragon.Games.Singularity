#include "animations\Singularity.Animations.h"
 
using namespace Singularity::Threading;

namespace Singularity
{
	namespace Animations
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Animations, AnimationSubTask, Singularity::Threading::Task);

		#pragma region Constructors and Finalizers
		AnimationSubTask::AnimationSubTask() 
			: Task("Animation Sub-Task"), m_pState(NULL), m_iStart(0), m_iEnd(0), m_fElapsedTime(0) { }
		#pragma endregion

		#pragma region Methods
		void AnimationSubTask::Update(AnimationState* state, unsigned start, unsigned end, float elapsedTime)
		{
			this->m_pState = state;
			this->m_iStart = start;
			this->m_iEnd = end;
			this->m_fElapsedTime = elapsedTime;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void AnimationSubTask::OnExecute()
		{
			unsigned index;
			AnimationTask* task;

			if(this->m_pState == NULL || (this->m_iStart - this->m_iEnd) <= 0)
				return;

			task = (AnimationTask*)this->Get_ParentTask();
			for(index = this->m_iStart; index < this->m_iEnd; ++index)
			{
				if(task->m_pAnimations[index]->Get_Enabled())
					task->m_pAnimations[index]->OnStep(this->m_pState, this->m_fElapsedTime);
			}
		}
		#pragma endregion
	}
}