#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Graphics
	{
		class AnimationVertex
		{
			private:
				#pragma region Static Methods
				static VertexDeclaration* GetVertexDeclaration();
				#pragma endregion

			public:
				#pragma region Static Variables
				static VertexDeclaration* Declaration;
				#pragma endregion				

				#pragma region Variables				
				Vector3 position;
				Vector3 normal;
				Vector2 texCoord;
				unsigned blendIndices[5];
				float blendWeights[5];				
				#pragma endregion

				#pragma region Constructors and Finalizers
				AnimationVertex();
				AnimationVertex(float x, float y, float z, float nx, float ny, float nz, float u, float v);
				AnimationVertex(Vector3 pos, Vector3 normal, Vector2 tex);
				#pragma endregion

				#pragma region Overriden Operator
				bool operator== (const AnimationVertex &other) const;
				#pragma endregion
		};
	}
}