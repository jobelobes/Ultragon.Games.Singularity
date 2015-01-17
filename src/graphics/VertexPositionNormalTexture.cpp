#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		VertexDeclaration* VertexPositionNormalTexture::Declaration = VertexPositionNormalTexture::GetVertexDeclaration();
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* VertexPositionNormalTexture::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[3] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D10_INPUT_PER_VERTEX_DATA, 0}
			};

			return new VertexDeclaration(vertexElements, 3, sizeof(VertexPositionNormalTexture));		
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		VertexPositionNormalTexture::VertexPositionNormalTexture()
			: position(0.0f, 0.0f, 0.0f), normal(0.0f, 0.0f, 0.0f), texCoord(0.0f, 0.0f) { }

		VertexPositionNormalTexture::VertexPositionNormalTexture(float x, float y, float z, float nx, float ny, float nz, float u, float v)
			: position(x, y, z), normal(nx, ny, nz), texCoord(u, v) { }

		VertexPositionNormalTexture::VertexPositionNormalTexture(Vector3 position, Vector3 normal, Vector2 tex)
			: position(position), normal(normal), texCoord(tex) { }
		#pragma endregion

		#pragma region Overriden Operator
		bool VertexPositionNormalTexture::operator== (const VertexPositionNormalTexture &other) const
		{
			return (memcmp(this, &other, sizeof(VertexPositionNormalTexture)) == 0);
		}
		#pragma endregion
	}
}