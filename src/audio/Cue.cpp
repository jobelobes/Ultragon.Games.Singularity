#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{

		#pragma region Constructors and Finalizers
			
			// Constructor.
			Cue::Cue(SoundBank* soundbank, IXACT3Cue* cue, int index, string cueName) : m_pSoundBank(soundbank), m_pCue(cue), m_index(index), m_bIsPaused(false), m_bIsPlaying(false), m_bIsLooping(false), m_fVolumePercent(100.0f), m_cueName(cueName)
			{
				// Looping is defined IN THE XACT SOFTWARE
				m_pCue->GetState(&m_state);
				X3DAUDIO_DSP_SETTINGS dsp = {0};
				m_dsp = dsp;
			}

			// Destructor.
			Cue::~Cue()
			{
				m_pSoundBank = NULL; // we don't need it anymore, but it still needs to exist
				if (m_pCue != NULL)
				{
					m_pCue->Destroy();
					m_pCue = NULL;
				}
			}

		#pragma endregion

		#pragma region Methods

			// Initializes the cue.
			void Cue::Initialize(bool isLooping, bool is3d)
			{
				this->m_bIsLooping = isLooping;
				this->m_bIs3d = is3d;
				UpdateState();
			}

			// Updates the cue's state variables.
			void Cue::UpdateState()
			{

				// See if we're still playing.
				// If not, reprepare the cue.

				m_pCue->GetState(&m_state);

				//if (m_state & XACT_CUESTATE_PREPARED)
				//{
				//	m_bIsPrepared = true;
				//}
				//else
				//{
				//	m_bIsPrepared = false;
				//}

				if (m_state & XACT_CUESTATE_PLAYING)
				{
					m_bIsPlaying = true;
				}
				else
				{
					m_bIsPlaying = false;
				}

				// Reprepare.

				if (m_state & XACT_CUESTATE_STOPPED)
				{
					ResetCue();
				}
			}

			// Applies the 3d positional calculations to the cue.
			void Cue::Apply3dCalculations(X3DAUDIO_DSP_SETTINGS dsp)
			{
				XACT3DApply(&dsp, m_pCue);
				//LPXACT_CUE_INSTANCE_PROPERTIES prop;
				//m_pCue->GetProperties(&prop);
				//int a = 0;
				
				//m_pCue->SetMatrixCoefficients(1, 2, pan);
			}

			// Resets and reprepares the cue.
			void Cue::ResetCue()
			{
				m_pSoundBank->PrepareCurrentCue(m_index, &m_pCue);
				//soundbank prepares cue, give it cue object
			}

			// Plays the cue.
			void Cue::PlayCue()
			{
				//Stop();
				//ResetCue();
				//if (this->
				UpdateState();
				if (this->m_bIsPlaying)
				{
					this->Stop();
					//this->ResetCue();
				}
				
				m_pCue->Play();
			}

			// Pauses/unpauses the cue. (Toggle)
			void Cue::PauseCue()
			{
				if (m_bIsPaused == true)
				{
					m_pCue->Pause(false);
					m_bIsPaused = false;
				}
				else
				{
					m_pCue->Pause(true);
					m_bIsPaused = true;
				}
			}

			// Pauses/unpauses the cue. (Manual)
			void Cue::PauseCue(bool becomePaused)
			{
				m_pCue->Pause(becomePaused);
				m_bIsPaused = becomePaused;
			}

			// Stops the cue.
			void Cue::Stop()
			{
				m_pCue->Stop(XACT_FLAG_STOP_IMMEDIATE);
				// the cue must now be reprepared!
				ResetCue();
			}

		#pragma endregion

		#pragma region Properties


			// Returns the current volume percentage (0-100)
			float Cue::Get_VolumePercentage()
			{
				return m_fVolumePercent;
			}

			// Sets the current volume percentage (0-100)
			void Cue::Set_VolumePercentage(float vol)
			{
				if (vol > 100.0f)
				{
					vol = 100.0f;
				}
				if (vol < 0.0f)
				{
					vol = 0.0f;
				}

				m_fVolumePercent = vol; // this way we don't have to spend time and cycles in XACT.

				int index = m_pCue->GetVariableIndex("Volume");
				if (index == XACTENGINE_E_INVALIDVARIABLEINDEX)
				{
					throw SingularityException("Cue does not have a custom \"Volume\" parameter defined.");
				}
					m_pCue->SetVariable(index, vol);
				
			}

			XACTINDEX Cue::Get_Index()
			{
				return m_index;
			}

			bool Cue::Get_IsPlaying()
			{
				return m_bIsPlaying;
			}

			bool Cue::Get_IsPaused()
			{
				return m_bIsPaused;
			}

			bool Cue::Get_IsLooping()
			{
				return m_bIsLooping;
			}

			bool Cue::Get_Is3d()
			{
				return m_bIs3d;
			}

			void Cue::Set_CueName(String name)
			{
				m_cueName = name;
			}

			String Cue::Get_CueName()
			{
				return m_cueName;
			}

		#pragma endregion
	}
}