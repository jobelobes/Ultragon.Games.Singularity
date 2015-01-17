#include "gui\Singularity.Gui.h"

using namespace Singularity::Inputs;
using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Gui
	{				
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, Control, Singularity::Object);

		#pragma region Static Variables
		Material* Control::g_pMaterial = NULL;
		#pragma endregion

		#pragma region Constructors and Deconstructors
		Control::Control(String name)
			: m_kName(name), m_sPosition(0,0), m_bVisible(true), m_pTexture(NULL), m_pVertices(NULL), m_bNeedToRecalc(true), m_pMaterial(Control::CreateGuiMaterial()), m_pGuiParent(NULL), m_pParent(NULL), m_fDepth(0.9f)
		{		
			this->m_pVertices = new VertexBuffer(GuiControlVertexDeclaration::Declaration, 1);
			m_pTexture = new NinePatch(Texture2D::LoadTextureFromFile(SINGULARITY_NINEPATCH_DEFAULT_FILEPATH), SINGULARITY_NINEPATCH_DEFAULT_CENTER);
		}
		
		Control::Control(String name, NinePatch* texture, Vector2 position, Vector2 size)
			: m_kName(name), m_pTexture(texture), m_sPosition(position), m_sSize(size), m_bVisible(true), m_pMaterial(Control::CreateGuiMaterial()), m_pVertices(NULL), m_bNeedToRecalc(true), m_pGuiParent(NULL), m_pParent(NULL), m_fDepth(0.9f)
		{
			this->m_pVertices = new VertexBuffer(GuiControlVertexDeclaration::Declaration, 1);
		}

		Control::Control(String name, Material* material)
			: m_kName(name), m_sPosition(0,0), m_bVisible(true), m_pVertices(NULL), m_pMaterial(material), m_bNeedToRecalc(true), m_pGuiParent(NULL), m_pParent(NULL), m_fDepth(0.9f)
		{
			m_pTexture = new NinePatch(Texture2D::LoadTextureFromFile(SINGULARITY_NINEPATCH_DEFAULT_FILEPATH), SINGULARITY_NINEPATCH_DEFAULT_CENTER);
			m_sSize = Vector2((float)m_pTexture->Get_Width(), (float)m_pTexture->Get_Height());
			
			this->m_pVertices = new VertexBuffer(GuiControlVertexDeclaration::Declaration, 1);
		}

		Control::~Control()
		{
			for (int i = this->m_pChildControls.size() -1; i >= 0; --i)
			{
				if (m_pChildControls[i] != NULL)
				{
					delete m_pChildControls[i];
				}
				m_pChildControls.clear();
			}
		}
		#pragma endregion

		#pragma region Methods
		void Control::SetFocus()
		{
			if(this->Get_GuiParent()->m_pControlWithFocus != this)
			{
				if(this->Get_GuiParent()->m_pControlWithFocus != NULL)
					this->Get_GuiParent()->m_pControlWithFocus->OnFocusLost();
				this->Get_GuiParent()->m_pControlWithFocus = this;
				this->OnFocusGained();
			}
		}

		bool Control::HandleMouseInput(MouseState& state, bool handled)
		{
			bool mouseOver[2];
			bool mouseDown[2];
			Vector2 mousePosition[2];
			unsigned count;
			
			/*if(state == this->m_pMouseState[0])
				return false;*/

			// swap the mouse states
			MouseState previous = this->m_pMouseState[0];
			this->m_pMouseState[0] = state;
			this->m_pMouseState[1] = previous;
			
			Vector2 position = this->Get_AbsolutePosition();
			Vector2 max = Vector2(position.x + this->m_sSize.x, position.y + this->m_sSize.y);
			mousePosition[0] = this->m_pMouseState[0].GetMousePosition();
			mousePosition[1] = this->m_pMouseState[1].GetMousePosition();

			mouseOver[0] = (mousePosition[0].x > position.x && mousePosition[0].y > position.y && mousePosition[0].x < max.x && mousePosition[0].y < max.y);
			mouseOver[1] = (mousePosition[1].x > position.x && mousePosition[1].y > position.y && mousePosition[1].x < max.x && mousePosition[1].y < max.y);

			if(mouseOver[0] && !mouseOver[1])
				this->OnMouseEnter(mousePosition[0]);
			else if(!mouseOver[0] && mouseOver[1])
				this->OnMouseLeave(mousePosition[0]);

			if(mouseOver[0])
				this->OnMouseMove(mousePosition[0]);

			count = this->m_pChildControls.size();
			for (int index = this->m_pChildControls.size() -1; index >= 0; --index)
			{
				if(this->m_pChildControls[index]->m_bEnabled)
					 handled |= this->m_pChildControls[index]->HandleMouseInput(state, handled);
			}

			if(!handled && mouseOver[0])
			{
				mouseDown[0] = this->m_pMouseState[0].GetMouseButton(0);
				mouseDown[1] = this->m_pMouseState[1].GetMouseButton(0);

				if(mouseDown[0])
					this->OnMouseDown(mousePosition[0]);
				else if(!mouseDown[0] && mouseDown[1])
				{
					this->OnMouseUp(mousePosition[0]);
					this->OnMouseClick(mousePosition[0]);

					this->SetFocus();
				}
				return true;
			}
			return false;
		}

		bool Control::HandleKeyboardInput(KeyboardState& state, bool handled)
		{
			unsigned index, count;
			bool keydown[2], shift, control;

			//if(state == this->m_pKeyboardState[0])
			//	return false;

			// swap the mouse states
			KeyboardState previous = this->m_pKeyboardState[0];
			this->m_pKeyboardState[0] = state;
			this->m_pKeyboardState[1] = previous;

			count = this->m_pChildControls.size();
			for (int index = this->m_pChildControls.size() -1; index >= 0; --index)
			{
				if(this->m_pChildControls[index]->m_bEnabled)
					 handled |= this->m_pChildControls[index]->HandleKeyboardInput(state, handled);
			}

			if (!handled && this == this->Get_GuiParent()->m_pControlWithFocus)
			{
				shift = this->m_pKeyboardState[0].IsKeyDown(DIK_LSHIFT) || this->m_pKeyboardState[0].IsKeyDown(DIK_RSHIFT) || this->m_pKeyboardState[0].IsKeyDown(DIK_CAPSLOCK);
				control = this->m_pKeyboardState[0].IsKeyDown(DIK_LCONTROL) || this->m_pKeyboardState[0].IsKeyDown(DIK_RCONTROL);

				for(index = 0; index <= 0xED; ++index)
				{
					if(index == DIK_LCONTROL || index == DIK_RCONTROL || index == DIK_LSHIFT || index == DIK_RSHIFT || index == DIK_CAPSLOCK)
						continue;

					keydown[0] = this->m_pKeyboardState[0].IsKeyDown(index);
					keydown[1] = this->m_pKeyboardState[1].IsKeyDown(index);

					if(keydown[0] && !keydown[1])
						this->OnKeyDown(shift, control, index);
					else if(!keydown[0] && keydown[1])
					{
						this->OnKeyUp(shift, control, index);
						this->OnKeyPress(shift, control, index);
					}
				}

				return true;
			}
			return handled;
		}

		void Control::InternalRebuildControl()
		{
			Vector3 offset;

			if(!this->m_pMaterial)
				throw SingularityException("Material cannot be null in order to draw. Set material before continuing");
		
			offset = Vector3(0,0,0);
			if(this->m_pParent)
				offset = this->m_pParent->m_pDeclaration.position;

			if(this->m_pTexture != NULL)
			{
				this->m_pDeclaration.position = Vector3(offset.x + this->m_sPosition.x, offset.y + this->m_sPosition.y, this->m_fDepth);
				this->m_pDeclaration.size = this->m_sSize;
				this->m_pDeclaration.center = this->m_pTexture->Get_Padding();

				this->m_pVertices->SetData(&this->m_pDeclaration);
				this->m_pMaterial->Set_MainTexture(this->m_pTexture->GetTexture());
			}

			this->m_bNeedToRecalc = false;
		}

		Vector2 Control::Get_Position() const 
		{ 
			return this->m_sPosition;
		}

		Vector2 Control::Get_AbsolutePosition() const
		{
			if (this->Get_Parent())
			{
				return this->m_sPosition + Get_Parent()->Get_AbsolutePosition();
			}
			else
			{
				return this->m_sPosition;
			}
		}

		void Control::RebuildControl(bool recursive)
		{
			unsigned count;

			this->m_bNeedToRecalc = true;

			if(!recursive)
				return;

			count = this->m_pChildControls.size();
			for (int index = this->m_pChildControls.size() -1; index >= 0; --index)
				this->m_pChildControls[index]->RebuildControl(recursive);
		}

		void Control::AddChildControl(Control* control)
		{

			this->m_pChildControls.push_back(control);
			//control->Set_Depth(this->m_fDepth - this->m_fDepth * 0.01f * this->m_pChildControls.size());
			control->Set_Depth(this->m_fDepth - this->m_pChildControls.size() * 0.0001f);
			
			control->Set_Enabled(true);
			control->Set_Parent(this);
			this->m_bNeedToRecalc = true;
		}

		void Control::RemoveChildControl(Control* control)
		{
			unsigned index, count;

			if(control == NULL)
				throw SingularityException("\"control\" cannot be null or empty.");

			count = this->m_pChildControls.size();
			for(index = 0; index < count; ++index)
			{
				if(this->m_pChildControls[index] == control)
				{
					this->m_pChildControls[index] = this->m_pChildControls[count - 1];
					this->m_pChildControls.pop_back();
				}
			}
		}

		Control* Control::GetChildControl(String name)
		{
			unsigned count;
			Control* control;

			count = this->m_pChildControls.size();
			for (DynamicList<Control*>::iterator iter = this->m_pChildControls.begin(); iter != this->m_pChildControls.end(); iter++)
			{
				if((*iter)->Get_Name() == name)
				{
					return *iter;
				}
				else
				{
					control = (*iter)->GetChildControl(name);
					if(control != NULL)
						return control;
				}
			}
			
			return NULL;
		}

		void Control::Clear()
		{
			for (unsigned index = 0; index < this->m_pChildControls.size(); ++index)
			{	
				this->m_pChildControls[index]->Set_Visible(false);
				this->m_pChildControls[index]->Clear();
			}

			this->m_pChildControls.clear();
		}
		#pragma endregion

		#pragma region Event Methods
		void Control::OnPaint(DrawingContext* context, Camera* camera)
		{
			Matrix world = Matrix::CreateIdentity();

			if (this->m_bNeedToRecalc)
				this->InternalRebuildControl();

			if(!this->m_pMaterial)
				throw SingularityException("Material cannot be null in order to draw. Set material before continuing");

			unsigned size = this->m_pChildControls.size();

			if (size > 0)
			{

				for (unsigned i = size -1; i < size; --i) // i < size because we'll wrap to a positive number rather than go to -1
				{	
					if(this->m_pChildControls[i]->m_bVisible && this->m_pChildControls[i]->m_bEnabled)
						this->m_pChildControls[i]->OnPaint(context, camera);
				}

			}

			if(this->m_pTexture != NULL)
				context->Draw(camera, this->m_pMaterial, world, this->m_pVertices);
		}


		void Control::OnFocusGained()
		{
			for(unsigned i = 0; i < this->FocusGained.Count(); ++i)
				if(this->FocusGained[i]->GetType().Equals(ControlDelegate::Type))
					((ControlDelegate*)this->FocusGained[i])->Invoke(this);
		}

		void Control::OnFocusLost()
		{
			for(unsigned i = 0; i < this->FocusLost.Count(); ++i)
				if(this->FocusLost[i]->GetType().Equals(ControlDelegate::Type))
					((ControlDelegate*)this->FocusLost[i])->Invoke(this);
		}
		
		void Control::OnMouseDown(Vector2 position)
		{
			for(unsigned i = 0; i < this->MouseDown.Count(); ++i)
				if(this->MouseDown[i]->GetType().Equals(ControlMouseDelegate::Type))
					((ControlMouseDelegate*)this->MouseDown[i])->Invoke(this, position);
		}

		void Control::OnMouseUp(Vector2 position)
		{
			for(unsigned i = 0; i < this->MouseUp.Count(); ++i)
				if(this->MouseUp[i]->GetType().Equals(ControlMouseDelegate::Type))
					((ControlMouseDelegate*)this->MouseUp[i])->Invoke(this, position);
		}

		void Control::OnKeyDown(bool shift, bool control, int keyIndex)
		{
			for(unsigned i = 0; i < this->KeyDown.Count(); ++i)
				if(this->KeyDown[i]->GetType().Equals(ControlKeyboardDelegate::Type))
					((ControlKeyboardDelegate*)this->KeyDown[i])->Invoke(this, shift, control, keyIndex);
		}

		void Control::OnKeyUp(bool shift, bool control, int keyIndex)
		{
			for(unsigned i = 0; i < this->KeyUp.Count(); ++i)
				if(this->KeyUp[i]->GetType().Equals(ControlKeyboardDelegate::Type))
					((ControlKeyboardDelegate*)this->KeyUp[i])->Invoke(this, shift, control, keyIndex);
		}

		void Control::OnKeyPress(bool shift, bool control, int keyIndex)
		{
			for(unsigned i = 0; i < this->KeyPress.Count(); ++i)
				if(this->KeyPress[i]->GetType().Equals(ControlKeyboardDelegate::Type))
					((ControlKeyboardDelegate*)this->KeyPress[i])->Invoke(this, shift, control, keyIndex);
		}
		#pragma endregion

		#pragma region Properties
		void Control::Set_Position(Vector2 value)
		{
			if (value == this->m_sPosition)
				return;				

			this->m_sPosition = value; 
			this->RebuildControl(true);
		}

		void Control::Set_Size(Vector2 value)
		{
			if (value == this->m_sSize) 
				return;

			this->m_sSize = value;
			this->RebuildControl(false);
		}

		void Control::Set_Visible(const bool value)
		{
			// Inactive does NOT necessarily mean invisible.
			// Invisible, on the other hand, DOES mean inactive.
			// We don't want to handle input on a gui element that's not there.

			if(value == this->m_bVisible)
				return;
			
			if (this->m_bVisible = value)
			{
				this->Set_Enabled(true);
				this->OnVisible();
			}
			else
			{
				this->Set_Enabled(false); // turn it off first
				this->OnInvisible();
			}

			//for (int index = 0; index < this->m_pChildControls.size(); ++index)
			//	this->m_pChildControls[index]->Set_Visible(value);
		}

		void Control::Set_Enabled(const bool value)
		{

			// Inactive does NOT necessarily mean invisible.
			// Invisible, on the other hand, DOES mean inactive.
			// We don't want to handle input on a gui element that's not there.

			this->m_bEnabled = value; 

			if (value)
				this->OnActivate(); 
			else 
				this->OnDeactivate();

			for (unsigned index = 0; index < this->m_pChildControls.size(); ++index)
				this->m_pChildControls[index]->Set_Enabled(value);
		}

		GuiScreen* Control::Get_GuiParent()
		{
			if (this->m_pGuiParent == NULL && this->m_pParent != NULL) 
				this->m_pGuiParent = this->m_pParent->Get_GuiParent();

			return this->m_pGuiParent;
		}

		void Control::Set_Depth(float value)
		{ 
			this->m_bNeedToRecalc = true;
			this->m_fDepth = value;
			for (unsigned index = 0; index < this->m_pChildControls.size(); ++index)
				this->m_pChildControls[index]->Set_Depth(this->m_fDepth - SINGULARITY_GUI_DEPTH_DIFFERENCE);
		}

		#pragma endregion

		#pragma region Static Methods
		Material* Control::CreateGuiMaterial()
		{
			HRSRC src;
			HANDLE bytes;
			String material;
			char id[5];

			if(Control::g_pMaterial == NULL)
			{
				id[0] = '#';
				_itoa_s(IDR_GUI_BINARY1, &id[1], 4, 10);
				src = ::FindResource(NULL, id, "GUI_BINARY");
				bytes = ::LoadResource(NULL, src);
				material = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
				Control::g_pMaterial = Material::LoadMaterialFromMemory(String("GuiMaterial"),  material);
				::FreeResource(bytes);
				return Control::g_pMaterial;
			}
			return Control::g_pMaterial->Clone();
		}
		#pragma endregion
	}
}