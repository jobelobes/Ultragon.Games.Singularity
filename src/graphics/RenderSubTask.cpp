#include "graphics\Singularity.Graphics.h"
 
using namespace Singularity;
using namespace Singularity::Threading;
using namespace Singularity::Components;
using namespace Singularity::Graphics::Devices;
 
namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, RenderSubTask, Singularity::Threading::Task);

		#pragma region Constructors and Finalizers
		/*RenderSubTask::RenderSubTask() 
			: Task("Render Sub-Task"), m_pCamera(NULL), m_pDrawingContext(NULL), m_pBufferedDrawingContext(NULL), m_pIterator(NULL) { }*/
		RenderSubTask::RenderSubTask()
			: Task("Render Sub-Task"), m_pCamera(NULL), m_pDrawingContext(NULL), m_pDeferredDrawingContext(NULL), m_pIterator(NULL) { }
		#pragma endregion

		#pragma region Methods
		void RenderSubTask::Update(DrawingContext* context, Camera* camera)
		{
			this->m_pDrawingContext = context;
			this->m_pCamera = camera;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void RenderSubTask::OnExecute()
		{
			RenderTask* parent;
			Renderer* renderer;
			DynamicSet<Light*>::iterator it;

			if(this->m_pDrawingContext == NULL || this->m_pCamera == NULL)
				return;

			parent = (RenderTask*)this->Get_ParentTask();

			try
			{
				//lock(parent->m_kLock)
				//{
					this->m_pCamera->OnPreCull(this->m_pDrawingContext);
					this->m_pCamera->OnPreRender(this->m_pDrawingContext);

					if(this->m_pIterator == NULL)
						this->m_pIterator = new OctreeIterator<Renderer*>(parent->m_pRenderers);

					this->m_pIterator->Reset();

					for(it = parent->m_pLights.begin(); it != parent->m_pLights.end(); ++it)
					{
						if((*it)->Get_Enabled())
							this->m_pDrawingContext->AddLight(*it);
					}
				

					//Vector3 cameraLoc;
					//Vector3 renderLoc;
					//
					//cameraLoc = m_pCamera->Get_Description().Position;
					
					// Now we can draw them knowing they're all synced.
					this->m_pIterator->Reset();
					while(this->m_pIterator->Next(renderer))
					{
						
						//renderLoc = renderer->Get_GameObject()->Get_Transform()->Get_Position();
						//if(Vector3(cameraLoc - renderLoc).length() > 500)
						//{
						//	printf("%d %d %d\n", cameraLoc.x, cameraLoc.y, cameraLoc.z);
						//	continue;
						//}

						if(renderer->Get_Enabled() && renderer->Get_IsVisible())
							renderer->InternalOnRender(this->m_pDrawingContext, this->m_pCamera);
					}
				//}
				
				this->m_pCamera->OnRenderImage(this->m_pDrawingContext);
				this->m_pCamera->OnPostRender(this->m_pDrawingContext);
			}
			catch(SingularityException& e) 
			{
				this->m_pDrawingContext->Clear(this->m_pCamera->Get_BackgroundColor());
				fprintf(stderr, "An exception has occurred in the RenderSubTask: %s\n", boost::diagnostic_information(e).c_str());
			}
		}
		#pragma endregion
	}
}