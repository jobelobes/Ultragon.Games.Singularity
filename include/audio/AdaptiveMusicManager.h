#include "audio\Singularity.Audio.h"

/*
* AdaptiveMusicManager.h
*
* Handles all adaptive music. Loads in a given file and plays music based upon the information given by the AdaptiveMusicUpdater(s).
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
		class AdaptiveMusicManager
		{
			private:

				#pragma region Static Variables

				// The single instance of the AudioManager.
				static AdaptiveMusicManager* g_pInstance;

				#pragma endregion

				#pragma region Variables

				bool m_bIsPlaying;

				// A list of AdaptiveEnvironments.
				DynamicList<AdaptiveEnvironment*> m_pEnvironments; // we only keep a list so that we don't lose any that we want to keep loaded in

				// A list of Cues.
				DynamicList<Cue*> m_pCuesToPlay; // This just happens to be the best place to keep track of them.

				// The current environment to play.
				AdaptiveEnvironment* m_pCurrentEnvironment;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				AdaptiveMusicManager();

				// Destructor.
				~AdaptiveMusicManager();

			#pragma endregion

			#pragma region Methods

				// Registers an AudioEmitter.
				void AddEnvironment(AdaptiveEnvironment* envir);

				// Unregisters an AudioEmitter.
				//void RemoveEnvironment(AdaptiveEnvironment* envir);

				void SetCurrentEnvironment(String name);

				// Pauses/unpauses the engine. (Manual.)
				void Play();

				// Stops all cues that are currently playing.
				void StopAll();

				bool Get_IsPlaying();

				DynamicList<Cue*> GetCuesToPlay();

				void ClearCues();

				void SetVariable(String variable, float value);

			#pragma endregion

				#pragma region Static Methods

				// Returns the single instance of the AudioManager.
				static AdaptiveMusicManager* Instantiate();

				#pragma endregion

			#pragma region Properties
				
			#pragma endregion
		};
	}
}