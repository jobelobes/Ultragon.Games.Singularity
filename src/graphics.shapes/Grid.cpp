#include "graphics.shapes\Singularity.Graphics.Shapes.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Graphics
	{
		namespace Shapes
		{
			/*unsigned	m_iGridSize;
			float		m_fGridScale;
			Color		m_kColor;
			bool		m_bDirty;
			Mesh*		m_pMesh;*/

			#pragma region Constructors and Finalizers
			Grid::Grid(String name, const unsigned gridSize, const float gridScale, const Color color)
				: GameObject(name), m_iGridSize(gridSize), m_fGridScale(gridScale), m_kColor(color), m_bDirty(true), m_pMaterial(NULL), m_pRenderer(NULL)
			{
				this->m_pMaterial = Material::CreateBasicMaterial();
				this->m_pMaterial->Set_Pass(0);
				this->m_pMaterial->Set_Color(color);
				this->m_pMaterial->SetVariable("VertexColorEnabled", true);

				this->m_pRenderer = new MeshRenderer();
				this->m_pRenderer->Set_Material(this->m_pMaterial);
				this->m_pRenderer->Set_Mesh(this->_BuildMesh(this->m_iGridSize, this->m_fGridScale));

				this->AddComponent(this->m_pRenderer);
			}
			
			Grid::~Grid()
			{

			}
			#pragma endregion

			#pragma region Methods
			Mesh* Grid::_BuildMesh(unsigned gridSize, float gridScale)
			{
				Mesh* mesh;
				unsigned i, index, size;
				float length, halfLength;
				VertexPositionNormalTexture* vertices;

				size = gridSize + 1;
				length = size * gridScale;
				halfLength = length * 0.5f;
				index = 0;
				vertices = new VertexPositionNormalTexture[size * 4];
				
				for(i = 0; i < size; ++i)
				{
					vertices[index].position = Vector3(-halfLength, 0.0f, i * gridScale - halfLength);
					vertices[index].normal = Vector3(0,1,0);
					vertices[index++].texCoord = Vector2(0,1);

					vertices[index].position = Vector3(halfLength, 0.0f, i * gridScale - halfLength);
					vertices[index].normal = Vector3(0,1,0);
					vertices[index++].texCoord = Vector2(0,1);

					vertices[index].position = Vector3(i * gridScale - halfLength, 0.0f, -halfLength);
					vertices[index].normal = Vector3(0,1,0);
					vertices[index++].texCoord = Vector2(0,1);

					vertices[index].position = Vector3(i * gridScale - halfLength, 0.0f, halfLength);
					vertices[index].normal = Vector3(0,1,0);
					vertices[index++].texCoord = Vector2(0,1);
				}

				mesh = new Mesh();
				mesh->Set_Topology(PrimitiveTopology::LineList);
				mesh->SetVertices(VertexPositionNormalTexture::Declaration, vertices, index);

				delete [] vertices;

				return mesh;
			}
			#pragma endregion

			#pragma region Overriden Methods
			void Grid::OnGameObjectAdded(GameObject* parent)
			{
				if(this->m_bDirty)
				{
					this->m_pRenderer->Set_Mesh(this->_BuildMesh(this->m_iGridSize, this->m_fGridScale));
					this->m_bDirty = false;
				}
			}
			#pragma endregion
		}
	}
}