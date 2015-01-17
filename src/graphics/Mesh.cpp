#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, Mesh, Singularity::Object);

		#pragma region Static Variables
		Mesh* Mesh::g_pPrimitives = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		Mesh::Mesh() 
			: m_pVertices(NULL), m_pIndices(NULL), m_kBounds(Bounds::Empty), m_kTopology(PrimitiveTopology::TriangleList)  { }

		Mesh::Mesh(VertexBuffer* vertices, IndexBuffer* indices)
			: m_pVertices(vertices), m_pIndices(indices), m_kBounds(Bounds::Empty), m_kTopology(PrimitiveTopology::TriangleList) { }

		Mesh::~Mesh() { }
		#pragma endregion

		#pragma region Methods
		void Mesh::Clear()
		{

		}

		void Mesh::RecalculateBounds()
		{

		}

		void Mesh::SetVertices(VertexDeclaration* declaration, void* data, unsigned count)
		{
			if(this->m_pVertices != NULL)
			{ }

			this->m_pVertices = new VertexBuffer(declaration, count);
			this->m_pVertices->SetData(data);
		}

		void Mesh::SetIndices(unsigned* data, unsigned count)
		{
			if(this->m_pIndices != NULL)
			{ }

			this->m_pIndices = new IndexBuffer(count);
			this->m_pIndices->SetData(data);
		}

		Mesh* Mesh::Clone()
		{
			Mesh* mesh = new Mesh();
			mesh->m_kBounds = this->m_kBounds;
			mesh->m_pVertices = this->m_pVertices;
			mesh->m_pIndices= this->m_pIndices;
			mesh->m_kTopology = this->m_kTopology;
			return mesh;
		}
		#pragma endregion

		#pragma region Static Methods
		Mesh* Mesh::CreatePrimitive(PrimitiveType type)
		{
			if(Mesh::g_pPrimitives == NULL)
				Mesh::g_pPrimitives = Mesh::BuildPrimitives();
			return Mesh::g_pPrimitives[type].Clone();
		}

		Mesh* Mesh::BuildPrimitives()
		{
			HRSRC src;
			HANDLE bytes;
			String basicmaterial;
			char id[5];

			Mesh* meshes = new Mesh[5];
			
			for(int i = 0; i < 5; ++i)
			{
				id[0] = '#';
				_itoa_s(IDR_BINARY1 + i * 2, &id[1], 4, 10);
				src = ::FindResource(NULL, id, "Binary");
				bytes = ::LoadResource(NULL, src);
				meshes[i].SetIndices((unsigned*)::LockResource(bytes), ::SizeofResource(NULL, src) / sizeof(unsigned));
				::FreeResource(bytes);

				id[0] = '#';
				_itoa_s(IDR_BINARY1 + i * 2 + 1, &id[1], 4, 10);
				src = ::FindResource(NULL, id, "Binary");
				bytes = ::LoadResource(NULL, src);
				meshes[i].SetVertices(VertexPositionNormalTexture::Declaration, (VertexPositionNormalTexture*)::LockResource(bytes), ::SizeofResource(NULL, src) / sizeof(VertexPositionNormalTexture));
				::FreeResource(bytes);
			}

			return meshes;
		}
		#pragma endregion
	}
}