#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{
		#pragma region Constructors and Finalizers

			WaveBank::WaveBank(IXACT3WaveBank* waveBank, VOID* waveBankData)
			{
				m_pWaveBank = waveBank;
				m_pWaveBankData = waveBankData;
			}

			WaveBank::~WaveBank()
			{
				if (m_pWaveBank != NULL)
				{
					m_pWaveBank->Destroy();
					m_pWaveBank = NULL;
					UnmapViewOfFile(m_pWaveBankData);
				}
			}

		#pragma endregion
	}
}