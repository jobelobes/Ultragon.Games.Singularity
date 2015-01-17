#include "graphics\Singularity.Graphics.h"
 
using namespace Singularity;
using namespace Singularity::Graphics;
using namespace Singularity::Components;
using namespace Singularity::Threading;
using namespace Singularity::Graphics::Devices;
 
namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, RenderTask, Singularity::Threading::Task);

		#pragma region Static Variables
		RenderTask* RenderTask::g_pInstance = NULL; 
		#pragma endregion

		#pragma region Constructors and Finalizers
		RenderTask::RenderTask(DrawingContext* context)
			: Task("Renderer Task"), m_pDrawingContext(context)
		{
			unsigned index;

			// should be set elsewhere, NOT hardcoded :/

			this->m_pRenderers = new Octree<Renderer*>(Bounds(Vector3(1000,50,750), Vector3(4000, 500, 1500))); // guesswork! 
			//this->m_pRenderers = new Octree<Renderer*>(Bounds(Vector3(0,0,0), Vector3(FLT_MAX, FLT_MAX, FLT_MAX)));

			for(index = 0; index < SINGULARITY_RENDERER_MAX_SUBTASKS; ++index)
				this->m_pSubTasks[index] = new RenderSubTask();

			this->Set_Frequency(1 / 60.0f);
		}
		#pragma endregion

		#pragma region Methods
		void RenderTask::RegisterComponent(Component* component)
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				if(component->GetType().Equals(Camera::Type))
					this->m_pCamera.insert((Camera*)component);
				else if(component->GetType().Equals(Light::Type))
					this->m_pLights.insert((Light*)component);
				else if(component->GetType().IsSubClassOf(Renderer::Type))
					this->m_pRenderers->insert(Bounds(((Renderer*)component)->Get_Bounds().Center, Vector3(0,0,0)), (Renderer*)component);
			}
		}

		void RenderTask::UnregisterComponent(Component* component)
		{
			if(component == NULL)
				throw SingularityException("\"component\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				if(component->GetType().Equals(Camera::Type))
					this->m_pCamera.erase((Camera*)component);
				else if(component->GetType().Equals(Light::Type))
					this->m_pLights.erase((Light*)component);
				else if(component->GetType().IsSubClassOf(Renderer::Type))
					this->m_pRenderers->erase((Renderer*)component);
			}
		}

		void RenderTask::RegisterTiedRenderer(Renderer* renderer)
		{
			if(renderer == NULL)
				throw SingularityException("\"renderer\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				this->m_pRenderersTiedToCamera.insert(renderer);
			}
		}

		void RenderTask::UnregisterTiedRenderer(Renderer* renderer)
		{
			if(renderer == NULL)
				throw SingularityException("\"renderer\" cannot be null or empty.");

			Autolock(this->m_kLock)
			{
				this->m_pRenderersTiedToCamera.erase(renderer);
			}
		}

		void RenderTask::OnExecuteCamera(Camera* camera)
		{
			DynamicSet<Renderer*>::iterator it;
			// Update list of renderers tied to camera.
			for(it = this->m_pRenderersTiedToCamera.begin(); it != this->m_pRenderersTiedToCamera.end(); ++it)
			{
				if((*it)->Get_Enabled() && (*it)->Get_IsVisible())
				{
					(*it)->UpdateRendererSnapshot();
				}
			}
							
			// Lock the camera.
			camera->UpdateCameraSnapshot();

			// Right now if we wanted multiple subtasks (and we do...) we would need to split them up in such a way that
			// we can maintain state on the card without swapping like crazy. Simplest way: feed all of Type 1 to the subtasks,
			// then all of Type 2, then all of Type 3...

			// Unless you need to maintain draw order, in which case it gets more complicated.
			this->m_pSubTasks[0]->Update(this->m_pDrawingContext, camera);
			this->Spawn(this->m_pSubTasks[0]);
		}
		#pragma endregion
 
		#pragma region Overriden Methods
		void RenderTask::OnExecute()
		{
			DynamicSet<Camera*>::iterator it;

			#if _DEBUG
			//printf("Render Call Frequency = %3.1f\n", this->Get_ActualFrequency());
			#endif

			if(this->m_pCamera.size() > 0)
			{
				for(it = this->m_pCamera.begin(); it != this->m_pCamera.end(); ++it)
				{
					if((*it)->Get_Enabled())
						this->OnExecuteCamera(*it);
				}
			}

			this->Recycle();
		}
		#pragma endregion

		#pragma region Static Methods
		RenderTask* RenderTask::Instantiate()
		{
			if(!RenderTask::g_pInstance)
				RenderTask::g_pInstance = new RenderTask(new DeferredDrawingContext());
			return RenderTask::g_pInstance;
		}
		#pragma endregion
	}
}