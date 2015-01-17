#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexPositionColor
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
				#pragma endregion

				#pragma region Constructors and Finalizers
				VertexPositionColor();
				VertexPositionColor(float x, float y, float z, float r, float g, float b, float a);
				VertexPositionColor(Vector3 pos, Color color);
				#pragma endregion
		};
	}
}