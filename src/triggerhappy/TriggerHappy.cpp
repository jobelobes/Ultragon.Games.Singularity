#include "triggerHappy\TriggerHappy.h"
 
using namespace Singularity;
using namespace Singularity::Threading;
using namespace Singularity::Components;
using namespace Singularity::Animations;
using namespace Singularity::Inputs;
using namespace Singularity::Graphics;
using namespace Singularity::Content;
using namespace Singularity::Audio;
using namespace Singularity::Gui;
using namespace Singularity::Physics;
using namespace Singularity::Scripting;
using namespace Singularity::Particles;

#include "triggerHappy\TestingScripts.inc"

void DrawOctNode(Mesh* mesh, Material* material, const OctNode<GameObject*>* node)
{
	if(node == NULL)
		return;

	GameObject* obj = GameObject::Create();
	obj->Get_Transform()->Translate(node->Bounds.Center);
	obj->Get_Transform()->Scale(node->Bounds.Size);
	if(node->Count == 0)
		material->Set_Color(Color(1, 0, 0, 0.1f));
	else
		material->Set_Color(Color(0, 1, 0, 1));

	MeshRenderer* renderer = new MeshRenderer(mesh, material);
	renderer->Set_Layer(node->Count == 0 ? 1 : 2);
		
	obj->AddComponent(renderer);
	if(node->Children != NULL)
	{
		for(int i = 0; i < 8; ++i)
			DrawOctNode(mesh, material->Clone(), &node->Children[i]);
	}
}

void UT_Octree()
{
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

	Mesh* mesh = new Mesh();
	mesh->SetVertices(VertexPositionColor::Declaration, &vertices[0], 8);
	mesh->SetIndices(&indices[0], 17);
	mesh->Set_Topology(PrimitiveTopology::LineStrip);

	Material* material = Material::CreateBasicMaterial();
	material->Set_Pass(1);

	unsigned index = 0;
	unsigned max = 15*15*15;
	GameObject** objects = new GameObject*[max];
	Octree<GameObject*> tree(Bounds(0, 0, 0, 20, 20, 20), 8, 8, max * 3);
	
	printf("UT_Octree Executing...\n");
	
	printf("\tInserting GameObjects...");
	for(int x = -7; x <= 7; ++x)
	{
		for(int y = -7; y <= 7; ++y)
		{
			for(int z = -7; z <= 7; ++z)
			{
				objects[index++] = GameObject::Create();
				tree.insert(Bounds(1, 1, 1, 0, 0, 0), objects[index - 1]);
			}
		}
	}
	printf("Done\n");

	DrawOctNode(mesh, material, tree.root());

	
	/*printf("\tRemoving GameObjects...");
	for(int i = 0; i < max; ++i)
	{
		tree.erase(objects[i]);
		objects[i]->Destroy();
	}
	printf("Done\n");*/
	
	printf("Done\n");
}

class TriggerHappy : public Game
{
	public:
		#pragma region Constructors and Finalizers
		TriggerHappy() : Game() {};
		#pragma endregion
 
		#pragma region Overriden Methods
		void BeginRun()
		{
			char cwd[256];
			_getcwd(&cwd[0], 256);
 
			String appPath = String(cwd);
			appPath += "\\..";
 
			TaskScheduler::Push(Singularity::Graphics::RenderTask::Instantiate());

			TaskScheduler::Push(Singularity::Inputs::InputTask::Instantiate());
			TaskScheduler::Push(Singularity::Animations::AnimationTask::Instantiate());
			TaskScheduler::Push(Singularity::Physics::PhysicsTask::Instantiate());
			TaskScheduler::Push(Singularity::Audio::AudioExtension::Instantiate());
			TaskScheduler::Push(Singularity::Scripting::LuaTask::Instantiate());
			TaskScheduler::Push(Singularity::Gui::GuiExtension::Instantiate());
			//TaskScheduler::Push(Singularity::Networking::NetworkTask::Instantiate());

			//Screen::SetResolution(1024, 768, false);

			String main = appPath;
			//main.append("\\..\\..\\Assets\\Scripts\\Game Scripts\\Main.lua");
			main.append("\\..\\..\\Assets\\Scripts\\Game Scripts\\GamePlay\\main.particles.lua");
			luaL_dofile(Singularity::Scripting::LuaRuntime::Create()->Stack, main.c_str());

			/*GameObject* camera = GameObject::Create();
			camera->AddComponent(new Camera());
			camera->Get_Transform()->Translate(30,5,30);
			camera->Get_Transform()->LookAt(Vector3(0,0,0));*/

			/*main = appPath;
			main.append("\\..\\..\\Assets\\Effects\\shader_axis.fx");
			Material* material = Singularity::Graphics::Material::LoadMaterialFromFile(main.c_str());
			Mesh* mesh = new Mesh();
			VertexPositionColor* vertices = new VertexPositionColor[0];
			vertices[0].position = Vector3(0, 0, 0);
			vertices[0].color = Color(0, 0, 0, 1);
			mesh->SetVertices(VertexPositionColor::Declaration, &vertices[0], 1);
			mesh->Set_Topology(PrimitiveTopology::PointList);
			GameObject* object = GameObject::Create();
			object->AddComponent(new MeshRenderer(mesh, material));*/

			//UT_Octree();
			//UT_GameObjectAllocation();
			//UT_TransformParenting();
		};
		#pragma endregion
};
 
int main(int argc, char* argv[])
{
	try
	{
		//#if defined(DEBUG) | defined(_DEBUG)
		//	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
		//#endif

		TriggerHappy* game = new TriggerHappy();
		game->Run();
	}
	catch(SingularityException& e) 
	{
		#if _DEBUG
		fprintf(stderr, "An exception has occurred: %s\n", boost::diagnostic_information(e).c_str());
		#else
		fprintf(stderr, "An exception has occurred: %s\n", e.what());
		#endif

		system("PAUSE"); // press any key to continue...
	}
 
	return 0;
}