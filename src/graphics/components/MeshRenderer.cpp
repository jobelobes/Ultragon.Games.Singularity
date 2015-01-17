#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Components;
using namespace Singularity::Graphics::Devices;

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, MeshRenderer, Renderer);

		#pragma region Event Methods
		void MeshRenderer::OnRender(DrawingContext* context, Camera* camera)
		{
			Mesh* mesh;
			Material* material;
			GameObject* gameobject;
			IndexBuffer* indices;
			RenderState renderState;
			renderState.Set_PrimitiveType(this->m_pMesh->Get_Topology());
		 
			mesh = this->Get_Mesh();
			if(!mesh)
				return;

			material = this->Get_Material();
			if(!material)
				return;

			gameobject = this->Get_GameObject();
			if(!gameobject)
				return;		

			indices = mesh->Get_IndexBuffer();
			context->SetLayer(this->m_pLayer);
			context->SetRenderState(renderState);
			if(indices)
			{
				if (this->Get_IsTiedToCamera())
					context->DrawIndexed(camera, material, this->m_kLocalToWorld, mesh->Get_VertexBuffer(), indices);
				else
					context->DrawIndexed(camera, material, gameobject->Get_Transform()->Get_LocalToWorldMatrix(), mesh->Get_VertexBuffer(), indices);
				
			}
			else
			{
				if (this->Get_IsTiedToCamera())
					context->Draw(camera, material, this->m_kLocalToWorld, mesh->Get_VertexBuffer());
				else
					context->Draw(camera, material, gameobject->Get_Transform()->Get_LocalToWorldMatrix(), mesh->Get_VertexBuffer());
				
			}
		}
		#pragma endregion
	}
}