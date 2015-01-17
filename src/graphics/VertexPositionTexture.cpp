#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		VertexDeclaration* VertexPositionTexture::Declaration = VertexPositionTexture::GetVertexDeclaration();
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* VertexPositionTexture::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[2] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0}
			};

			return new VertexDeclaration(vertexElements, 2, sizeof(VertexPositionTexture));
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		VertexPositionTexture::VertexPositionTexture()
			: position(0.0f, 0.0f, 0.0f), textureCoord(0.0f, 0.0f) { }

		VertexPositionTexture::VertexPositionTexture(float x, float y, float z, float u, float v)
			: position(x, y, z), textureCoord(u, v) { }

		VertexPositionTexture::VertexPositionTexture(Vector3 position, Vector2 tex)
			: position(position), textureCoord(tex) { }
		#pragma endregion
	}
}