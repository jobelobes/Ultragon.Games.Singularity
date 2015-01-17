// 3/30

//position, size, offset, texture

#include "gui\Singularity.Gui.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Gui
	{
		class GuiControlVertexDeclaration
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
				Vector2 size;
				Vector4 center;
				#pragma endregion

				#pragma region Constructors and Finalizers
				GuiControlVertexDeclaration();
				GuiControlVertexDeclaration(float x, float y, float z, float sx, float sy, float cx, float cy, float cdx, float cdy);
				GuiControlVertexDeclaration(Vector3 pos, Vector2 size, Vector4 center);
				#pragma endregion

				#pragma region Overridden Operator
				bool operator== (const GuiControlVertexDeclaration &other) const;
				#pragma endregion
		};
	}
}