#include "gui\Singularity.Gui.h"
#include "inputs\Singularity.Inputs.h"
 
using namespace Singularity;
using namespace Singularity::Components;
using namespace Singularity::Inputs;
 
namespace Singularity
{
	namespace Gui
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, GuiExtension, Singularity::Threading::Task);

		#pragma region Static Variables
		
		// The single instance of the GuiExtension.
		GuiExtension* GuiExtension::g_pInstance = NULL; 

		#pragma endregion

		#pragma region Constructors and Finalizers

		// Constructor.
		GuiExtension::GuiExtension() 
			: Task("Gui Extension")
		{
			this->Set_Frequency(1 / 30.0f);

			this->m_kTimer.Reset();
			this->m_kTimer.Tick();
		}
		#pragma endregion

		#pragma region Methods

		// Registers a Control.
		void GuiExtension::RegisterComponent(Component* component)
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");
			if(!component->GetType().Equals(GuiScreen::Type))
				return;

			Autolock(this->m_kLock)
				this->m_pScreens.insert((GuiScreen*)component);
		}

		// Unregisters a Control.
		void GuiExtension::UnregisterComponent(Component* component)
		{
			if(component == NULL)
				throw SingularityException("\"Component\" cannot be null or empty.");
			if(!component->GetType().Equals(GuiScreen::Type))
				return;

			Autolock(this->m_kLock)
				this->m_pScreens.erase((GuiScreen*)component);
		}
		#pragma endregion
			
		#pragma region Overridden Methods
		void GuiExtension::OnExecute()
		{
			// if we have a depth:
			// identify everything that is under the click (add a method to control perhaps?)
			// only send a click to the closest thing.
			// we also want to make sure that the game world isn't fed input unless it's fed through here
			// (don't forget that we can ignore all of the click stuff if the cursor is not active)

			DynamicSet<GuiScreen*>::iterator it;
			Vector2 mousePosition = Input::GetMousePosition();
			bool mouseClicked = Input::GetMouseButton(0);

			for(it = this->m_pScreens.begin(); it != this->m_pScreens.end(); ++it)
			{
				if((*it)->Get_Enabled())
				{
					(*it)->HandleMouseInput(Input::GetMouseState());
					(*it)->HandleKeyboardInput(Input::GetKeyboardState());
				}
			}
			
			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods

		// Returns a pointer to the GuiExtension.
		GuiExtension* GuiExtension::Instantiate()
		{
			if(!GuiExtension::g_pInstance)
				GuiExtension::g_pInstance = new GuiExtension();
			return GuiExtension::g_pInstance;
		}

		#pragma endregion
	}
}