#include "content\Singularity.Content.h"

namespace Singularity
{
	namespace Content
	{
		class IModelImporter : public Singularity::Content::IContentImporter
		{
			protected:
				#pragma region Properties
				virtual const int Get_ModelCount() = 0;
				#pragma endregion

				#pragma region Methods
				virtual Singularity::Components::GameObject* LoadModel(unsigned index) = 0;
				virtual Singularity::Graphics::Mesh* LoadMesh(unsigned index) = 0;
				virtual Singularity::Graphics::Material* LoadMaterial(unsigned index) = 0;
				#pragma endregion

				friend class ModelLoader;
		};
	}
}