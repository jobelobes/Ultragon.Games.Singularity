#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexPositionColorTexture
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
				Color color;
				Vector2 textureCoord;
				#pragma endregion

				#pragma region Constructors and Finalizers
				VertexPositionColorTexture();
				VertexPositionColorTexture(float x, float y, float z, float r, float g, float b, float a, float u, float v);
				VertexPositionColorTexture(Vector3 pos, Color color, Vector2 tex);
				#pragma endregion
		};
	}
}