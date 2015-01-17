#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		VertexDeclaration* AnimationVertex::Declaration = AnimationVertex::GetVertexDeclaration();
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* AnimationVertex::GetVertexDeclaration()
		{
			D3D10_INPUT_ELEMENT_DESC vertexElements[13] = 
			{
				{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDINDICES", 0, DXGI_FORMAT_R32_UINT, 0, 32, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDINDICES", 1, DXGI_FORMAT_R32_UINT, 0, 36, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDINDICES", 2, DXGI_FORMAT_R32_UINT, 0, 40, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDINDICES", 3, DXGI_FORMAT_R32_UINT, 0, 44, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDINDICES", 4, DXGI_FORMAT_R32_UINT, 0, 48, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDWEIGHT", 0, DXGI_FORMAT_R32_FLOAT, 0, 52, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDWEIGHT", 1, DXGI_FORMAT_R32_FLOAT, 0, 56, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDWEIGHT", 2, DXGI_FORMAT_R32_FLOAT, 0, 60, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDWEIGHT", 3, DXGI_FORMAT_R32_FLOAT, 0, 64, D3D10_INPUT_PER_VERTEX_DATA, 0},
				{"BLENDWEIGHT", 4, DXGI_FORMAT_R32_FLOAT, 0, 68, D3D10_INPUT_PER_VERTEX_DATA, 0}
			};

			return new VertexDeclaration(vertexElements, 13, sizeof(AnimationVertex));		
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		AnimationVertex::AnimationVertex()
			: position(0.0f, 0.0f, 0.0f), normal(0.0f, 0.0f, 0.0f), texCoord(0.0f, 0.0f) { }

		AnimationVertex::AnimationVertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
			: position(x, y, z), normal(nx, ny, nz), texCoord(u, v) { }

		AnimationVertex::AnimationVertex(Vector3 position, Vector3 normal, Vector2 tex)
			: position(position), normal(normal), texCoord(tex) { }
		#pragma endregion

		#pragma region Overriden Operator
		bool AnimationVertex::operator== (const AnimationVertex &other) const
		{
			return (memcmp(this, &other, sizeof(AnimationVertex)) == 0);
		}
		#pragma endregion
	}
}