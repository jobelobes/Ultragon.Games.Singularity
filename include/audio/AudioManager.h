#include "audio\Singularity.Audio.h"

/*
* AudioManager.h
*
* Main public interface to playing audio. All SFX should be played through here. All ADAPTIVE music
* should be played automagically through the AdaptiveMusicManager instead.
*
* Loading files takes place through here. New emitters, listener (ONLY ONE), soundbanks, wavebanks,
* etc. all go through here.
*
* Author: Sela Davis
*
* Created: March 15, 2010 (03/15/10)
* Last modified: March 15, 2010 (03/15/10)
*/

namespace Singularity
{
	namespace Audio
	{
		class AudioManager
		{

			private:

				#pragma region Static Variables

				// The single instance of the AudioManager.
				static AudioManager* g_pInstance;

				#pragma endregion

			#pragma region Variables

				// Whether or not the AudioManager is initialized.
				bool m_bInitialized;
				
				// The AudioEngine used for audio playback.
				AudioEngine* m_pEngine;

				// A list of SoundBanks.
				DynamicList<SoundBank*> m_pSoundBanks;

				// A list of WaveBanks.
				DynamicList<WaveBank*> m_pWaveBanks;

				// A list of Cues.
				DynamicList<Cue*> m_pCues; // This just happens to be the best place to keep track of them.

				// A list of AudioEmitters.
				DynamicList<AudioEmitter*> m_pEmitters;

				// The single AudioListener.
				AudioListener* m_pListener; // Singleton, much like the Highlander.

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				AudioManager();

				// Destructor.
				~AudioManager();

			#pragma endregion

			#pragma region Methods

				// Updates the engine.
				void UpdateEngine();

				// Cleans up any extraneous "stuff".
				void CleanUp();

				// Tests audio playback. MUST BE REMOVED FOR FINAL IMPLEMENTATION.
				void TestEngine(); //TODO: remove for release

				// Initializes the AudioManager.
				void Initialize();

				// Loads in a wavebank from a file. (*.xwb)
				WaveBank* LoadWaveBank(string path);

				// Streams a wavebank from a file. (*.xwb)
				WaveBank* LoadStreamingWaveBank(string path);

				// Loads in a soundbank from a file. (*.xsb)
				SoundBank* LoadSoundBank(string path);

				// Creates the AudioEngine and applies its global settings from a file. (*.xgs)
				void CreateEngine(string path);

				// Creates and returns an AudioEmitter object.
				AudioEmitter* GetNewEmitter(string cueName);

				// Returns the AudioListener.
				AudioListener* GetSingleListener();

				// Calculates the 3d positional data for the sound.
				void Calculate3dPosition(AudioEmitter* emit, AudioListener* listener);

				// Creates and returns a cue using a provided and predetermined cue name.
				// A cue is a SINGLE INSTANCE of a sound.
				Cue* CreateCue(string cueName, bool isLooping = false, bool is3d = false);
				
				// Pauses/unpauses the engine. (Toggle.)
				void PauseEngine();

				// Pauses/unpauses the engine. (Manual.)
				void PauseEngine(bool becomePaused);

				// Mutes/unmutes the engine. (Toggle.)
				void MuteEngine();

				// Mutes/unmutes the engine. (Manual.)
				void MuteEngine(bool becomeMuted);

				// Stops all cues that are currently playing.
				void StopAll();

				// Sets the volume for a particular category.
				void SetVolume(string category, float volume);

			#pragma endregion

				#pragma region Static Methods

				// Returns the single instance of the AudioManager.
				static AudioManager* Instantiate();

				#pragma endregion

			#pragma region Properties
				
			#pragma endregion
		};
	}
}