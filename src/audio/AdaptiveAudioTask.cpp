#include "audio\Singularity.Audio.h"
 
using namespace Singularity;
using namespace Singularity::Threading;
using namespace Singularity::Components;
 
namespace Singularity
{
	namespace Audio
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Audio, AdaptiveAudioTask, Singularity::Threading::Task);

		#pragma region Static Variables
		
		// The single instance of the AudioExtension.
		AdaptiveAudioTask* AdaptiveAudioTask::g_pInstance = NULL; 

		#pragma endregion

		#pragma region Constructors and Finalizers

		// Constructor.
		AdaptiveAudioTask::AdaptiveAudioTask() 
			: Singularity::Threading::Task("Audio Extension")
		{
			unsigned index = 0;
			
			m_bIsPaused = true;

			this->Set_Frequency(2 / 1.0f); // 2000 milliseconds...for now (one measure @ 120 bpm)

		}
		#pragma endregion

		#pragma region Methods


		void AdaptiveAudioTask::Set_IsPaused(bool pause)
		{
			m_bIsPaused = pause;
		}

		#pragma endregion
			
		#pragma region Overriden Methods
		void AdaptiveAudioTask::OnInitialize()
		{
			this->m_kTimer.Reset();
			this->m_kTimer.Tick();
		}

		void AdaptiveAudioTask::OnExecute()
		{

			// This is where our playback calculations happen...
			// Tell the musicmanager to initiate playback calculations.
			// I'm sure there's a better time to do it at, but I haven't found one yet.

			if (!this->m_bIsPaused)
			{
				DynamicList<Cue*> cues = AdaptiveMusicManager::Instantiate()->GetCuesToPlay();
				for (DynamicList<Cue*>::iterator iter = cues.begin(); iter != cues.end(); iter++)
				{
					(*iter)->PlayCue();
				}
				AdaptiveMusicManager::Instantiate()->ClearCues();
				//AdaptiveMusicManager::Instantiate()->DetermineCuesToPlay();
			}

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods

		// Returns a pointer to the AudioExtension.
		AdaptiveAudioTask* AdaptiveAudioTask::Instantiate()
		{
			if(!AdaptiveAudioTask::g_pInstance)
				AdaptiveAudioTask::g_pInstance = new AdaptiveAudioTask();
			return AdaptiveAudioTask::g_pInstance;
		}

		#pragma endregion
	}
}