#include "ai\Singularity.AI.h"
 
using namespace Singularity;
using namespace Singularity::Tasks;
using namespace Singularity::Components;
 
namespace Singularity
{
	namespace AI
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.AI, FlockingSubTask, Task);

		#pragma region Constructors and Finalizers
		FlockingSubTask::FlockingSubTask() 
			: Extension("Flocking Sub-Task"), m_fElapsedTime(0.0), m_iStart(0), m_iEnd(0) { }
		#pragma endregion

		#pragma region Methods
		void FlockingSubTask::Update(float elapsedTime, unsigned start, unsigned end)
		{
			this->m_fElapsedTime = elapsedTime;
			this->m_iStart = start;
			this->m_iEnd = end;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void FlockingSubTask::OnExecute()
		{
			unsigned index, searchIndex, avgCount;
			FlockingExtension* extension;
			Vector3 position, searchPosition, avgHeading, avgPosition;

			if((this->m_iStart - this->m_iEnd) <= 0)
				return;
			
			extension = (FlockingExtension*)this->Get_ParentTask();
			for(index = this->m_iStart; index < this->m_iEnd; ++index)
			{
				if(extension->m_pMovers[index]->Get_Enabled())
				{
					avgCount = 0;
					position = extension->m_pMovers[index]->Get_GameObject()->Get_WorldTransformation().Get_Position();
					avgHeading = Vector3(0.0f, 0.0f, 0.0f);
					avgPosition = Vector3(0.0f, 0.0f, 0.0f);

					for(searchIndex = 0; searchIndex < extension->m_pMovers.size(); ++searchIndex)
					{
						if(index == searchIndex || !extension->m_pMovers[index]->Get_Enabled())
							continue;

						searchPosition = extension->m_pMovers[searchIndex]->Get_GameObject()->Get_WorldTransformation().Get_Position();
						if(D3DXVec3LengthSq(&(searchPosition - position)) > 60)
							continue;

						avgHeading += extension->m_pMovers[searchIndex]->m_kHeading;
						avgPosition += searchPosition;
						avgCount++;

						if(avgCount > 10)
							break;
					}

					if(avgCount > 0)
					{
						avgHeading = avgHeading / avgCount + (position - avgPosition / avgCount);
						D3DXVec3Normalize(&avgHeading, &avgHeading);

						extension->m_pMovers[index]->m_kHeading = avgHeading;
					}

					if(abs(position.x) > 100)
						extension->m_pMovers[index]->m_kHeading.x *= -1;
					
					if(abs(position.y) > 100)
						extension->m_pMovers[index]->m_kHeading.y *= -1;
					
					if(abs(position.z) > 100)
						extension->m_pMovers[index]->m_kHeading.z *= -1;

					Transformation transform = extension->m_pMovers[index]->Get_GameObject()->Get_WorldTransformation();
					transform.Translate(extension->m_pMovers[index]->m_kHeading);
					extension->m_pMovers[index]->Get_GameObject()->Set_WorldTransformation(transform);

				}
			}
		}
		#pragma endregion
	}
}