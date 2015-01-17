#include "audio\Singularity.Audio.h"

/*
* Cue.h
*
* An object allowing access to a single individual sound playing. 3d cue position is handled through AudioEmitters and AudioListeners.
*
* Author: Sela Davis
*
* Created: March 15, 2010 (03/15/10)
* Last modified: March 17, 2010 (03/17/10)
*/

namespace Singularity
{
	namespace Audio
	{
		class Cue
		{
			private:
			
			#pragma region Variables

				// The XACT representation of the cue.
				IXACT3Cue* m_pCue;

				// The XACT index.
				XACTINDEX m_index;

				// The name of the cue.
				String m_cueName;

				// Whether or not the cue is playing.
				bool m_bIsPlaying;

				// Whether or not the cue is paused.
				bool m_bIsPaused;

				// Whether or not the cue is looping.
				bool m_bIsLooping;

				// Whether or not the cue is 3d.
				bool m_bIs3d;

				// A pointer to the soundbank used for this cue.
				SoundBank* m_pSoundBank;

				// The cue's DSP settings.
				X3DAUDIO_DSP_SETTINGS m_dsp;

				// The current state of the cue. (Playing, etc.)
				DWORD m_state;

				// The volume percentage.
				float m_fVolumePercent;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				Cue(SoundBank* soundbank, IXACT3Cue* cue, int index, String cueName = "");

				// Destructor.
				~Cue();

			#pragma endregion

			#pragma region Methods

				// Initializes the cue.
				void Initialize(bool isLooping, bool is3d);

				// Updates the cue's state variables.
				void UpdateState();

				// Applies the 3d positional calculations to the cue.
				void Apply3dCalculations(X3DAUDIO_DSP_SETTINGS dsp);

				// Resets and reprepares the cue.
				void ResetCue();

				// Plays the cue.
				void PlayCue();

				// Pauses/unpauses the cue. (Toggle)
				void PauseCue();

				// Pauses/unpauses the cue. (Manual)
				void PauseCue(bool becomePaused);

				// Stops the cue.
				void Stop();

			#pragma endregion

			#pragma region Properties

				// Sets the current volume percentage (0-100)
				void Set_VolumePercentage(float vol);

				// Sets the cue's name.
				void Set_CueName(String name);

				// Returns the current volume percentage (0-100)
				float Get_VolumePercentage();

				// Returns the XACT index for this cue.
				XACTINDEX Get_Index();

				// Returns the XACT friendly name for this cue.
				string Get_CueName();

				// Whether or not the cue is playing.
				bool Get_IsPlaying();

				// Whether or not the cue is paused.
				bool Get_IsPaused();

				// Whether or not the cue is looping.
				bool Get_IsLooping();

				// Whether or no the cue is 3d positional.
				bool Get_Is3d();

			#pragma endregion
		};
	}
}