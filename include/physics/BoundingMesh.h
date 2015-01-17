#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace BoundingVolumes
		{
		class Mesh
		{
			public:
				#pragma region Variables
				unsigned VertexCount;
				void* Vertices;
				unsigned IndexCount;
				unsigned* Indices;
				#pragma endregion

				#pragma region Constructors and Finalizers
				BoundingMesh(unsigned vertexCount, void* vertices, unsigned indexCount, unsigned* indices)
					: VertexCount(vertexCount), Vertices(vertices), IndexCount(indexCount), Indices(indices) { };
				#pragma endregion

				#pragma region Static Methods
				static bool Intersects(BoundingMesh& mesh0, BoundingMesh& mesh1, Vector3& point, Vector3& normal);
				#pragma endregion
		};
	}
}