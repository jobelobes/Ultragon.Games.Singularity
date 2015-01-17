// 3/21
// GuiScreen.h
// A screen in the 2d subsystem. Attaches to the GuiManager.

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class GuiScreen : public Singularity::Graphics::Renderer
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				Control*				m_pControlWithFocus; // When something is clicked upon, call FOCUS on it and UNFOCUS on whatever had focus before.
				DynamicList<Window*>	m_pWindows;
				#pragma endregion

			protected:
				#pragma region Methods
				void ReorderWindows(Window* focusedWindow);
				void HandleMouseInput(Singularity::Inputs::MouseState& state);
				void HandleKeyboardInput(Singularity::Inputs::KeyboardState& state);
				#pragma endregion

				#pragma region Overriden Methods
				void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				void OnRender(Singularity::Graphics::Devices::DrawingContext* context, Singularity::Graphics::Camera* camera);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				GuiScreen(String name = "") : Renderer(name, NULL), m_pControlWithFocus(NULL) { }
				~GuiScreen() {}
				#pragma endregion

				#pragma region Properties
				Control* Get_ControlWithFocus();
				#pragma endregion

				#pragma region Methods
				Control* GetControl(String name);
				void AddWindow(Window* window);
				void RemoveWindow(Window* window);
				void Clear();
				#pragma endregion

				friend class Control;
				friend class GuiExtension;
				friend class Window;
		};

		#include "gui\GuiScreen.inc"
	}
}