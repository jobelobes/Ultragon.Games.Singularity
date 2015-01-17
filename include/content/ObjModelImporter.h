#include "content\Singularity.Content.h"

namespace Singularity
{
	namespace Content
	{
		class ObjModelImporter : public Singularity::Content::IModelImporter
		{
			private: 
				#pragma region Nested Classes
				struct Face
				{
					std::vector<Vector3> vertices;
				};
				#pragma endregion

				#pragma region Variables
				DynamicList<Vector3>	m_pPositions;
				DynamicList<Vector2>	m_pTexCoords;
				DynamicList<Vector3>	m_pNormals;
				DynamicList<Face>		m_pFaces;
				#pragma endregion

				#pragma region Methods
				void ExtractData(std::wifstream* stream);
				#pragma endregion

			protected:
				#pragma region Overriden Properties
				inline const int Get_ModelCount() { return this->m_pPositions.size() > 0 ? 1 : 0; };
				#pragma endregion

				#pragma region IContentImporter Methods
				virtual void LoadFile(String path);
				virtual Singularity::Graphics::Mesh* LoadMesh(unsigned index){ return NULL; };
				virtual Singularity::Graphics::Material* LoadMaterial(unsigned index){ return NULL; };
				#pragma endregion

				#pragma region IModelImporter Methods
				Singularity::Components::GameObject* LoadModel(unsigned index);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				ObjModelImporter();
				~ObjModelImporter();
				#pragma endregion
		};
	}
}