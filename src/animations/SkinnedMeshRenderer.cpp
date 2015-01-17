#include "animations\Singularity.Animations.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, SkinnedMeshRenderer, Singularity::Graphics::MeshRenderer);

		#pragma region Static Variables
		Material* SkinnedMeshRenderer::g_pAnimatedMaterial = NULL;
		#pragma endregion

		#pragma region Constructors and Deconstructors
		SkinnedMeshRenderer::SkinnedMeshRenderer(Mesh* mesh)
			: MeshRenderer(mesh, NULL) 
		{ 
			this->Set_Material(SkinnedMeshRenderer::CreateAnimatedMaterial());
		}		

		SkinnedMeshRenderer::SkinnedMeshRenderer(String name, Mesh* mesh) 
			: MeshRenderer(name, mesh, NULL) 
		{ 
			this->Set_Material(SkinnedMeshRenderer::CreateAnimatedMaterial());
		}
		#pragma endregion

		#pragma region Event Methods
		void SkinnedMeshRenderer::OnRender(DrawingContext* context, Camera* camera)
		{
			SkinnedMesh* mesh;
			GameObject*	gameObject;
			
			mesh = (SkinnedMesh*)this->Get_Mesh();
			if(!mesh) 
				return;

			gameObject = this->Get_GameObject();
			if(!gameObject)
				return;			
			
			this->Get_Material()->SetVariable("_Bones", mesh->Get_SkinTransforms(), mesh->Get_JointCount() * sizeof(Matrix));									
			MeshRenderer::OnRender(context, camera);
		}
		#pragma endregion

		#pragma region Static Methods
		Material* SkinnedMeshRenderer::CreateAnimatedMaterial()
		{
			//HRSRC src;
			//HANDLE bytes;
			//String basicmaterial;
			//char id[5];

			if(SkinnedMeshRenderer::g_pAnimatedMaterial == NULL)
			{
				SkinnedMeshRenderer::g_pAnimatedMaterial = Singularity::Graphics::Material::LoadMaterialFromFile("P:\\gdd_capstone\\Assets\\Effects\\shader_animatedmesh.fx");
				//SkinnedMeshRenderer::g_pAnimatedMaterial = Singularity::Graphics::Material::LoadMaterialFromFile("C:\\Users\\GDDAdmin\\Desktop\\gdd_capstone\\Assets\\Effects\\shader_animatedmesh.fx");
				/*id[0] = '#';
				_itoa_s(IDR_ANIMATED_EFFECT1, &id[1], 4, 10);
				src = ::FindResource(NULL, id, "ANIMATED_EFFECT");
				bytes = ::LoadResource(NULL, src);
				basicmaterial = String((char*)::LockResource(bytes), ::SizeofResource(NULL, src));
				SkinnedMeshRenderer::g_pAnimatedMaterial = Singularity::Graphics::Material::LoadMaterialFromMemory(String("AnimatedMeshMaterial"),  basicmaterial);
				::FreeResource(bytes);
				return SkinnedMeshRenderer::g_pAnimatedMaterial;*/
			}
			return SkinnedMeshRenderer::g_pAnimatedMaterial->Clone();
		}
	}
}