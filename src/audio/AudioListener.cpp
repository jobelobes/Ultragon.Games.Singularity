#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{			
		
		IMPLEMENT_OBJECT_TYPE(Singularity.Audio, AudioListener, Component);

		#pragma region Constructors and Finalizers

			// Constructor. Takes in a name for the AudioListener.
			AudioListener::AudioListener(String name) : Singularity::Components::Component(name)
			{
				m_name = name;
				m_offset = Vector3(0,0,0);
				m_offsetDirection = Vector3(0,0,0);
//			m_previousRotation = NULL;

				// One of many ways to zero out the memory for the struct.
				ZeroMemory( &m_listener, sizeof( X3DAUDIO_LISTENER ) );
			}

			// Destructor.
			AudioListener::~AudioListener()
			{
			}

		#pragma endregion

		#pragma region Overriden Methods
			
			// Called whenever this component is added to a GameObject.
			void AudioListener::OnComponentAdded(Singularity::Components::GameObject* gameObject)
			{
				Quaternion q = Get_GameObject()->Get_Transform()->Get_LocalRotation();

				m_listener.Position = (D3DXVECTOR3)Get_GameObject()->Get_Transform()->Get_Position();
				m_listener.Velocity = (D3DXVECTOR3)Vector3(0, 0, 0);
				m_listener.OrientFront = (D3DXVECTOR3)Vector3(q.x, q.y, q.z); // probably needs more testing...

				m_listener.OrientTop = (D3DXVECTOR3)Vector3(0, 1, 0);

				AudioExtension::Instantiate()->RegisterListener(this);
			}

			// Called whenever this component is removed from a GameObject.
			void AudioListener::OnComponentRemoved(Singularity::Components::GameObject* gameObject)
			{
				// clear out the position
				m_listener.Position = (D3DXVECTOR3)Vector3(0,0,0);
				m_listener.Velocity = (D3DXVECTOR3)Vector3(0,0,0);
				m_listener.OrientFront = (D3DXVECTOR3)Vector3(0,0,0);
				m_listener.OrientTop = (D3DXVECTOR3)Vector3(0,0,0);
				AudioExtension::Instantiate()->UnregisterListener(this);
			}

		#pragma endregion

		#pragma region Methods

			// Initializes the AudioListener.
			void AudioListener::Initialize()
			{

			}

			// Sets the offset and the offset direction from the GameObject for the AudioListener.
			void AudioListener::SetOffset(Vector3 offset, Vector3 offsetDirection)
			{
				m_offset = offset;
				m_offsetDirection = offsetDirection;
			}

			// Updates the state of the AudioListener.
			void AudioListener::UpdateState()
			{
				if (Get_GameObject() != NULL)
				{
					m_listener.Position = (D3DXVECTOR3)Get_GameObject()->Get_Transform()->Get_Position();
					//m_listener.OrientFront.x = Get_GameObject()->Get_Transform()->Get_Rotation().x;
					//m_listener.OrientFront.y = Get_GameObject()->Get_Transform()->Get_Rotation().y;
					//m_listener.OrientFront.z = Get_GameObject()->Get_Transform()->Get_Rotation().z+1;
				}

				//if (m_previousRotation != NULL)
				{
					Quaternion curRot;
					curRot = this->Get_GameObject()->Get_Transform()->Get_Rotation();
					if (m_previousRotation != curRot)
					{
						Quaternion vecRot, inverse, result;
						//curRot = this->Get_GameObject()->Get_Transform()->Get_Rotation();

						vecRot.x = 0.0f;
						vecRot.y = 0.0f;
						vecRot.z = 1.0f;
						vecRot.w = 0.0f;

						inverse = curRot.conjugate();

						result = curRot * vecRot * inverse;
						m_listener.OrientFront.x = result.x;
						m_listener.OrientFront.y = result.y;
						m_listener.OrientFront.z = result.z;
					}
				}

				// ew, this is a nasty hack.
				//Singularity::Graphics::Camera::Get_Current();
			}

		#pragma endregion

		#pragma region Properties

			// Returns the X3DAudio struct for the listener.
			X3DAUDIO_LISTENER AudioListener::GetX3dListener()
			{
				return m_listener;
			}

		#pragma endregion
	}
}