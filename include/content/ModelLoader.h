#include "content\Singularity.Content.h"

namespace Singularity
{
	namespace Content
	{
		class ModelLoader
		{
			public:
				#pragma region Methods
				static Singularity::Components::GameObject* LoadModel(String path, IModelImporter* importer = NULL);
				static Singularity::Graphics::Mesh* LoadMesh(String path, int index, IModelImporter* importer = NULL);
				static Singularity::Graphics::Material* LoadMaterial(String path, int index, IModelImporter* importer = NULL);
				#pragma endregion

		};
	}
}