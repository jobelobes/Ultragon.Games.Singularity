#include "core\Singularity.Core.h"

using namespace Singularity;
using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	#pragma region Constructors and Finalizers
	Game::Game()
	{
		ULONG HeapFragValue;

		// Use low fragmentation heap
		HeapFragValue = 2;
		::HeapSetInformation(::GetProcessHeap(), HeapCompatibilityInformation, &HeapFragValue, sizeof(HeapFragValue));
	}

	Game::~Game()
	{
		TaskScheduler::Stop();
		exit(0);
	}
	#pragma endregion

	#pragma region Methods
	void Game::Run()
	{
		if(Scene::Get_Current() == NULL)
			Scene::Create()->Activate();

		TaskScheduler::Create();
		TaskScheduler::Push(Singularity::GameTask::Instantiate());
		TaskScheduler::Push(Singularity::BehaviorTask::Instantiate());
	
		this->BeginRun();

		TaskScheduler::Start();
	}

	void Game::Exit()
	{
		TaskScheduler::Stop();
		exit(0);
	}	
	#pragma endregion
}