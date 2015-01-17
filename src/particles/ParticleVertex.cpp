#include "particles\Singularity.Particles.h"

using namespace Singularity;
using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Particles
	{
		#pragma region Static Variables
		VertexDeclaration* ParticleVertex::g_pVertexDeclaration = NULL;
		#pragma endregion

		#pragma region Static Methods
		VertexDeclaration* ParticleVertex::GetVertexDeclaration()
		{
			if(ParticleVertex::g_pVertexDeclaration == NULL)
			{
				D3D10_INPUT_ELEMENT_DESC vertexElements[9] =
				{
					{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"TEXCOORD", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 28, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"TEXCOORD", 1, DXGI_FORMAT_R32G32B32_FLOAT, 0, 40, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"PSIZE", 0, DXGI_FORMAT_R32_FLOAT, 0, 52, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"TEXCOORD", 2, DXGI_FORMAT_R32_FLOAT, 0, 56, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"TEXCOORD", 3, DXGI_FORMAT_R32_FLOAT, 0, 60, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"TEXCOORD", 4, DXGI_FORMAT_R32_FLOAT, 0, 64, D3D10_INPUT_PER_VERTEX_DATA, 0},
					{"TEXCOORD", 5, DXGI_FORMAT_R32_FLOAT, 0, 68, D3D10_INPUT_PER_VERTEX_DATA, 0}
				};

				ParticleVertex::g_pVertexDeclaration = new VertexDeclaration(vertexElements, 9, sizeof(ParticleVertex));
			}

			return ParticleVertex::g_pVertexDeclaration;
		}
		#pragma endregion

		#pragma region Constructors and Deconstructors
		ParticleVertex::ParticleVertex()
			: position(0.0f, 0.0f, 0.0f), color(0xffffffff), velocity(0.0f, 0.0f, 0.0f), acceleration(0.0f, 0.0f, 0.0f), size(0.5f), timestamp(0), lifetime(10.0f), rotation(0.0f), type(1)
		{}

		ParticleVertex::ParticleVertex(float x, float y, float z, float velX, float velY, float velZ, float accX, float accY, float accZ, float r, float g, float b, float a, float size, float timestamp, float lifetime, float rotation, float type)
			: position(x, y, z), color(r, g, b, a), velocity(velX, velY, velZ), acceleration(accX, accY, accZ), size(size), timestamp(timestamp), lifetime(lifetime), rotation(rotation), type(type)
		{}

		ParticleVertex::ParticleVertex(Vector3 position, Vector3 velocity, Vector3 accleration, Color color, float size, float timestamp, float lifetime, float rotation, float type)
			: position(position), color(color), velocity(velocity), acceleration(acceleration), size(size), timestamp(timestamp), lifetime(lifetime), rotation(rotation), type(type)
		{ }

		#pragma endregion
	}
}