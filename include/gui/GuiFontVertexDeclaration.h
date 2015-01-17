// 3/30

//position, size, offset, texture

#include "gui\Singularity.Gui.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Gui
	{
		class GuiFontVertexDeclaration
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
				Vector2 scale;
				Vector2 texSize;
				Vector2 texOffset;
				#pragma endregion

				#pragma region Constructors and Finalizers
				GuiFontVertexDeclaration();
				GuiFontVertexDeclaration(float x, float y, float z, float sx, float sy, float ou, float ov, float u, float v);
				GuiFontVertexDeclaration(Vector3 pos, Vector2 scale, Vector2 texOffset, Vector2 texSize);
				#pragma endregion

				#pragma region Overriden Operator
				bool operator== (const GuiFontVertexDeclaration &other) const;
				#pragma endregion
		};
	}
}