#include "audio\Singularity.Audio.h"

/*
* AudioEngine.h
*
* Provides access to the XACT audioengine class. Handles the loading of all audio files into memory.
*
* Author: Sela Davis
*
* Created: March 15, 2010 (03/15/10)
* Last modified: March 20, 2010 (03/20/10)
*/

namespace Singularity
{
	namespace Audio
	{
		class AudioEngine
		{

			private:

			#pragma region Variables

				// Whether or not the AudioEngine is initialized.
				bool m_bInitialized;

				// Whether or not the AudioEngine is muted.
				bool m_bIsMuted;

				// Whether or not the AudioEngine is paused.
				bool m_bIsPaused;

				// The XACT representation of the AudioEngine.
				IXACT3Engine* m_pEngine;

				// The X3DAudio representation of the AudioEngine.
				X3DAUDIO_HANDLE m_x3d;

				// The default X3DAudio DSP struct.
				X3DAUDIO_DSP_SETTINGS m_defaultDsp;


			#pragma endregion

			public:

			#pragma region Constructors and Finalizers
				
				// Constructor.
				AudioEngine();

				// Destructor.
				~AudioEngine();

			#pragma endregion

			#pragma region Methods

				// Cleans up unused data in the audio system.
				void CleanupXACT();

				// Initializes the AudioEngine.
				void Initialize();

				// Loads in the AudioEngine's global settings. (*.xgs)
				void LoadEngine(string path);

				// Loads a wavebank into memory. (*.xwb)
				WaveBank* LoadWaveBankInMemory(string path);

				// Prepares a wavebank for streaming. (*.xwb)
				WaveBank* LoadWaveBankForStreaming(string path);

				// Loads a soundbank into memory. (*.xsb)
				SoundBank* LoadSoundBank(string path);

				// Updates the engine.
				void UpdateEngine();

				// Pauses/unpauses the engine. (Toggle)
				void PauseEngine();

				// Pauses/unpauses the engine. (Manual)
				void PauseEngine(bool becomePaused);

				// Mutes/unmutes the engine. (Toggle)
				void MuteEngine();

				// Mutes/unmutes the engine (Manual)
				void MuteEngine(bool becomeMuted);

				// Stops all currently playing cues.
				void StopAll();

				// Sets the master volume for the engine. (0.0f - 2.0f; 1.0f default)
				void SetMasterVolume(float volume);

				// Sets the volume for a particular category.
				void SetVolume(string category, float volume);

				// Calculates the 3d positional data for an AudioEmitter.
				X3DAUDIO_DSP_SETTINGS CalculateDSP(AudioEmitter* emit, AudioListener* listener);

			#pragma endregion
		};
	}
}