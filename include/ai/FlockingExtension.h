#include "animations\Singularity.Animations.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace AI
	{
		class FlockingExtension : public Singularity::Components::Extension
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static FlockingExtension* g_pInstance;
				#pragma endregion

				#pragma region Variables
				CriticalSection				m_kLock;
				Timer						m_kTimer;

				DynamicList<FlockingMover*>	m_pMovers;
				FlockingSubTask*			m_pSubTasks[SINGULARITY_AI_MAX_SUBTASKS];
				#pragma endregion

				#pragma region Constructors and Finalizers
				FlockingExtension();
				#pragma endregion

				#pragma region Methods
				void Register(FlockingMover* component);
				void Unregister(FlockingMover* component);
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
				~FlockingExtension();
				#pragma endregion

				#pragma region Static Methods
				static FlockingExtension* Instantiate();
				#pragma endregion

				friend class FlockingMover;
				friend class FlockingSubTask;
		};
	}
}