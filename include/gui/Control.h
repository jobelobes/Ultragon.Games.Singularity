// 3/21
// Control.h
// A Gui component. NOT a component in a game. Registers with the GuiManager instead(?)

#include "gui\Singularity.Gui.h"
#include "scripting\LuaCallback.h"

namespace Singularity
{
	namespace Gui
	{
		class Control : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Static Variables
				static Material* g_pMaterial;
				#pragma endregion

				#pragma region Static Methods
				static Material* CreateGuiMaterial();
				#pragma endregion

				#pragma region Variables
				String									m_kName; //a name for the control.
				Vector2									m_sPosition;
				Vector2									m_sSize;
				float									m_fDepth;

				bool									m_bVisible;
				bool									m_bEnabled;
				bool									m_bHasFocus;

				NinePatch*								m_pTexture; // some objects may have a 0px padding, meaning it doesn't resize
				Material*								m_pMaterial;
				GuiControlVertexDeclaration				m_pDeclaration;
				VertexBuffer*							m_pVertices;
				IndexBuffer*							m_pIndices;	

				GuiScreen*								m_pGuiParent;
				Control*								m_pParent;
				
				bool									m_bMouseOver;
				bool									m_bMouseClick;
				Singularity::Inputs::MouseState			m_pMouseState[2];
				Singularity::Inputs::KeyboardState		m_pKeyboardState[2];
				#pragma endregion

				#pragma region Methods
				void InternalRebuildControl();
				#pragma endregion

			protected:

				bool							m_bNeedToRecalc;
				DynamicList<Control*>			m_pChildControls;

				#pragma region Properties
				float Get_Depth() const;
				
				Singularity::Graphics::Material* Get_Material() const;
				void Set_Material(Singularity::Graphics::Material* value);

				GuiScreen* Get_GuiParent();

				Control* Get_Parent() const;
				#pragma endregion

				#pragma region Methods
				virtual bool HandleMouseInput(Singularity::Inputs::MouseState& state, bool handled = false);
				virtual bool HandleKeyboardInput(Singularity::Inputs::KeyboardState& state, bool handled = false);

				void RebuildControl(bool recursive = false);

				Control* GetChildControl(String name);
				void AddChildControl(Control* control);
				void RemoveChildControl(Control* control);
				void Clear();
				#pragma endregion

				#pragma region Event Methods
				virtual void OnInitialize() { };
				virtual void OnActivate() { }; // Called when activated.
				virtual void OnDeactivate() { }; // Called when deactivated.
				virtual void OnPaint(DrawingContext* context, Camera* camera); // Called in order to draw.
				virtual void OnFocusGained(); // Called when focus is gained.
				virtual void OnFocusLost(); // Called when focus is lost.
				virtual void OnVisible() { }; // Called when the control becomes visible.
				virtual void OnInvisible() { }; // Called when the control become invisible.

				virtual void OnMouseClick(Vector2 position) { }; // Called when the mouse rolls over the component.
				virtual void OnMouseMove(Vector2 position) { }; // Called when the mouse rolls over the component.
				virtual void OnMouseEnter(Vector2 position) { }; // Called when the mouse rolls over the component.
				virtual void OnMouseLeave(Vector2 position) { };  // Called when the mouse leaves the component.
				virtual void OnMouseDown(Vector2 position);  // Called when the mouse leaves the component.
				virtual void OnMouseUp(Vector2 position);  // Called when the mouse leaves the component.

				virtual void OnKeyDown(bool shift, bool control, int keyIndex);
				virtual void OnKeyUp(bool shift, bool control, int keyIndex);		
				virtual void OnKeyPress(bool shift, bool control, int keyIndex);	
				#pragma endregion

			public:
				#pragma region Variables
				DelegateHandler	FocusGained;
				DelegateHandler	FocusLost;

				DelegateHandler	MouseDown;
				DelegateHandler	MouseUp;

				DelegateHandler	KeyDown;
				DelegateHandler	KeyUp;
				DelegateHandler KeyPress;
				#pragma endregion

				#pragma region Constructors and Deconstructors
				Control(String name);
				Control(String name, NinePatch* texture, Vector2 position, Vector2 size);
				Control(String name, Singularity::Graphics::Material* material);
				~Control();
				#pragma endregion

				#pragma region Properties
				void Set_Parent(Control* value);
				void Set_Depth(float value);

				Vector2 Get_AbsolutePosition() const;

				const bool Get_HasFocus() const;

				String Get_Name() const;
				void Set_Name(String value);

				Vector2 Get_Position() const;
				void Set_Position(Vector2 value);

				Vector2 Get_Size() const;
				void Set_Size(Vector2 value);

				NinePatch* Get_Texture() const;
				void Set_Texture(NinePatch* value);

				const bool Get_Visible() const;
				void Set_Visible(const bool value);

				const bool Get_Enabled() const;
				void Set_Enabled(const bool value);

				void Set_Color(Color color);

				int Get_NumberOfChildren() const;
				#pragma endregion

				#pragma region Methods
				virtual void SetFocus();
				#pragma endregion

				friend class GuiScreen;
				friend class GuiExtension;
				friend class Panel;
		};

		#include "gui\Control.inc"
	}
}