#include "content\Singularity.Content.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Content
	{
		#pragma region Static Methods
		GameObject* ModelLoader::LoadModel(String path, IModelImporter* importer)
		{
			int find;
			int meshCount;

			if(importer == NULL)
			{
				if((find = path.rfind(".obj")) != -1)
					importer = new ObjModelImporter();
				else if((find = path.rfind(".smurf")) != -1)
					importer = new SmurfModelImporter();
				//else if((index = path.rfind(".fbx")) != -1)
				//	importer = new FbxModelImporter();
			}

			importer->LoadFile(path);
			meshCount = importer->Get_ModelCount();
			if(meshCount == 0)
				return NULL;

			GameObject* object = GameObject::Create("");
			for(int i = 0; i < meshCount; ++i)
				object->AttachChild(importer->LoadModel(i));

			((SmurfModelImporter*)importer)->LoadCollisionData(object);
			return object;
		}

		Singularity::Graphics::Mesh* ModelLoader::LoadMesh(String path, int index, IModelImporter* importer)
		{
			int find;
			int meshCount;

			if(importer == NULL)
			{
				if((find = path.rfind(".obj")) != -1)
					importer = new ObjModelImporter();
				else if((find = path.rfind(".smurf")) != -1)
					importer = new SmurfModelImporter();
				//else if((index = path.rfind(".fbx")) != -1)
				//	importer = new FbxModelImporter();
			}

			importer->LoadFile(path);
			meshCount = importer->Get_ModelCount();
			if(meshCount == 0 || index > meshCount)
				return NULL;

			return importer->LoadMesh(index);
		}

		Singularity::Graphics::Material* ModelLoader::LoadMaterial(String path, int index, IModelImporter* importer)
		{
			int find;
			int meshCount;

			if(importer == NULL)
			{
				if((find = path.rfind(".obj")) != -1)
					importer = new ObjModelImporter();
				else if((find = path.rfind(".smurf")) != -1)
					importer = new SmurfModelImporter();
				//else if((index = path.rfind(".fbx")) != -1)
				//	importer = new FbxModelImporter();
			}

			importer->LoadFile(path);
			meshCount = importer->Get_ModelCount();
			if(meshCount == 0 || index > meshCount)
				return NULL;

			return importer->LoadMaterial(index);
		}
		#pragma endregion
	}
}