#include "gui\Singularity.Gui.h"

namespace Singularity
{
	namespace Gui
	{
		#pragma region Static Variables
		VertexDeclaration* GuiFontVertexDeclaration::Declaration = GuiFontVertexDeclaration::GetVertexDeclaration();
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* GuiFontVertexDeclaration::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[4] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 1, DXGI_FORMAT_R32G32_FLOAT, 0, 20, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 2, DXGI_FORMAT_R32G32_FLOAT, 0, 28, D3D10_INPUT_PER_VERTEX_DATA, 0}
			};

			return new VertexDeclaration(vertexElements, 4, sizeof(GuiFontVertexDeclaration));		
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		GuiFontVertexDeclaration::GuiFontVertexDeclaration()
			: position(0.0f, 0.0f, 0.0f), scale(0.0f, 0.0f), texOffset(0.0f, 0.0f), texSize(0.0f, 0.0f) { }

		GuiFontVertexDeclaration::GuiFontVertexDeclaration(float x, float y, float z, float sx, float sy, float ou, float ov, float u, float v)
			: position(x, y, z), scale(sx, sy), texOffset(ou, ov), texSize(u, v) { }

		GuiFontVertexDeclaration::GuiFontVertexDeclaration(Vector3 position, Vector2 scale, Vector2 texSize, Vector2 texOffset)
			: position(position), scale(scale), texOffset(texOffset), texSize(texSize) { }
		#pragma endregion

		#pragma region Overriden Operator
		bool GuiFontVertexDeclaration::operator== (const GuiFontVertexDeclaration &other) const
		{
			return (memcmp(this, &other, sizeof(GuiFontVertexDeclaration)) == 0);
		}
		#pragma endregion
	}
}