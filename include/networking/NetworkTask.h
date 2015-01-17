#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		class NetworkTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static NetworkTask* g_pInstance;
				#pragma endregion

				#pragma region Variables
				Network*						m_pNetwork;
				DynamicList<NetworkSync*>		m_pSyncPoints;
				#pragma endregion

				#pragma region Constructors and Finalizers
				NetworkTask();
				~NetworkTask();
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnExecute();
				virtual void OnComplete() { };
				#pragma endregion

			public:
				#pragma region Methods
				void RegisterComponent(Singularity::Components::Component* component);
				void UnregisterComponent(Singularity::Components::Component* component);
				#pragma endregion

				#pragma region Static Methods
				static NetworkTask* Instantiate();
				#pragma endregion

				friend class NetworkSync;
		};
	}
}