#include "core\Singularity.Core.h"
 
using namespace Singularity;
using namespace Singularity::Threading;
 
namespace Singularity
{
	IMPLEMENT_OBJECT_TYPE(Singularity, GameTask, Singularity::Threading::Task);

	#pragma region Static Variables
	GameTask* GameTask::g_pInstance = NULL; 
	#pragma endregion

	#pragma region Constructors and Finalizers
	GameTask::GameTask()
		: Task("Game Task")
	{
		this->Set_Frequency(1 / 30.0f);
	}
	#pragma endregion

	#pragma region Overriden Methods
	void GameTask::OnExecute()
	{
		MSG msg;

		#if _DEBUG
		//printf("Game Call Frequency = %3.1f\n", this->Get_ActualFrequency());
		#endif

		// process windows messages but don't linger within the loop
		while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		this->Recycle();
	}
	#pragma endregion

	#pragma region Static Methods
	GameTask* GameTask::Instantiate()
	{
		if(!GameTask::g_pInstance)
			GameTask::g_pInstance = new GameTask();
		return GameTask::g_pInstance;
	}
	#pragma endregion
}