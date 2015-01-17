#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma Static Variables
		VertexDeclaration* VertexPositionNormalTextureBone::Declaration = VertexPositionNormalTextureBone::GetVertexDeclaration();
		#pragma endregion

		#pragma Static Methods
		VertexDeclaration* VertexPositionNormalTextureBone::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[5] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDINDICES", 0, DXGI_FORMAT_R32_UINT, 0, 32, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDWEIGHT", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 36, D3D10_INPUT_PER_VERTEX_DATA, 0}
			};

			return new VertexDeclaration(vertexElements, 5, sizeof(VertexPositionNormalTextureBone));		
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		VertexPositionNormalTextureBone::VertexPositionNormalTextureBone()
			: position(0.0f, 0.0f, 0.0f), normal(0.0f, 0.0f, 0.0f), textureCoord(0.0f, 0.0f), boneIndex(0), boneWeights(0.0f, 0.0f, 0.0f, 0.0f) { }

		VertexPositionNormalTextureBone::VertexPositionNormalTextureBone(float x, float y, float z, float nx, float ny, float nz, float u, float v, unsigned i, float bwx, float bwy, float bwz, float bww)
			: position(x, y, z), normal(nx, ny, nz), textureCoord(u, v), boneIndex(i), boneWeights(bwx, bwy, bwz, bww) { }

		VertexPositionNormalTextureBone::VertexPositionNormalTextureBone(Vector3 position, Vector3 normal, Vector2 tex, unsigned index, Vector4 weight)
			: position(position), normal(normal), textureCoord(tex), boneIndex(index), boneWeights(weight) { }
		#pragma endregion

		#pragma region Overriden Operator
		bool VertexPositionNormalTextureBone::operator== (const VertexPositionNormalTextureBone &other) const
		{
			return (memcmp(this, &other, sizeof(VertexPositionNormalTextureBone)) == 0);
		}
		#pragma endregion
	}
}