#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexPositionTexture
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
				Vector2 textureCoord;
				#pragma endregion

				#pragma region Constructors and Finalizers
				VertexPositionTexture();
				VertexPositionTexture(float x, float y, float z, float u, float v);
				VertexPositionTexture(Vector3 pos, Vector2 tex);
				#pragma endregion
		};
	}
}