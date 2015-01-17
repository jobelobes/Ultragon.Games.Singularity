#include "core\Singularity.Core.h"

using namespace Singularity::Components;

namespace Singularity
{
	IMPLEMENT_OBJECT_TYPE(Singularity, BehaviorTask, Singularity::Threading::Task);

	#pragma region Static Variables
	BehaviorTask* BehaviorTask::g_pInstance = NULL; 
	#pragma endregion

	#pragma region Constructors and Finalizers
	BehaviorTask::BehaviorTask()
		: Task("Game Task")
	{
		this->Set_Frequency(1 / 60.0f);
	}
	#pragma endregion

	#pragma region Methods
	void BehaviorTask::RegisterComponent(Component* component)
	{
		if(component == NULL)
			throw SingularityException("\"component\" cannot be null or empty.");

		if(component->GetType().Equals(Behavior::Type))
			this->m_pBehaviors.insert((Behavior*)component);
	}

	void BehaviorTask::UnregisterComponent(Component* component)
	{
		if(component == NULL)
			throw SingularityException("\"component\" cannot be null or empty.");

		if(component->GetType().Equals(Behavior::Type))
			this->m_pBehaviors.erase((Behavior*)component);
	}
	#pragma endregion

	#pragma region Overriden Methods
	void BehaviorTask::OnExecute()
	{
		DynamicSet<Behavior*>::iterator it;

		#if _DEBUG
		//printf("Behavior Call Frequency = %3.1f\n", this->Get_ActualFrequency());
		#endif

		Behavior* behavior;
		for(it = this->m_pBehaviors.begin(); it != this->m_pBehaviors.end(); ++it)
		{
			behavior = *it;
			for(int i = 0; i < behavior->Update.Count(); ++i)
				if(behavior->Update[i]->GetType().Equals(BehaviorDelegate::Type))
					((BehaviorDelegate*)behavior->Update[i])->Invoke(behavior, this->Get_ElapsedTime());
		}

		this->Recycle();
	}
	#pragma endregion

	#pragma region Static Methods
	BehaviorTask* BehaviorTask::Instantiate()
	{
		if(!BehaviorTask::g_pInstance)
			BehaviorTask::g_pInstance = new BehaviorTask();
		return BehaviorTask::g_pInstance;
	}
	#pragma endregion
}