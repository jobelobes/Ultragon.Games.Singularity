#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexPositionNormalTexture
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
				#pragma endregion

				#pragma region Constructors and Finalizers
				VertexPositionNormalTexture();
				VertexPositionNormalTexture(float x, float y, float z, float nx, float ny, float nz, float u, float v);
				VertexPositionNormalTexture(Vector3 pos, Vector3 normal, Vector2 tex);
				#pragma endregion

				#pragma region Overriden Operator
				bool operator== (const VertexPositionNormalTexture &other) const;
				#pragma endregion
		};
	}
}