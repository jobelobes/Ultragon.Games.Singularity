#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{

		#pragma region Static Variables

		// The single instance of the AudioManager.
		AudioManager* AudioManager::g_pInstance = NULL; 

		#pragma endregion

		#pragma region Constructors and Finalizers

		// Constructor.
		AudioManager::AudioManager()
		{
			m_bInitialized = false;
			m_pEngine = NULL;
			m_pListener = NULL;
		}

		// Destructor.
		AudioManager::~AudioManager()
		{
			// Delete all of the soundbanks, wavebanks, etc.
			for (int i = m_pSoundBanks.size() - 1; i >= 0; i--)
			{
				delete m_pSoundBanks[i];
			}
			for (int i = m_pWaveBanks.size() - 1; i >= 0; i--)
			{
				delete m_pWaveBanks[i];
			}
			for (int i = m_pCues.size() - 1; i >= 0; i--)
			{
				delete m_pCues[i];
			}
			for (int i = m_pEmitters.size() - 1; i >= 0; i--)
			{
				delete m_pEmitters[i];
			}
			if (m_pListener != NULL)
			{
				delete m_pListener;
				m_pListener = NULL;
			}
			if (m_pEngine != NULL)
			{
				delete m_pEngine;
				m_pEngine = NULL;
			}
		}

		#pragma endregion

		#pragma region Methods

		// Updates the engine.
		void AudioManager::UpdateEngine()
		{
			m_pEngine->UpdateEngine();
		}

		// Cleans up any extraneous "stuff".
		void AudioManager::CleanUp()
		{
			// Destroys all of the cues, wavebanks, and soundbanks that are inactive. This requires metadata such as which files are associated with a cue.
		}

		// Tests audio playback. MUST BE REMOVED FOR FINAL IMPLEMENTATION.
		void AudioManager::TestEngine()
		{
			// Test functions.

			// 1st tier: Basic playback
			
			// Load in test settings
			Initialize();
			CreateEngine("..\\..\\..\\Assets\\Audio\\Win\\Test.xgs");
			//CreateEngine("a"); // this should do nothing because the engine is already there.

			// Load in wavebanks
			WaveBank* wb = LoadWaveBank("..\\..\\..\\Assets\\Audio\\Win\\Speech.xwb");
			WaveBank* wb2 = LoadWaveBank("..\\..\\..\\Assets\\Audio\\Win\\Tada.xwb");
			WaveBank* wb3 = LoadWaveBank("..\\..\\..\\Assets\\Audio\\Win\\Windows.xwb");

			// Load in soundbanks
			SoundBank* sb = LoadSoundBank("..\\..\\..\\Assets\\Audio\\Win\\Speech.xsb");
			SoundBank* sb2 = LoadSoundBank("..\\..\\..\\Assets\\Audio\\Win\\Tada.xsb");
			SoundBank* sb3 = LoadSoundBank("..\\..\\..\\Assets\\Audio\\Win\\Windows.xsb");

			//IXACT3Cue* cue;

			//m_pEngine->SetMasterVolume(0.01f);
			m_pEngine->SetMasterVolume(2.0f);

			//sb2->GetSoundBank()->Play(0, 0, 0, &cue); // tada!

			//Cue* cue = sb2->PrepareNewCueFromCueIndex(0);

			//cue->PlayCue();

			//AudioEmitter* emit = GetNewEmitter("tada");

			// Play one cue
			//Cue = sb.PrepareNewCue( );
			//Cue.Play()
			
			//emit->Play();

			//AudioListener* listen = GetSingleListener();




			//int a = 0;

			//cue->UpdateState();

			//while (cue->IsPlaying() == true)
			//{
			//	cue->UpdateState();
			//	a++;
			//	// just kinda hang out for a bit and increment
			//}

			//cue->PlayCue();

			// Play all cues at once
			//for (int i = 0; i < sb.NumIndexes)
			//{
			//		sb.play(i)
			//}
			//for (int i = 0; i < sb.NumIndexes)
			//{
			//		sb2.play(i)
			//}
			//for (int i = 0; i < sb.NumIndexes)
			//{
			//		sb3.play(i)
			//}

			// 2nd tier: hooking up to the scheduler

			// 3rd tier: mandatory audio features and 3d audio

			// We also want to add in VOLUME, PAUSE, RESUME, STOP, MUTE in here later.

			// 4rd tier: adaptive stuff

			// 5th tier: ducking by category, 2d fades, other cool things XACT hates with a passion

		}

		// Initializes the AudioManager.
		void AudioManager::Initialize()
		{
			// CreateEngine MUST be called before Initialize.
			if (m_pEngine != NULL)
			{
				//CoInitializeEx( NULL, COINIT_MULTITHREADED);  // should be done by engine
				m_bInitialized = true;
			}
		}

		// Loads in a wavebank from a file. (*.xwb)
		WaveBank* AudioManager::LoadWaveBank(string path)
		{
			WaveBank* wb = m_pEngine->LoadWaveBankInMemory(path);
			if (wb == NULL)
				throw SingularityException("Failed to load wavebank.");

			m_pWaveBanks.push_back(wb);
			return wb;
		}

		// Streams a wavebank from a file. (*.xwb)
		WaveBank* AudioManager::LoadStreamingWaveBank(string path)
		{
			// TODO: This currently just loads a wavebank into memory rather than streaming. It's a lie!

			WaveBank* wb = m_pEngine->LoadWaveBankInMemory(path);
			if (wb == NULL)
				throw SingularityException("Failed to load wavebank.");

			m_pWaveBanks.push_back(wb);
			return wb;

		}

		// Loads in a soundbank from a file. (*.xsb)
		SoundBank* AudioManager::LoadSoundBank(string path)
		{
			SoundBank* sb =  m_pEngine->LoadSoundBank(path);
			if (sb == NULL)
				throw SingularityException("Failed to load soundbank.");

			m_pSoundBanks.push_back(sb);
			return sb;
		}

		// Creates the AudioEngine and applies its global settings from a file. (*.xgs)
		void AudioManager::CreateEngine(string path)
		{
			// If we want to do a second global settings file...oh well. That'll take changes.
			// Load in here. If somebody wants to create another one, we can try that, I guess.
			
			// Inspired and partially borrowed from DirectX examples

			AudioEngine* engine = new AudioEngine();
			engine->LoadEngine(path);
			engine->Initialize();

			m_pEngine = engine;

		}

		// Creates and returns an AudioEmitter object.
		AudioEmitter* AudioManager::GetNewEmitter(string cueName)
		{
			// Creates an emitter that is unattached to a GameObject.
			
			AudioEmitter* emit = new AudioEmitter(cueName);
			//Cue* cue = CreateCue(cueName);
			//emit->Initialize(cue);
			m_pEmitters.push_back(emit);
			return emit;
		}

		// Creates and returns a cue using a provided and predetermined cue name.
		Cue* AudioManager::CreateCue(string cueName, bool isLooping, bool is3d)
		{
			Cue* cue = NULL;
			int cueNum = XACTINDEX_INVALID;

			for (DynamicList<SoundBank*>::iterator iter = m_pSoundBanks.begin(); iter != m_pSoundBanks.end(); iter++)
			{
				cueNum = (*iter)->GetCueIndex(cueName);
				if (cueNum != XACTINDEX_INVALID)
				{
					cue = (*iter)->PrepareNewCueFromCueIndex(cueNum);
					cue->Set_CueName(cueName);
					break;

				}
			}

			if (cueNum == XACTINDEX_INVALID)
			{
				throw SingularityException("Unable to load a cue with the provided XACT friendly name.");
				return NULL; // nothing found, throw an exception!
			}

			cue->Initialize(isLooping, is3d);
			return cue;
		}

		// Returns the AudioListener.
		AudioListener* AudioManager::GetSingleListener()
		{
			// If we don't have one, we need one.
			if (m_pListener == NULL)
			{
				m_pListener = new AudioListener("Listener");
				m_pListener->Initialize();
			}
			return m_pListener;

		}

		// Calculates the 3d positional data for the sound.
		void AudioManager::Calculate3dPosition(AudioEmitter* emit, AudioListener* listener)
		{
			//emit->GetCue()->Apply3dCalculations(m_pEngine->CalculateDSP(emit, listener));
			m_pEngine->CalculateDSP(emit, listener);
		}

		// Pauses/unpauses the engine. (Toggle.)
		void AudioManager::PauseEngine()
		{
			m_pEngine->PauseEngine();
		}

		// Pauses/unpauses the engine. (Manual.)
		void AudioManager::PauseEngine(bool becomePaused)
		{
			m_pEngine->PauseEngine(becomePaused);
		}

		// Mutes/unmutes the engine. (Toggle.)
		void AudioManager::MuteEngine()
		{
			m_pEngine->MuteEngine();
		}

		// Mutes/unmutes the engine. (Manual.)
		void AudioManager::MuteEngine(bool becomeMuted)
		{
			m_pEngine->MuteEngine(becomeMuted);
		}

		// Stops all cues that are currently playing.
		void AudioManager::StopAll()
		{
			m_pEngine->StopAll();
		}

		// Sets the volume for a particular catagory.
		void AudioManager::SetVolume(string category, float volume)
		{
			m_pEngine->SetVolume(category, volume);
		}

		#pragma endregion

		#pragma region Static Methods

		// Returns the single instance of the AudioManager.
		AudioManager* AudioManager::Instantiate()
		{
			if(!AudioManager::g_pInstance)
				AudioManager::g_pInstance = new AudioManager();
			return AudioManager::g_pInstance;
		}

		#pragma endregion

	}
}