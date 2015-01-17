#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{			

		IMPLEMENT_OBJECT_TYPE(Singularity.Audio, AudioEmitter, Component);

		#pragma region Constructors and Finalizers

			// Constructor. Takes a name representing the XACT name of the cue.
			AudioEmitter::AudioEmitter(String name) : Singularity::Components::Component(name), m_offset(Vector3()), m_offsetDirection(Vector3()), m_bUseOffset(false), m_bInitialized(false)
			{

				// One of many ways to zero out the struct info.
				ZeroMemory( &m_emitter, sizeof( X3DAUDIO_EMITTER ) );

			}

			// Destructor.
			AudioEmitter::~AudioEmitter()
			{
				// Right now we don't delete the cue -- the AudioManager does this. Frowney-face.
			}

		#pragma endregion

		#pragma region Overriden Methods
			
			// Called whenever this component is added to a GameObject.
			void AudioEmitter::OnComponentAdded(GameObject* gameObject)
			{
				// Set up all of the information for the emitter based upon the GameObject the component is attached to.
				
				Quaternion q = this->Get_GameObject()->Get_Transform()->Get_Rotation();

				m_emitter.pCone = NULL;
				m_emitter.OrientFront = (D3DXVECTOR3)Vector3(q.x, q.y, q.z);
				m_emitter.OrientTop = (D3DXVECTOR3)Vector3(0, 1, 0); //need a better way; up vector
				m_emitter.Position = (D3DXVECTOR3)Get_GameObject()->Get_Transform()->Get_Position();
				m_emitter.Velocity = (D3DXVECTOR3)Vector3(0, 0, 0); // this is for doppler...maybe we'll actually use this for fun and profit
				m_emitter.ChannelCount = 1; // we're not in stereo
				m_emitter.ChannelRadius = 0.0f; // set by calculate
				m_emitter.pChannelAzimuths = NULL; // set by calculate
				m_emitter.pVolumeCurve = NULL; // set by calculate
				m_emitter.pLFECurve = NULL; // set by calculate
				m_emitter.pLPFDirectCurve = NULL; // set by calculate
				m_emitter.pLPFReverbCurve = NULL;// set by calculate
				m_emitter.pReverbCurve = NULL; // set by calculate
				m_emitter.CurveDistanceScaler = 1.0;
				m_emitter.DopplerScaler = 1.0f;

				// Register with the AudioExtension so it can be updated.
				AudioExtension::Instantiate()->RegisterEmitter(this);

			}

			// Called whenever this component is removed from a GameObject.
			void AudioEmitter::OnComponentRemoved(GameObject* gameObject)
			{
				for (unsigned i = 0; i < this->m_pCues.size(); i++)
				{
					this->Stop(i);
				}
				AudioExtension::Instantiate()->UnregisterEmitter(this);
			}

		#pragma endregion


		#pragma region Methods

			// Initializes the AudioEmitter with a cue.
			//void AudioEmitter::Initialize(Cue* cue)
			//{
			//	m_pCue = cue;
			//	m_bInitialized = true;
			//}

			// Plays the cue associated with the AudioEmitter using the sound designer's preset properties.
			void AudioEmitter::Play(int index)
			{
				Cue* cue = m_pCues[index];
				// if we're playing and we call another play, stop and reset it?
				if (cue->Get_IsPlaying())
				{
					cue->ResetCue();
				}
				if (cue != NULL)
				{
					cue->PlayCue();
				}
			}

			// Pauses or unpauses the cue. (Toggle.)
			void AudioEmitter::Pause(int index)
			{
				if (m_pCues[index] != NULL)
				{
					m_pCues[index]->PauseCue();
				}
			}

			// Pauses or unpauses the cue. (Manual.)
			void AudioEmitter::Pause(int index, bool becomePaused)
			{
				if (m_pCues[index] != NULL)
				{
					m_pCues[index]->PauseCue(becomePaused);
				}
			}

			// Stops the cue and reprepares it for playback.
			void AudioEmitter::Stop(int index)
			{
				if (m_pCues[index] != NULL)
				{
					m_pCues[index]->Stop();
				}
			}

			// Updates the state of the cue.
			void AudioEmitter::UpdateState(int index)
			{
				if (this->Get_GameObject() != NULL)
					m_emitter.Position = (D3DXVECTOR3)this->Get_GameObject()->Get_Transform()->Get_Position();
				
				if (m_pCues[index] != NULL)
					m_pCues[index]->UpdateState();
			}

			// Calculates 3d positional information for the cue.
			void AudioEmitter::CalculateDSP(AudioListener* listener)
			{
				// Can't play anything without defining a listener and a cue.
				if ((listener != NULL))
				{
					if (Get_GameObject() != NULL)
					{
						m_emitter.Position = (D3DXVECTOR3)Get_GameObject()->Get_Transform()->Get_Position();
						if (m_bUseOffset)
						{
							m_emitter.Position.x += m_offset.x;
							m_emitter.Position.y += m_offset.y;
							m_emitter.Position.z += m_offset.z;
						}
					}

					AudioManager::Instantiate()->Calculate3dPosition(this, listener);
				}
			}

			// Sets the offset and direction of the offset.
			void AudioEmitter::Set_Offset(Vector3 offset, Vector3 offsetDirection)
			{
				m_offset = offset;
				m_offsetDirection = offsetDirection;
				m_bUseOffset = true;
			}


			void AudioEmitter::AddCue(Cue* cue)
			{
				if (cue != NULL)
				{
					m_pCues.push_back(cue);
				}
			}

		#pragma endregion

		#pragma region Properties

			int AudioEmitter::Get_NumberOfCues()
			{
				return this->m_pCues.size();
			}

			// Whether or not the cue is playing.
			bool AudioEmitter::Get_IsPlaying(int index)
			{
				if (m_pCues[index] != NULL)
					return m_pCues[index]->Get_IsPlaying();
				return false;
			}

			// Whether or not the cue is paused.
			bool AudioEmitter::Get_IsPaused(int index)
			{
				if (m_pCues[index] != NULL)
					return m_pCues[index]->Get_IsPaused();
				return false;
			}

			// Whether or not the cue is looping.
			bool AudioEmitter::Get_IsLooping(int index)
			{
				if (m_pCues[index] != NULL)
					return m_pCues[index]->Get_IsLooping();
				return false;
			}

			// Whether or not the cue is positioned in 3d space.
			bool AudioEmitter::Get_Is3dPositional(int index)
			{
				if (m_pCues[index] != NULL)
					return m_pCues[index]->Get_Is3d();
				return false;
			}

			// Returns the Cue object associated with the AudioEmitter component.
			Cue* AudioEmitter::Get_Cue(int index)
			{
				if (index < m_pCues.size() && m_pCues[index] != NULL)
					return m_pCues[index];
				else
					return NULL; // :/
			}

			// Returns the X3DAudio emitter. Used to calculate DSP.
			X3DAUDIO_EMITTER AudioEmitter::GetX3dEmitter()
			{
				return m_emitter;
			}

			int AudioEmitter::Get_EmitterCueIndex(string cueName)
			{
				for (DynamicList<Cue*>::iterator iter = m_pCues.begin(); iter != m_pCues.end(); iter++)
				{
					if ((*iter)->Get_CueName() == cueName)
					{
						return (*iter)->Get_Index();
					}
				}
				return XACTINDEX_INVALID; // not found :/
			}

		#pragma
	}
}