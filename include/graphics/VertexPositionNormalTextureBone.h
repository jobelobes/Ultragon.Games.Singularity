#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexPositionNormalTextureBone
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
				Vector2 textureCoord;
				unsigned boneIndex;
				Vector4 boneWeights;
				#pragma endregion

				#pragma region Constructors and Finalizers
				VertexPositionNormalTextureBone();
				VertexPositionNormalTextureBone(float x, float y, float z, float nx, float ny, float nz, float u, float v, unsigned i, float bwx, float bwy, float bwz, float bww);
				VertexPositionNormalTextureBone(Vector3 pos, Vector3 normal, Vector2 tex, unsigned indice, Vector4 weight);
				#pragma endregion

				#pragma region Overriden Operator
				bool operator== (const VertexPositionNormalTextureBone &other) const;
				#pragma endregion
		};
	}
}