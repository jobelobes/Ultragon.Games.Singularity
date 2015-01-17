#include "audio\Singularity.Audio.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Audio
	{
		class AdaptiveAudioTask : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				
				// The single instance of the AudioExtension.
				static AdaptiveAudioTask* g_pInstance;

				#pragma endregion

				#pragma region Variables
				
				// The lock for the extension.
				CriticalSection				m_kLock;

				// The timer for the extension.
				Timer						m_kTimer;

				bool						m_bIsPaused;

				#pragma endregion

				#pragma region Constructors and Finalizers

				// Constructor.
				AdaptiveAudioTask();

				#pragma endregion

				#pragma region Methods

				void Set_IsPaused(bool pause);

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
				~AdaptiveAudioTask();

				#pragma endregion

				#pragma region Static Methods

				// Returns a pointer to the AudioExtension.
				static AdaptiveAudioTask* Instantiate();

				#pragma endregion

				friend AdaptiveMusicManager;

		};
	}
}