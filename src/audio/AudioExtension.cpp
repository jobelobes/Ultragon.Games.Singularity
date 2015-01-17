#include "audio\Singularity.Audio.h"
 
using namespace Singularity;
using namespace Singularity::Threading;
using namespace Singularity::Components;
 
namespace Singularity
{
	namespace Audio
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Audio, AudioExtension, Singularity::Threading::Task);

		#pragma region Static Variables
		
		// The single instance of the AudioExtension.
		AudioExtension* AudioExtension::g_pInstance = NULL; 

		#pragma endregion

		#pragma region Constructors and Finalizers

		// Constructor.
		AudioExtension::AudioExtension() 
			: Singularity::Threading::Task("Audio Extension")
		{
			unsigned index = 0;
			m_pListener = NULL;

			this->Set_Frequency(1 / 60.0f);

		}
		#pragma endregion

		#pragma region Methods

		// Registers an AudioEmitter.
		void AudioExtension::RegisterEmitter(AudioEmitter* emit)
		{
			if(emit == NULL)
				throw SingularityException("\"emit\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				this->m_pEmitters.push_back(emit);
			}
		}

		// Unregisters an AudioEmitter.
		void AudioExtension::UnregisterEmitter(AudioEmitter* emit)
		{
			unsigned index, count;

			if(emit == NULL)
				throw SingularityException("\"emit\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				count = this->m_pEmitters.size();
				for(index = 0; index < count; ++index)
				{
					if(this->m_pEmitters[index] == emit)
					{
						this->m_pEmitters[index] = this->m_pEmitters[count - 1];
						this->m_pEmitters.pop_back();
					}
				}
			}
		}

		// Registers an AudioListener.
		void AudioExtension::RegisterListener(AudioListener* listener)
		{
			if (listener == NULL)
				throw SingularityException("\"listener\" cannot be null or empty.");
			
			Autolock(this->m_kLock)
			{
				this->m_pListener = listener;
			}
		}

		// Unregisters an AudioListener.
		void AudioExtension::UnregisterListener(AudioListener* listener)
		{
			Autolock(this->m_kLock)
			{
				m_pListener = NULL;
				for (int i = 0; i < m_pEmitters.size(); i++)
				{
					m_pEmitters[i]->Stop(i);
				}
			}
		}

		#pragma endregion
			
		#pragma region Overriden Methods
		void AudioExtension::OnInitialize()
		{
			this->m_kTimer.Reset();
			this->m_kTimer.Tick();
		}

		void AudioExtension::OnExecute()
		{

			// Updates all of the emitters.

			if (m_pListener != NULL)
				m_pListener->UpdateState();

			Autolock(this->m_kLock) // just in case this is some sort of wacky threading issue
			{
				for (DynamicList<AudioEmitter*>::iterator iter = m_pEmitters.begin(); iter != m_pEmitters.end(); iter++)
				{
					// We always update state.
					for (int i = 0; i < (*iter)->Get_NumberOfCues(); i++)
					{
						(*iter)->UpdateState(i);
					}

					//if ((*iter)->IsPlaying() && (*iter)->Is3dPositional())
					
					if (m_pListener != NULL)
					{
						// We calculate 3d positional data when necessary.
						(*iter)->CalculateDSP(m_pListener);
					}
					
				}
			}

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods

		// Returns a pointer to the AudioExtension.
		AudioExtension* AudioExtension::Instantiate()
		{
			if(!AudioExtension::g_pInstance)
				AudioExtension::g_pInstance = new AudioExtension();
			return AudioExtension::g_pInstance;
		}

		#pragma endregion
	}
}