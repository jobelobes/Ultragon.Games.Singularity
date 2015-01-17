#include "audio\Singularity.Audio.h"

/*
* AudioEmitter.h
*
* A Component for a GameObject that emits a positional sound.
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
		class AudioEmitter : public Singularity::Components::Component
		{

			DECLARE_OBJECT_TYPE;

			private:

			#pragma region Variables

				// Whether or not the AudioEmitter is initialized.
				bool m_bInitialized;

				// Whether or not we need to offset from the parent object's position. Affects ALL CUES.
				bool m_bUseOffset;

				// The distance of the AudioEmitter from the GameObject it is attached to.
				Vector3 m_offset;

				// The direction in which the offset is applied.
				Vector3 m_offsetDirection;

				// The cue associated with the AudioEmitter.
				DynamicList<Cue*> m_pCues;

				// The X3DAudio emitter struct.
				X3DAUDIO_EMITTER m_emitter;

				//bool m_bActive; // active: is it attached to something right now or stored for reuse / removal?
			#pragma endregion

			public:

			#pragma region Constructors and Finalizers
				
				// Constructor. Takes a name representing the emitter.
				AudioEmitter(String name);

				// Destructor.
				~AudioEmitter();
			#pragma endregion

				#pragma region Overriden Methods

				// Called whenever this component is added to a GameObject.
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);

				// Called whenever this component is removed from a GameObject.
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				
				#pragma endregion

			#pragma region Methods

				// Initializes the AudioEmitter with a cue.
				//void Initialize(Cue* cue);

				// Plays the cue associated with the AudioEmitter using the sound designer's preset properties.
				void Play(int index);

				// Pauses or unpauses the cue. (Toggle.)
				void Pause(int index);

				// Pauses or unpauses the cue. (Manual.)
				void Pause(int index, bool becomePaused);

				// Stops the cue and reprepares it for playback.
				void Stop(int index);

				// Updates the state of the cue.
				void UpdateState(int index);

				// Calculates 3d positional information for the cues.
				void CalculateDSP(AudioListener* listener);

				// Sets the offset and direction of the offset.
				void Set_Offset(Vector3 offset, Vector3 offsetDirection);

				void AddCue(Cue* cue);

			#pragma endregion

			#pragma region Properties

				// The position (with offset) of the emitter.
				//Vector3 Get_EmitterPosition();

				// Whether or not the cue is playing.
				bool Get_IsPlaying(int index);

				// Whether or not the cue is paused.
				bool Get_IsPaused(int index);

				// Whether or not the cue is looping.
				bool Get_IsLooping(int index);

				// Whether or not the cue is positioned in 3d space.
				bool Get_Is3dPositional(int index);

				// The number of cues on the AudioEmitter
				int Get_NumberOfCues();

				// Returns a Cue object associated with the AudioEmitter component.
				Cue* Get_Cue(int index);

				// Returns the emitter's index of a cue attached to this emitter.
				int Get_EmitterCueIndex(string xactFriendlyName);

				// Returns the X3DAudio emitter. Used to calculate DSP.
				X3DAUDIO_EMITTER GetX3dEmitter();

			#pragma endregion
		};
	}
}