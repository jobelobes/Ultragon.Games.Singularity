#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{

		#pragma region Static Variables

		// The single instance of the AudioManager.
		AdaptiveMusicManager* AdaptiveMusicManager::g_pInstance = NULL; 

		#pragma endregion

		#pragma region Constructors and Finalizers

		// Constructor.
		AdaptiveMusicManager::AdaptiveMusicManager()
		{
			m_pCurrentEnvironment = NULL;
		}

		// Destructor.
		AdaptiveMusicManager::~AdaptiveMusicManager()
		{
			// Delete all of the soundbanks, wavebanks, etc.
			for (int i = m_pEnvironments.size() - 1; i >= 0; i--)
			{
				delete m_pEnvironments[i];
			}
		}

		#pragma endregion

		#pragma region Methods

		void AdaptiveMusicManager::Play()
		{
			if (m_pEnvironments.size() == 0 && m_pCurrentEnvironment != NULL)
				throw SingularityException("Cannot play adaptive music without first defining an environment for playback.");

			m_pCuesToPlay = m_pCurrentEnvironment->DetermineCuesToPlay();

			AdaptiveAudioTask::Instantiate()->Set_IsPaused(false);
			m_bIsPlaying = true;
		}

		// Stops all cues that are currently playing.
		void AdaptiveMusicManager::StopAll()
		{
			for (DynamicList<Cue*>::iterator iter = m_pCuesToPlay.begin(); iter != m_pCuesToPlay.end(); iter++)
			{
				(*iter)->Stop();
			}
			m_bIsPlaying = false;
			AdaptiveAudioTask::Instantiate()->Set_IsPaused(true);
		}

				// Registers an AudioEmitter.
		void AdaptiveMusicManager::AddEnvironment(AdaptiveEnvironment* envir)
		{
			if(envir == NULL)
				throw SingularityException("\"envir\" cannot be null or empty.");


			this->m_pEnvironments.push_back(envir);
			
		}
		
		void AdaptiveMusicManager::SetCurrentEnvironment(String name)
		{
			for (DynamicList<AdaptiveEnvironment*>::iterator iter = m_pEnvironments.begin(); iter != m_pEnvironments.end(); iter++)
			{
				if ((*iter)->GetName() == name)
					m_pCurrentEnvironment = *iter;
			}
			// otherwise, don't change it
		}

		bool AdaptiveMusicManager::Get_IsPlaying()
		{
			return this->m_bIsPlaying;
		}

		DynamicList<Cue*> AdaptiveMusicManager::GetCuesToPlay()
		{
			return m_pCuesToPlay;
		}

		void AdaptiveMusicManager::ClearCues()
		{
			m_pCuesToPlay.clear();
			// I guess it's not really a clear...
			m_pCuesToPlay = this->m_pCurrentEnvironment->DetermineCuesToPlay();
		}

		void AdaptiveMusicManager::SetVariable(String variable, float value)
		{
			m_pCurrentEnvironment->SetVariable(variable, value);
		}

				// Unregisters an AudioEmitter.
		//void AdaptiveAudioTask::UnregisterEnvironment(AdaptiveEnvironment* envir)
		//{
		//	unsigned index, count;

		//	if(envir == NULL)
		//		throw SingularityException("\"envir\" cannot be null or empty.");

		//	lock(this->m_kLock)
		//	{
		//		count = this->m_pEnvironments.size();
		//		for(index = 0; index < count; ++index)
		//		{
		//			if(this->m_pEnvironments[index] == envir)
		//			{
		//				this->m_pEnvironments[index] = this->m_pEnvironments[count - 1];
		//				this->m_pEnvironments.pop_back();
		//			}
		//		}
		//	}
		//}


		#pragma endregion

		#pragma region Static Methods

		// Returns the single instance of the AudioManager.
		AdaptiveMusicManager* AdaptiveMusicManager::Instantiate()
		{
			if(!AdaptiveMusicManager::g_pInstance)
				AdaptiveMusicManager::g_pInstance = new AdaptiveMusicManager();
			return AdaptiveMusicManager::g_pInstance;
		}

		#pragma endregion

	}
}