#include "animations\Singularity.Animations.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Animations
	{
		class AnimationTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static AnimationTask* g_pInstance;
				#pragma endregion

				#pragma region Variables
				CriticalSection				m_kLock;
				Timer						m_kTimer;

				AnimationState*				m_pState;
				DynamicList<Animation*>		m_pAnimations;
				AnimationSubTask*			m_pSubTasks[SINGULARITY_ANIMATION_MAX_SUBTASKS];
				#pragma endregion

				#pragma region Constructors and Finalizers
				AnimationTask();
				#pragma endregion

				#pragma region Methods
				void RegisterAnimation(Animation* renderer);
				void UnregisterAnimation(Animation* renderer);
				#pragma endregion

			protected:
				#pragma region Event Methods
				void OnExecute();
				void OnComplete() { };
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				~AnimationTask();
				#pragma endregion

				#pragma region Static Methods
				static AnimationTask* Instantiate();
				#pragma endregion

				friend class Animation;
				friend class AnimationSubTask;
		};
	}
}