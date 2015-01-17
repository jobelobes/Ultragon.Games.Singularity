#include "audio\Singularity.Audio.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Audio
	{
		class AudioExtension : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				
				// The single instance of the AudioExtension.
				static AudioExtension* g_pInstance;

				#pragma endregion

				#pragma region Variables
				
				// The lock for the extension.
				CriticalSection				m_kLock;

				// The timer for the extension.
				Timer						m_kTimer;

				// A list of emitters.
				DynamicList<AudioEmitter*> m_pEmitters;
				
				// The AudioListener used for 3d calculations.
				AudioListener* m_pListener;
				
				#pragma endregion

				#pragma region Constructors and Finalizers

				// Constructor.
				AudioExtension();

				#pragma endregion

				#pragma region Methods

				// Registers an AudioEmitter.
				void RegisterEmitter(AudioEmitter* emitter);

				// Unregisters an AudioEmitter.
				void UnregisterEmitter(AudioEmitter* emitter);

				// Registers an AudioListener.
				void RegisterListener(AudioListener* listener);

				// Unregisters an AudioListener.
				void UnregisterListener(AudioListener* listener);

				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnInitialize();
				virtual void OnExecute();
				virtual void OnComplete() { };
				virtual void OnUninitialize() { };
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				
				// Destructor.
				~AudioExtension();

				#pragma endregion

				#pragma region Static Methods

				// Returns a pointer to the AudioExtension.
				static AudioExtension* Instantiate();

				#pragma endregion

				friend class AudioEmitter;
				friend class AudioListener;
				friend class AudioManager;
		};
	}
}