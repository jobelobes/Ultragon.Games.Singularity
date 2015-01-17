#include "gui\Singularity.Gui.h"

using namespace Singularity::Graphics;
using namespace Singularity::Graphics::Devices;
using namespace Singularity::Components;
using namespace Singularity::Inputs;

namespace Singularity
{
	namespace Gui
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Gui, GuiScreen, Renderer);

		#pragma region Methods
		void GuiScreen::ReorderWindows(Window* focusedWindow)
		{
			int index, count, focusIndex;

			focusIndex = -1;
			count = this->m_pWindows.size();
			if(this->m_pWindows[0] == focusedWindow) // check the front
				return;

			Window* temp = NULL;
			for (index = count - 1; index >= 0; --index)
			//for(index = 0; index < count; ++index)
			{
				//if(!this->m_pWindows[index]->Get_Enabled())
					//continue;

				// if we've found it, throw it on the front
				if(this->m_pWindows[index] == focusedWindow)
				{
					focusIndex = index;
					temp = m_pWindows[index];
					this->m_pWindows[index] = this->m_pWindows[0];
					this->m_pWindows[0] = temp;
				}
				
				if(focusIndex < 0)
					continue;
				else
				{
					// shift the previous front to spot #2
					if ((index - 1) >= 0)
					{
						temp = m_pWindows[index];
						this->m_pWindows[index] = this->m_pWindows[index-1];
						this->m_pWindows[index - 1] = temp;
					}

					// this is making us lose windows -- we're copying memory locations and losing m_pWindows[index]
					//this->m_pWindows[index] = ((index + 1) < count) ? this->m_pWindows[index + 1] : focusedWindow;
					// 1 is FARTHER. 0 is CLOSER. WTF.
					this->m_pWindows[index]->Set_Depth(0.1f + index * 0.1f);
					// but controls all draw fine...? weird.
					//this->m_pWindows[index]->Set_Depth(0.98f - index * 0.1f);
					
				}
			}
		}

		void GuiScreen::HandleMouseInput(MouseState& state)
		{
			int index, count;			

			count = this->m_pWindows.size();
			//for(index = count - 1; index >= 0; --index)
			for (index = 0; index < count; index++)
			{
				if(!this->m_pWindows[index]->m_bEnabled)
					continue;

				if(this->m_pWindows[index]->HandleMouseInput(state, false))
				{
					
					//this->m_pControlWithFocus = this->m_pWindows[index];
					return;
				}
			}
		}

		void GuiScreen::HandleKeyboardInput(KeyboardState& state)
		{
			if(this->m_pControlWithFocus != NULL)
				this->m_pControlWithFocus->HandleKeyboardInput(state);
		}

		Control* GuiScreen::GetControl(String name)
		{
			unsigned index, count;
			Control* control;

			count = this->m_pWindows.size();
			for(index = 0; index < count; ++index)
			{
				if(this->m_pWindows[index]->Get_Name() == name)
					return this->m_pWindows[index];
				else
				{
					control = this->m_pWindows[index]->GetChildControl(name);
					if(control != NULL)
						return control;
				}
			}
			
			return NULL;
		}

		void GuiScreen::AddWindow(Window* window)
		{
			this->m_pWindows.push_back(window);
			((Control*)window)->m_pGuiParent = this;
			//window->Set_Enabled(true);
			window->Set_Depth(0.99f - this->m_pWindows.size() * 0.1f);
			this->ReorderWindows(window);
		}

		void GuiScreen::RemoveWindow(Window* window)
		{
			unsigned index, count;

			if(window == NULL)
				throw SingularityException("\"window\" cannot be null or empty.");

			count = this->m_pWindows.size();
			for(index = 0; index < count; ++index)
			{
				if(this->m_pWindows[index] == window)
				{
					this->m_pWindows[index] = this->m_pWindows[count - 1];
					this->m_pWindows.pop_back();
				}
			}		
		}

		void GuiScreen::Clear()
		{
			for (unsigned index = 0; index < m_pWindows.size(); ++index)
				this->m_pWindows[index]->Set_Visible(false);
			this->m_pWindows.clear();
		}
		#pragma endregion

		#pragma region Overriden Methods
		void GuiScreen::OnComponentAdded(GameObject* gameObject)
		{
			Renderer::OnComponentAdded(gameObject);
			GuiExtension::Instantiate()->RegisterComponent(this);
		}

		void GuiScreen::OnComponentRemoved(GameObject* gameObject)
		{
			Renderer::OnComponentRemoved(gameObject);
			GuiExtension::Instantiate()->UnregisterComponent(this);
		}

		void GuiScreen::OnRender(DrawingContext* context, Camera* camera)
		{
			int index, count;

			RenderState renderState;
			renderState.Set_EnableAlphaToCoverage(false);
			renderState.EnableBlend(0);
			renderState.Set_SourceBlend(Blend::SourceAlpha);
			renderState.Set_DestinationBlend(Blend::InverseSourceAlpha);
			renderState.Set_BlendFunction(BlendFunction::Add);
			renderState.Set_AlphaSourceBlend(Blend::Zero);
			renderState.Set_AlphaDestinationBlend(Blend::Zero);
			renderState.Set_AlphaBlendOperation(BlendFunction::Max);
			renderState.Set_EnableDepthBuffer(false);
			renderState.Set_CullMode(CullMode::None);
			renderState.Set_PrimitiveType(PrimitiveTopology::PointList);

			context->SetLayer(100);
			context->SetRenderState(renderState);
			count = this->m_pWindows.size();

			// we have a backwards draw.
			//for (index = count - 1; index >= 0; --index)
			for (index = 0; index < count; index++)
			{
				if(this->m_pWindows[index]->Get_Visible() && this->m_pWindows[index]->Get_Enabled())
					this->m_pWindows[index]->OnPaint(context, camera);
			}
		}
		#pragma endregion
	}
}