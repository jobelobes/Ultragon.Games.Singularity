#include "animations\Singularity.Animations.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Animations
	{
		class AnimationSubTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				AnimationState*				m_pState;
				unsigned					m_iStart;
				unsigned					m_iEnd;
				float						m_fElapsedTime;
				#pragma endregion

				#pragma region Constructors and Finalizers
				AnimationSubTask();
				~AnimationSubTask();
				#pragma endregion

				#pragma region Methods
				void Update(AnimationState* state, unsigned start, unsigned end, float elapsedTime);
				#pragma endregion

			protected:
				#pragma region Event Methods
				void OnExecute();
				void OnComplete() { };
				#pragma endregion

				friend class AnimationTask;
		};
	}
}