#include "networking\Singularity.Networking.h"
 
using namespace Singularity::Threading;
using namespace Singularity::Components;
 
namespace Singularity
{
	namespace Networking
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, NetworkTask, Singularity::Threading::Task);

		#pragma region Static Variables
		NetworkTask* NetworkTask::g_pInstance = NULL; 
		#pragma endregion

		#pragma region Constructors and Finalizers
		NetworkTask::NetworkTask()
			: Task("Network Task")
		{
			this->Set_Frequency(1 / 30.f);

			this->m_pNetwork = Network::ConnectTo(IPAddress("224.0.1.1"), 3245);
		}
		#pragma endregion

		#pragma region Methods
		void NetworkTask::RegisterComponent(Component* component)
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");

			/*if(component->GetType().Equals(NetworkSync::Type))
				this->m_pSyncPoints.push_back((NetworkSync*)component);*/
		}

		void NetworkTask::UnregisterComponent(Component* component)
		{
			
		}
		#pragma endregion
 
		#pragma region Overriden Methods
		void NetworkTask::OnExecute()
		{
			#if _DEBUG
			//printf("Network Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif

			this->m_pNetwork->Update();
			if(this->m_pNetwork->m_pCurrentGame)
				this->m_pNetwork->m_pCurrentGame->Update();

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		NetworkTask* NetworkTask::Instantiate()
		{
			if(!NetworkTask::g_pInstance)
				NetworkTask::g_pInstance = new NetworkTask();
			return NetworkTask::g_pInstance;
		}
		#pragma endregion
	}
}