#include "gui\Singularity.Gui.h"

using namespace Singularity::Threading;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Gui
	{
		class GuiExtension : public Singularity::Threading::Task
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static GuiExtension* g_pInstance; // The single instance of the GuiExtension.
				#pragma endregion

				#pragma region Variables
				CriticalSection				m_kLock; // The lock for the extension.
				Timer						m_kTimer; // The timer for the extension.
				DynamicSet<GuiScreen*>		m_pScreens; // A list of controls.
				#pragma endregion

				#pragma region Constructors and Finalizers
				GuiExtension(); // Constructor.
				#pragma endregion

				#pragma region Methods		
				void RegisterComponent(Singularity::Components::Component* component); // Registers an Component.		
				void UnregisterComponent(Singularity::Components::Component* component); // Unregisters an Component.
				#pragma endregion

			protected:
				#pragma region Event Methods
				void OnExecute();
				void OnComplete() { };
				#pragma endregion

			public:
				#pragma region Static Methods
				static GuiExtension* Instantiate(); // Returns a pointer to the GuiExtension.
				#pragma endregion

				friend class Control;
				friend class GuiScreen;
		};
	}
}