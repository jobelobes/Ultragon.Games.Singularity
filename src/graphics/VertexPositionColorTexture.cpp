#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		VertexDeclaration* VertexPositionColorTexture::Declaration = VertexPositionColorTexture::GetVertexDeclaration();
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* VertexPositionColorTexture::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[3] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 28, D3D10_INPUT_PER_VERTEX_DATA, 0}
			};

			return new VertexDeclaration(vertexElements, 3, sizeof(VertexPositionColorTexture));			
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		VertexPositionColorTexture::VertexPositionColorTexture()
			: position(0.0f, 0.0f, 0.0f), color(0xffffffff), textureCoord(0.0f, 0.0f) { }

		VertexPositionColorTexture::VertexPositionColorTexture(float x, float y, float z, float r, float g, float b, float a, float u, float v)
			: position(x, y, z), color(r,g,b,a), textureCoord(u,v) { }

		VertexPositionColorTexture::VertexPositionColorTexture(Vector3 position, Color color, Vector2 tex)
			: position(position), color(color), textureCoord(tex) { }
		#pragma endregion
	}
}