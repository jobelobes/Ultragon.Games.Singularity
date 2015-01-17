#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, Renderer, Component);

		#pragma region Event Methods
		void Renderer::InternalOnRender(DrawingContext* context, Camera* camera)
		{
			if(this->m_pCallback != NULL)
				this->m_pCallback(this, context, camera);

			this->OnRender(context, camera);
		}

		void Renderer::UpdateRendererSnapshot()
		{
			this->m_kLocalToWorld = this->Get_GameObject()->Get_Transform()->Get_LocalToWorldMatrix();
		}

		void Renderer::Set_IsTiedToCamera(bool value)
		{
			m_bTiedToCamera = value;
			if (value == true)
				RenderTask::Instantiate()->RegisterTiedRenderer(this);
			else
				RenderTask::Instantiate()->UnregisterTiedRenderer(this);
		}

		#pragma endregion

		#pragma region Overriden Methods
		void Renderer::OnComponentAdded(GameObject* gameObject)
		{
			RenderTask::Instantiate()->RegisterComponent(this);
			if (this->Get_IsTiedToCamera())
			{
				this->UpdateRendererSnapshot();
				RenderTask::Instantiate()->RegisterTiedRenderer(this);
			}
		}

		void Renderer::OnComponentRemoved(GameObject* gameObject)
		{
			RenderTask::Instantiate()->UnregisterComponent(this);
		}
		#pragma endregion
	}
}