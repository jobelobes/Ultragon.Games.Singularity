// 3/21
// Window.h
// Groups together GUI elements with a possibly visible border. Replaces FrameWindow, HAH!

#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		class Window: public Singularity::Gui::Panel
		{
			private:
				#pragma region Variables
				bool	m_bDraggable;
				bool	m_bDragging;
				Vector2 m_kPrevPosition;
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				bool HandleMouseInput(Singularity::Inputs::MouseState& state, bool handled = false);
				#pragma endregion

				#pragma region Event Methods
				void OnMouseClick(Vector2 position);
				void OnMouseDown(Vector2 position);
				void OnMouseUp(Vector2 position);
				void OnMouseMove(Vector2 position);

				void OnVisible() { Get_GuiParent()->ReorderWindows(this); }; // Called when the control becomes visible.
				//void OnInvisible() { Get_GuiParent()->ReorderWindows(); }; // Called when the control become invisible.
				#pragma endregion

			public:
				#pragma region Constructors and Deconstructors
				const bool Get_Draggable() const;
				void Set_Draggable(const bool value);
				#pragma endregion

				#pragma region Constructors and Deconstructors
				Window(String name = "") : Panel(name), m_bDraggable(true), m_bDragging(false) { };
				Window(String name, NinePatch* texture, Vector2 position, Vector2 size) : Panel(name, texture, position, size), m_bDraggable(true), m_bDragging(false) { };
				~Window() { };
				#pragma endregion

				#pragma region Methods
				void SetFocus();
				#pragma endregion

				friend class GuiScreen;
		};

		#include "gui\Window.inc"
	}
}