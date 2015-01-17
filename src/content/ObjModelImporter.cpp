#include "content\Singularity.Content.h"

using namespace Singularity;
using namespace Singularity::Components;
using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Content
	{
		#pragma region Constructors and Finalizers
		ObjModelImporter::ObjModelImporter()
		{
		}

		ObjModelImporter::~ObjModelImporter()
		{
		}
		#pragma endregion

		#pragma region Methods
		void ObjModelImporter::ExtractData(std::wifstream* stream)
		{
			int index;
			UINT subsets;
			Vector3 values;
			Face face;
			wchar_t* token;
			wchar_t* buffer;
			wchar_t* subToken;
			wchar_t* cmd;

			subsets = 0;
			cmd = new wchar_t[256];
			buffer = new wchar_t[256];

			while(stream->good())
			{
				stream->get(cmd, 256, ' ');
				if( 0 == wcscmp( cmd, L"v" ) ) // Vertex Position
				{
					float x, y, z;
					(*stream) >> x >> y >> z;
					this->m_pPositions.push_back( Vector3( x, y, z ) );
				}
				else if( 0 == wcscmp( cmd, L"vt" ) ) // Vertex TexCoord
				{
					float u, v;
					(*stream) >> u >> v;
					this->m_pTexCoords.push_back( Vector2( u, 1 - v ) );
				}
				else if( 0 == wcscmp( cmd, L"vn" ) ) // Vertex Normal
				{
					float x, y, z;
					(*stream) >> x >> y >> z;
					this->m_pNormals.push_back( Vector3( x, y, z ) );
				}
				else if( 0 == wcscmp( cmd, L"f" ) ) // Face
				{	
					token = NULL;
					stream->get(buffer, 256);

					if(buffer[0] == L' ') buffer++;

					while((token = wcstok_s(buffer, L" ", &buffer)) != NULL)
					{
						index = 0;
						values = Vector3(0,0,0);
						subToken = NULL;
						while((subToken = wcstok_s(token, L"/", &token)) != NULL)
						{
							*(&values[index]) = (float)_wtof(subToken);
							index++;

							if(token[0] == L'/')
								index++;
						}

						face.vertices.push_back(values);
					}
					this->m_pFaces.push_back(face);
				}

				stream->ignore( 1000, '\n' );
			}

			delete [] cmd;
			delete [] buffer;
		}
		#pragma endregion

		#pragma region IContentImporter Methods
		void ObjModelImporter::LoadFile(String path)
		{
			std::wifstream objStream;

			this->m_pPositions.clear();
			this->m_pTexCoords.clear();
			this->m_pNormals.clear();
			this->m_pFaces.clear();

			objStream.open(path.c_str(), std::ios::in);
			{
				if( !objStream || !objStream.is_open())
					throw SingularityException("Unable to locate or open the asset defined.");
				
				this->ExtractData(&objStream);
			}
			objStream.close();
		}
		#pragma endregion

		#pragma region IModelImporter Methods
		GameObject* ObjModelImporter::LoadModel(unsigned index)
		{
			GameObject* obj;
			Mesh* newMesh;
			DynamicList<VertexPositionNormalTexture> vertices;
			DynamicList<UINT> indices;
			DynamicList<UINT> attributes;
			VertexPositionNormalTexture* vertBuff;
			unsigned* indexBuff;
			Face face;
			unsigned i, j, size;

			if(this->m_pPositions.size() == 0 || index > 0)
				return NULL;

			for(i = 0; i < this->m_pFaces.size(); i++)
			{
				face = this->m_pFaces[i];
				size = face.vertices.size();
				if(size < 3 || size > 4)
					throw SingularityException("Unable to load obj with this format.");

				for(j = 0; j < face.vertices.size(); j++)
				{
					VertexPositionNormalTexture element;
					element.position = this->m_pPositions[(int)face.vertices[j].x - 1];
					element.texCoord = ((int)face.vertices[j].y != 0) ? this->m_pTexCoords[(int)face.vertices[j].y - 1] : Vector2(0,0);
					element.normal = ((int)face.vertices[j].z != 0) ? this->m_pNormals[(int)face.vertices[j].z - 1] : Vector3(0, 0, 0);

					vertices.push_back(element);
				}

				int vertSize = vertices.size();
				if(size == 3)
				{
					indices.push_back(vertSize - 1);
					indices.push_back(vertSize - 2);
					indices.push_back(vertSize - 3);
					attributes.push_back(0);
				}
				else
				{
					//face 1
					indices.push_back(vertSize - 3);
					indices.push_back(vertSize - 4);
					indices.push_back(vertSize - 1);
					attributes.push_back(0);

					//face 2
					indices.push_back(vertSize - 1);
					indices.push_back(vertSize - 2);
					indices.push_back(vertSize - 3);
					attributes.push_back(0);
				}
			}

			//Create buffers.
			vertBuff = new VertexPositionNormalTexture[vertices.size()];
			for(i = 0; i < vertices.size(); i++)
				vertBuff[i] = vertices[i];

			indexBuff = new unsigned[indices.size()];
			for(i = 0; i < indices.size(); i++)
				indexBuff[i] = indices[i];

			newMesh = new Mesh();
			newMesh->SetVertices(VertexPositionNormalTexture::Declaration, vertBuff, vertices.size());
			newMesh->SetIndices(indexBuff, indices.size());
			
			delete [] vertBuff;
			delete [] indexBuff;

			obj = GameObject::Create("obj.loader");
			obj->AddComponent(new MeshRenderer(newMesh));
			return obj;
		}
		#pragma endregion
	}
}