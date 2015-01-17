#include "audio\Singularity.Audio.h"

/*
* SoundBank.h
*
* A wrapper for an XACT WaveBank. Represents the audio on the desk. Sits and looks pretty while
* the other classes do all the work. Pretty much just holds data. The AudioManager will keep
* track of all of the WaveBanks.
*
* Author: Sela Davis
*
* Created: March 15, 2010 (03/15/10)
* Last modified: March 16, 2010 (03/16/10)
*/

namespace Singularity
{
	namespace Audio
	{
		class WaveBank
		{
			private:

			#pragma region Variables

				// The XACT representation of a wavebank.
				IXACT3WaveBank* m_pWaveBank;

				// The data for an XACT wavebank.
				VOID* m_pWaveBankData; // so we don't lose track of it and can clean it up

				// The filepath for the wavebank.
				string m_bPath;

				// Whether or not the wavebank is active.
				bool m_bActive;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				WaveBank(IXACT3WaveBank* waveBank, VOID* waveBankData);

				// Destructor.
				~WaveBank();

			#pragma endregion

			#pragma region Methods
			#pragma endregion

			#pragma region Properties
			#pragma endregion
		};
	}
}