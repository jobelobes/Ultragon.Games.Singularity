#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{
		#pragma region Constructors and Finalizers

			SoundBank::SoundBank(IXACT3SoundBank* soundbank, VOID* soundbankData)
			{
				m_pSoundBank = soundbank;
				m_pSoundBankData = soundbankData;
			}

			SoundBank::~SoundBank()
			{
				if (m_pSoundBank != NULL)
				{
					m_pSoundBank->Destroy();
					m_pSoundBank = NULL;
					delete[] m_pSoundBankData;
				}
			}

		#pragma endregion

		#pragma region Methods

			int SoundBank::GetCueIndex(string friendlyName)
			{
				return m_pSoundBank->GetCueIndex(friendlyName.c_str());
			}

			Cue* SoundBank::PrepareNewCueFromCueIndex(int index)
			{
				Cue* cue;
				IXACT3Cue* xactCue;
				m_pSoundBank->Prepare(index, 0, 0, &xactCue);
				cue = new Cue(this, xactCue, index);
				return cue;
			}

			void SoundBank::PrepareCurrentCue(int index, IXACT3Cue** cue)
			{
				m_pSoundBank->Prepare(index, 0, 0, cue);
			}

		#pragma endregion
	}
}