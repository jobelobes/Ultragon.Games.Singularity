#include "animations\Singularity.Animations.h"
 
using namespace Singularity;
using namespace Singularity::Components;
 
namespace Singularity
{
	namespace Animations
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Animations, AnimationTask, Singularity::Threading::Task);

		#pragma region Static Variables
		AnimationTask* AnimationTask::g_pInstance = NULL; 
		#pragma endregion

		#pragma region Constructors and Finalizers
		AnimationTask::AnimationTask() 
			: Task("Animation Extension"), m_pState(NULL)
		{
			unsigned index = 0;

			this->Set_Frequency(1 / 100.0f);

			for(index = 0; index < SINGULARITY_ANIMATION_MAX_SUBTASKS; ++index)
				this->m_pSubTasks[index] = new AnimationSubTask();

			this->m_kTimer.Reset();
			this->m_kTimer.Tick();
		}
		#pragma endregion

		#pragma region Methods
		void AnimationTask::RegisterAnimation(Animation* animation)
		{
			if(animation == NULL)
				throw SingularityException("\"animation\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				this->m_pAnimations.push_back(animation);
			}
		}

		void AnimationTask::UnregisterAnimation(Animation* animation)
		{
			unsigned index, count;

			if(animation == NULL)
				throw SingularityException("\"animation\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				count = this->m_pAnimations.size();
				for(index = 0; index < count; ++index)
				{
					if(this->m_pAnimations[index] == animation)
					{
						this->m_pAnimations[index] = this->m_pAnimations[count - 1];
						this->m_pAnimations.pop_back();
						return;
					}
				}
			}
		}
		#pragma endregion
			
		#pragma region Overriden Methods
		void AnimationTask::OnExecute()
		{
			unsigned index, count, taskCount, animCount;

			#if _DEBUG
			//printf("Animation Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif

			if(this->m_pState == NULL)
				this->m_pState = new AnimationState(0.0f);

			count = this->m_pAnimations.size();
			if(count > 0)
			{
				taskCount = max(min(count / 5, SINGULARITY_ANIMATION_MAX_SUBTASKS), 1);
				animCount = count / taskCount + 1;
				
				for(index = 0; index < taskCount; ++index)
				{
					this->m_pSubTasks[index]->Update(this->m_pState, index * animCount, min((index + 1) * animCount, count), this->Get_ElapsedTime());
					this->Spawn(this->m_pSubTasks[index]);
				}
			}

			this->m_kTimer.Tick();
			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		AnimationTask* AnimationTask::Instantiate()
		{
			if(!AnimationTask::g_pInstance)
				AnimationTask::g_pInstance = new AnimationTask();
			return AnimationTask::g_pInstance;
		}
		#pragma endregion
	}
}