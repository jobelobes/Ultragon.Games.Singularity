#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		enum PrimitiveType { Cube = 0, Cone = 1, Cylinder = 2, Sphere = 3, Plane= 4 };

		class Mesh : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Static Variables
				static Mesh*	g_pPrimitives;
				#pragma endregion

				#pragma region Static Methods
				static Mesh* BuildPrimitives();
				#pragma endregion

			protected:
				#pragma region Variables
				Bounds				m_kBounds;

				VertexBuffer*		m_pVertices;
				IndexBuffer*		m_pIndices;
				PrimitiveTopology	m_kTopology;
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				Mesh();
				Mesh(VertexBuffer* vertices, IndexBuffer* indices = NULL);
				~Mesh();
				#pragma endregion

				#pragma region Methods
				const Bounds Get_Bounds() const;

				PrimitiveTopology Get_Topology() const;
				void Set_Topology(PrimitiveTopology value);

				VertexBuffer* Get_VertexBuffer() const;
				void Set_VertexBuffer(VertexBuffer* value);
				
				IndexBuffer* Get_IndexBuffer() const;
				void Set_IndexBuffer(IndexBuffer* value);
				#pragma endregion

				#pragma region Methods
				void Clear();
				virtual Mesh* Clone();

				void RecalculateBounds();

				void SetVertices(VertexDeclaration* declaration, void* data, unsigned count);

				void SetIndices(unsigned* data, unsigned count);
				#pragma endregion

				#pragma region Static Methods
				static Mesh* CreatePrimitive(PrimitiveType type);
				#pragma endregion

				friend class Renderer;
		};

		#include "graphics\Mesh.inc"
	}
}