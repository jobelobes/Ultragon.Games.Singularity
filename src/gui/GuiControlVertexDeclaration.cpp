#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		#pragma region Static Variables
		VertexDeclaration* GuiControlVertexDeclaration::Declaration = GuiControlVertexDeclaration::GetVertexDeclaration();
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* GuiControlVertexDeclaration::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[3] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"POSITION", 1, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 20, D3D10_INPUT_PER_VERTEX_DATA, 0},
			};

			return new VertexDeclaration(vertexElements, 3, sizeof(GuiControlVertexDeclaration));		
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		GuiControlVertexDeclaration::GuiControlVertexDeclaration()
			: position(0.0f, 0.0f, 0.0f), size(0.0f, 0.0f), center(0.0f, 0.0f, 0.0f, 0.0f) { }

		GuiControlVertexDeclaration::GuiControlVertexDeclaration(float x, float y, float z, float sx, float sy, float cx, float cy, float cdx, float cdy)
			: position(x, y, z), size(sx, sy), center(cx, cy, cdx, cdy) { }

		GuiControlVertexDeclaration::GuiControlVertexDeclaration(Vector3 position, Vector2 size, Vector4 center)
			: position(position), size(size), center(center) { }
		#pragma endregion

		#pragma region Overriden Operator
		bool GuiControlVertexDeclaration::operator== (const GuiControlVertexDeclaration &other) const
		{
			return (memcmp(this, &other, sizeof(GuiControlVertexDeclaration)) == 0);
		}
		#pragma endregion
	}
}