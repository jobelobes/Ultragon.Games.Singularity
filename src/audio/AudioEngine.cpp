#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{
		#pragma region Constructors and Finalizers

		// Constructor.
		AudioEngine::AudioEngine()
		{
			m_bInitialized = false;
			m_bIsMuted = false;
			m_bIsPaused = false;
			m_pEngine = NULL;

			// One of many ways to initialize the struct to all 0x00000000.
			ZeroMemory( &m_defaultDsp, sizeof( X3DAUDIO_DSP_SETTINGS ) );
		}

		// Destructor.
		AudioEngine::~AudioEngine()
		{
			CleanupXACT();
			if (m_pEngine != NULL)
			{
				m_pEngine->ShutDown();
				m_pEngine->Release();
				delete m_pEngine;
				m_pEngine = NULL;
			}
			//CoUninitialize();
		}

		#pragma endregion

		#pragma region Methods

		// Cleans up unused data in the audio system.
		void AudioEngine::CleanupXACT()
		{
			
			// Remove everything we don't care about right now. Garbage collect.
		}

		// Initializes the AudioEngine.
		void AudioEngine::Initialize()
		{
			if (m_pEngine == NULL)
				throw SingularityException("Must load in an audio engine before you can initialize.");

			m_bInitialized = true;
			// Necessary for 3d audio.
			XACT3DInitialize(m_pEngine, m_x3d);
			


			WAVEFORMATEXTENSIBLE format;
			m_pEngine->GetFinalMixFormat(&format);

			m_defaultDsp.SrcChannelCount = 1;
			m_defaultDsp.DstChannelCount = format.Format.nChannels;
			m_defaultDsp.pMatrixCoefficients = new FLOAT32[m_defaultDsp.SrcChannelCount * m_defaultDsp.DstChannelCount];
		}

		// Loads in the AudioEngine's global settings. (*.xgs)
		void AudioEngine::LoadEngine(string path)
		{
			if (m_pEngine == NULL)
			{
				HANDLE hFile;
				DWORD dwBytesRead;
				VOID* pGlobalSettingsData = NULL;
				DWORD dwGlobalSettingsFileSize = 0;
				bool bSuccess = false;
				IXACT3Engine* engine;

				hFile = CreateFile(path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
				if (hFile)
				{
					dwGlobalSettingsFileSize = GetFileSize(hFile, NULL);
					if (dwGlobalSettingsFileSize != INVALID_FILE_SIZE)
					{
						pGlobalSettingsData = CoTaskMemAlloc(dwGlobalSettingsFileSize);
						if(pGlobalSettingsData)
						{
							if(0 != ReadFile(hFile, pGlobalSettingsData, dwGlobalSettingsFileSize, &dwBytesRead, NULL))
							{
								bSuccess = true;
							}
						}
					}
				}
				if (!bSuccess)
				{
					if (pGlobalSettingsData)
					{
						CoTaskMemFree(pGlobalSettingsData);
					}
					pGlobalSettingsData = NULL;
					dwGlobalSettingsFileSize = 0;
					throw SingularityException("Invalid path provided to \"CreateEngine\".");
				}
				
				XACT3CreateEngine(0, &engine);

				XACT_RUNTIME_PARAMETERS xrParams = {0};
				xrParams.pGlobalSettingsBuffer = pGlobalSettingsData;
				xrParams.globalSettingsBufferSize = dwGlobalSettingsFileSize;
				xrParams.globalSettingsFlags = XACT_FLAG_GLOBAL_SETTINGS_MANAGEDATA; // this will tell XACT to delete[] the buffer when its unneeded
				//xrParams.fnNotificationCallback = XACTNotificationCallback;
				xrParams.lookAheadTime = XACT_ENGINE_LOOKAHEAD_DEFAULT;

				engine->Initialize( &xrParams );

				m_pEngine = engine;
			}		
		}

		// Loads a wavebank into memory. (*.xwb)
		WaveBank* AudioEngine::LoadWaveBankInMemory(string path)
		{
			// Loads in a .xwb into memory

			if (!m_bInitialized)
				throw SingularityException("Cannot load a wavebank without loading and initializing the engine.");

			HANDLE hFile;
			DWORD dwFileSize;
			HANDLE hMapFile;
			HRESULT hr;
			VOID* wavebankData;
			IXACT3WaveBank* wavebank;
			bool bSuccess = false;

			hFile = CreateFile(path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
			if (hFile != INVALID_HANDLE_VALUE)
			{
				dwFileSize = GetFileSize( hFile, NULL);
				if (dwFileSize != -1)
				{
					hMapFile = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, dwFileSize, NULL);
					if (hMapFile)
					{
						wavebankData = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, 0);
						{
							if (wavebankData)
							{
								hr = m_pEngine->CreateInMemoryWaveBank( wavebankData, dwFileSize, 0, 0, &wavebank);
								bSuccess = true;
							}
							CloseHandle(hMapFile); //wavebankData has this stuff still
						}
					}
				}
				CloseHandle(hFile); //wavebankData has this still
			}

			if (!bSuccess)
				throw SingularityException("Invalid path provided to \"LoadWaveBankInMemory\".");

			WaveBank* wb = new WaveBank(wavebank, wavebankData);

			return wb;
		}

		// Prepares a wavebank for streaming. (*.xwb)
		WaveBank* AudioEngine::LoadWaveBankForStreaming(string path)
		{
			// REDIRECTS. MUST BE FIXED.
			return LoadWaveBankInMemory(path);
		}

		// Loads a soundbank into memory. (*.xsb)
		SoundBank* AudioEngine::LoadSoundBank(string path)
		{
			if (!m_bInitialized)
				throw SingularityException("Cannot load a soundbank without loading and initializing the engine.");
						// Inspired and partially borrowed from DirectX examples

			HANDLE hFile;
			DWORD dwFileSize;
			HRESULT hr;
			DWORD dwBytesRead;
			VOID* soundbankData;
			IXACT3SoundBank* soundbank;
			bool bSuccess = false;

			hFile = CreateFile( path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
			if (hFile != INVALID_HANDLE_VALUE)
			{
				dwFileSize = GetFileSize( hFile, NULL);
				if (dwFileSize != -1)
				{
					soundbankData = new BYTE[dwFileSize];
					if (soundbankData)
					{
						if (0 != ReadFile(hFile, soundbankData, dwFileSize, &dwBytesRead, NULL))
						{
							hr = m_pEngine->CreateSoundBank(soundbankData, dwFileSize, 0, 0, &soundbank);
							bSuccess = true;
						}
					}
				}
				CloseHandle(hFile); // all of this information is in soundbankData/
			}

			if (!bSuccess)
				throw SingularityException("Invalid path provided to \"LoadSoundBank\".");

			SoundBank* sb = new SoundBank(soundbank, soundbankData);

			return sb;
		}

		// Updates the engine.
		void AudioEngine::UpdateEngine()
		{
			m_pEngine->DoWork();
		}

		// Pauses/unpauses the engine. (Toggle)
		void AudioEngine::PauseEngine()
		{
			if (m_bIsPaused)
			{
				m_pEngine->Pause(0, false);
				m_bIsPaused = false;
			}
			else
			{
				m_pEngine->Pause(0, true);
				m_bIsPaused = true;
			}
		}

		// Pauses/unpauses the engine. (Manual)
		void AudioEngine::PauseEngine(bool becomePaused)
		{
			if (becomePaused)
			{
				m_pEngine->Pause(0, true);
				m_bIsPaused = true;
			}
			else
			{
				m_pEngine->Pause(0, false);
				m_bIsPaused = false;
			}
		}

		// Mutes/unmutes the engine. (Toggle)
		void AudioEngine::MuteEngine()
		{
			if (m_bIsMuted)
			{
				m_pEngine->SetVolume(0, 1.0f);
				m_bIsMuted = false;
			}
			else
			{
				m_pEngine->SetVolume(0, 0.0f);
				m_bIsMuted = true;
			}
		}

		// Mutes/unmutes the engine (Manual)
		void AudioEngine::MuteEngine(bool becomeMuted)
		{
			if (becomeMuted)
			{
				m_pEngine->SetVolume(0, 0.0f);
				m_bIsMuted = true;
			}
			else
			{
				m_pEngine->SetVolume(0, 1.0f);
				m_bIsMuted = false;
			}
		}

		// Stops all currently playing cues.
		void AudioEngine::StopAll()
		{
			m_pEngine->Stop(0, XACT_FLAG_STOP_IMMEDIATE);
		}

		// Sets the master volume for the engine. (0.0f - 2.0f; 1.0f default)
		void AudioEngine::SetMasterVolume(float volume)
		{
			m_pEngine->SetVolume(0, volume);
		}

		// Sets the volume for a particular category.
		void AudioEngine::SetVolume(string category, float volume)
		{
			m_pEngine->SetVolume(m_pEngine->GetCategory(category.c_str()), volume);
		}

		// Calculates the 3d positional data for an AudioEmitter.
		X3DAUDIO_DSP_SETTINGS AudioEngine::CalculateDSP(AudioEmitter* emit, AudioListener* listener)
		{
			
			bool calculated = false;
			Cue* cue;

			for (int i = 0; i < emit->Get_NumberOfCues(); i++)
			{
				cue = emit->Get_Cue(i);
				if (cue != NULL)
				{
					if (cue->Get_Is3d() && cue->Get_IsPlaying())
					{
						if (!calculated)
						XACT3DCalculate(m_x3d, &(listener->GetX3dListener()), &(emit->GetX3dEmitter()), &m_defaultDsp);
						//m_defaultDsp.EmitterToListenerAngle = D3DXVec3Dot(&listener->Get_GameObject()->Get_Transform()->Get_Position(), &emit->Get_GameObject()->Get_Transform()->Get_Position());
						//m_defaultDsp.EmitterToListenerAngle
						calculated = true;
						// because you're a pain, xact,
						Vector3 cross;
						//D3DXVec3Cross(&cross, Vector3(listener->Get_GameObject()->Get_Parent()->Get_Transform()->Get_Rotation(), Vector2(0,1,0));
						cross = Vector3(listener->GetX3dListener().OrientFront.x, listener->GetX3dListener().OrientFront.y, listener->GetX3dListener().OrientFront.z).cross(Vector3(listener->GetX3dListener().OrientTop.x, listener->GetX3dListener().OrientTop.y, listener->GetX3dListener().OrientTop.z));
						Vector3 emittolisten = Vector3(emit->GetX3dEmitter().Position.x, emit->GetX3dEmitter().Position.y, emit->GetX3dEmitter().Position.z) - Vector3(listener->GetX3dListener().Position.x, listener->GetX3dListener().Position.y, listener->GetX3dListener().Position.z);
						float pan = emittolisten.dot(cross);
//					float pan = D3DXVec
//						float panSides[2] = {0, 1};
//						m_defaultDsp.pMatrixCoefficients = panSides;
						cue->Apply3dCalculations(m_defaultDsp);
						int a = 0;
					}
				}
			}
			return m_defaultDsp;
		}

		#pragma endregion

	}
}