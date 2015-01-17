#include "audio\Singularity.Audio.h"

/*
* AudioListener.h
*
* A Component for a Player that listens to positional sound.
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
		class AudioListener : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			private:

			#pragma region Variables
				
				// Whether or not the AudioListener is active.
				bool m_bActive;

				// The name of the AudioListener.
				string m_name;

				// The offset distance of the AudioListener from the GameObject it is attached to.
				Vector3 m_offset;

				// The offset direction of the AudioListener from the GameObject it is attached to.
				Vector3 m_offsetDirection;

				// Lets us know whether or not we need to recalculate listener lookat.
				Quaternion m_previousRotation;

				// The X3DAudio struct for the listener.
				X3DAUDIO_LISTENER m_listener;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor. Takes in a name for the AudioListener.
				AudioListener(String name);

				// Destructor.
				~AudioListener();

			#pragma endregion

				#pragma region Overriden Methods

				// Called whenever this component is added to a GameObject.
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);

				// Called whenever this component is removed from a GameObject.
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);

				#pragma endregion

			#pragma region Methods

				// Initializes the AudioListener.
				void Initialize();

				// Sets the offset and the offset direction from the GameObject for the AudioListener.
				void SetOffset(Vector3 offset, Vector3 offsetDirection);

				// Updates the state of the AudioListener.
				void UpdateState();

			#pragma endregion

			#pragma region Properties

				// Returns the X3DAudio struct for the listener.
				X3DAUDIO_LISTENER GetX3dListener();

			#pragma endregion
		};
	}
}