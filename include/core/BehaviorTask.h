#include "core\Singularity.Core.h"

namespace Singularity
{
	class BehaviorTask : public Singularity::Threading::Task
	{
		DECLARE_OBJECT_TYPE;

		private:
			#pragma region Static Variables
			static BehaviorTask*	g_pInstance;
			#pragma endregion

			#pragma region Static Variables
			DynamicSet<Singularity::Components::Behavior*>	 m_pBehaviors;
			#pragma endregion

			#pragma region Constructors and Finalizers
			BehaviorTask();
			~BehaviorTask() {};
			#pragma endregion

		protected:
			#pragma region Event Methods
			void OnExecute();
			void OnComplete() { };
			#pragma endregion

		public:
			#pragma region Methods
			void RegisterComponent(Singularity::Components::Component* component);
			void UnregisterComponent(Singularity::Components::Component* component);
			#pragma endregion

			#pragma region Static Methods
			static BehaviorTask* Instantiate();
			#pragma endregion

			friend class Singularity::Components::Behavior;
	};
}