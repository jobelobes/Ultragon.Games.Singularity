#include "physics\Singularity.Physics.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Physics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Physics, BoxCollider, Collider);

		#pragma region Static Variables
		Mesh* BoxCollider::g_pBoundingBox = NULL;
		#pragma endregion

		#pragma region Static Methods
		Mesh* BoxCollider::CreateBoundingBoxMesh()
		{
			Mesh* mesh = NULL;

			VertexPositionColor vertices[8];
			vertices[0].position = Vector3(-0.5, -0.5, -0.5); vertices[0].color = Color(1,1,1,1);
			vertices[1].position = Vector3( 0.5, -0.5, -0.5); vertices[1].color = Color(1,1,1,1);
			vertices[2].position = Vector3(-0.5,  0.5, -0.5); vertices[2].color = Color(1,1,1,1);
			vertices[3].position = Vector3( 0.5,  0.5, -0.5); vertices[3].color = Color(1,1,1,1);
			vertices[4].position = Vector3(-0.5, -0.5,  0.5); vertices[4].color = Color(1,1,1,1);
			vertices[5].position = Vector3( 0.5, -0.5,  0.5); vertices[5].color = Color(1,1,1,1);
			vertices[6].position = Vector3(-0.5,  0.5,  0.5); vertices[6].color = Color(1,1,1,1);
			vertices[7].position = Vector3( 0.5,  0.5,  0.5); vertices[7].color = Color(1,1,1,1);

			unsigned indices[17] = {0,1,3,2,0,4,6,2,3,7,5,1,0,4,5,7,6};

			mesh = new Mesh();
			mesh->SetVertices(VertexPositionColor::Declaration, &vertices[0], 8);
			mesh->SetIndices(&indices[0], 17);
			return mesh;
		}
		#pragma endregion

		#pragma region Overriden Methods
		void BoxCollider::OnComponentAdded(GameObject* gameObject)
		{
			//GameObject* child;
			Collider::OnComponentAdded(gameObject);

			//Material* material = Material::CreateBasicMaterial();
			//material->Set_Color(Color(1,0,0,1));
			//material->Set_Pass(1);

			//if(BoxCollider::g_pBoundingBox == NULL)
			//	BoxCollider::g_pBoundingBox = BoxCollider::CreateBoundingBoxMesh();

			//Mesh* mesh = BoxCollider::g_pBoundingBox->Clone();
			//mesh->Set_Topology(PrimitiveTopology::LineStrip);

			//MeshRenderer* renderer = new MeshRenderer(mesh, material);
			//renderer->Set_Layer(10);

			//child = GameObject::Create("BoundingBox", gameObject);
			//child->AddComponent(renderer);
			//child->Get_Transform()->Set_LocalPosition(this->m_kCenter);
			//child->Get_Transform()->Set_Scale(this->m_kSize * 1.005f);
			//child->Get_Transform()->Set_Rotation(this->Get_Rotation());
		}
		#pragma endregion
	}
}