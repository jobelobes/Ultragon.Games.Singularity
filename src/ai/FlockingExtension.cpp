#include "ai\Singularity.AI.h"
 
using namespace Singularity;
using namespace Singularity::Components;
 
namespace Singularity
{
	namespace AI
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.AI, FlockingExtension, Extension);

		#pragma region Static Variables
		FlockingExtension* FlockingExtension::g_pInstance = NULL; 
		#pragma endregion

		#pragma region Constructors and Finalizers
		FlockingExtension::FlockingExtension() 
			: Extension("Flocking Extension")
		{
			unsigned index = 0;

			this->Set_Frequency(1 / 100.0f);

			for(index = 0; index < SINGULARITY_AI_MAX_SUBTASKS; ++index)
				this->m_pSubTasks[index] = new FlockingSubTask();
		}
		#pragma endregion

		#pragma region Methods
		void FlockingExtension::Register(FlockingMover* component)
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");

			lock(this->m_kLock)
			{
				this->m_pMovers.push_back(component);
			}
		}

		void FlockingExtension::Unregister(FlockingMover* component)
		{
			unsigned index, count;

			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");

			lock(this->m_kLock)
			{
				count = this->m_pMovers.size();
				for(index = 0; index < count; ++index)
				{
					if(this->m_pMovers[index] == component)
					{
						this->m_pMovers[index] = this->m_pMovers[count - 1];
						this->m_pMovers.pop_back();
					}
				}
			}
		}
		#pragma endregion
			
		#pragma region Overriden Methods
		void FlockingExtension::OnInitialize()
		{
			this->m_kTimer.Reset();
			this->m_kTimer.Tick();
		}

		void FlockingExtension::OnExecute()
		{
			unsigned index, count, taskCount, flockingCount;
			float elapsedTime;

			#if _DEBUG
			printf("Flocking Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif
			
			elapsedTime = this->m_kTimer.Get_ElapsedTime();

			count = this->m_pMovers.size();
			if(count > 0)
			{
				taskCount = max(min(count / 5, SINGULARITY_AI_MAX_SUBTASKS), 1);
				flockingCount = count / taskCount + 1;
				
				for(index = 0; index < taskCount; ++index)
				{
					this->m_pSubTasks[index]->Update(elapsedTime, index * flockingCount, min((index + 1) * flockingCount, count));
					this->Spawn(this->m_pSubTasks[index]);
				}
			}

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		FlockingExtension* FlockingExtension::Instantiate()
		{
			if(!FlockingExtension::g_pInstance)
				FlockingExtension::g_pInstance = new FlockingExtension();
			return FlockingExtension::g_pInstance;
		}
		#pragma endregion
	}
}