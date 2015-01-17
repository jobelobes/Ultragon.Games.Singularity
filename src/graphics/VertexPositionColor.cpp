#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		VertexDeclaration* VertexPositionColor::Declaration = VertexPositionColor::GetVertexDeclaration();
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* VertexPositionColor::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[2] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0}
			};

			return new VertexDeclaration(vertexElements, 2, sizeof(VertexPositionColor));
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		VertexPositionColor::VertexPositionColor()
			: position(0.0f, 0.0f, 0.0f), color(0xffffffff) { }

		VertexPositionColor::VertexPositionColor(float x, float y, float z, float r, float g, float b, float a)
			: position(x, y, z), color(r, g, b, a) { }

		VertexPositionColor::VertexPositionColor(Vector3 position, Color color)
			: position(position), color(color) { }
		#pragma endregion
	}
}