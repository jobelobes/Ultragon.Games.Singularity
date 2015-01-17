#include "audio\Singularity.Audio.h"

/*
* SoundBank.h
*
* A wrapper for an XACT SoundBank. Cue information is acquired from soundbanks.
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
		class SoundBank
		{
			private:

			#pragma region Variables

				// The XACT soundbank.
				IXACT3SoundBank* m_pSoundBank;

				// The data for the XACT soundbank.
				VOID* m_pSoundBankData; // for a clean delete; we don't want this lost in memory.

				// The filepath to the XACT soundbank.
				string m_bPath; // the filepath to the object so we can tell if it's already loaded.

				// Whether or not the soundbank is active.
				bool m_bActive;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				SoundBank(IXACT3SoundBank* soundbank, VOID* soundbankData);

				// Destructor.
				~SoundBank();

			#pragma endregion

			#pragma region Methods

				// Returns a cue index from a supplied XACT friendly name.
				int GetCueIndex(string friendlyName);

				// Prepares and returns a new cue from an index.
				Cue* PrepareNewCueFromCueIndex(int index); // the Cue object will need to be played.

				// Reprepares a cue without creating a new instance.
				void PrepareCurrentCue(int index, IXACT3Cue** cue);

			#pragma endregion

		};
	}
}