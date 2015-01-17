#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, Axis, Singularity::Graphics::MeshRenderer);

		#pragma region Static Variables
		Mesh* Axis::g_pMesh = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		Axis::Axis(String name)
			: MeshRenderer(name, Axis::CreateAxisMesh(), Material::CreateBasicMaterial()) 
		{
			this->Get_Material()->Set_Pass(1);
		}
		#pragma endregion

		#pragma region Event Methods
		void Axis::OnRender(DrawingContext* context, Camera* camera)
		{
			RenderState renderState;
			renderState.Set_CullMode(CullMode::None);
			renderState.Set_PrimitiveType(PrimitiveTopology::LineList);

			context->SetLayer(99);
			context->SetRenderState(renderState);
			context->Draw(camera, this->Get_Material(), this->Get_GameObject()->Get_Transform()->Get_LocalToWorldMatrix(), this->Get_Mesh()->Get_VertexBuffer());
		}
		#pragma endregion

		#pragma region Static Methods
		Mesh* Axis::CreateAxisMesh()
		{
			if(Axis::g_pMesh == NULL)
			{
				Axis::g_pMesh = new Mesh();

				VertexPositionColor vertices[6];
				// x axis
				vertices[0].position = Vector3(0,0,0);
				vertices[0].color = Color(1,0,0,1);
				vertices[1].position = Vector3(1,0,0);
				vertices[1].color = Color(1,0,0,1);

				// y axis
				vertices[2].position = Vector3(0,0,0);
				vertices[2].color = Color(0,1,0,1);
				vertices[3].position = Vector3(0,1,0);
				vertices[3].color = Color(0,1,0,1);

				// z axis
				vertices[4].position = Vector3(0,0,0);
				vertices[4].color = Color(0,0,1,1);
				vertices[5].position = Vector3(0,0,1);
				vertices[5].color = Color(0,0,1,1);

				Axis::g_pMesh->SetVertices(VertexPositionColor::Declaration, &vertices[0], 6);
				return Axis::g_pMesh;
			}
			return Axis::g_pMesh->Clone();

		}
		#pragma endregion
	}
}