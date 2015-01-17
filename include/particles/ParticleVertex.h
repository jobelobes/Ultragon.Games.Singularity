#include "Singularity.Particles.h"

namespace Singularity
{
	namespace Particles
	{
		class ParticleVertex
		{
			private:
				#pragma region Static Variables
				static Singularity::Graphics::VertexDeclaration* g_pVertexDeclaration;
				#pragma endregion

			public:
				#pragma region Static Methods
				static Singularity::Graphics::VertexDeclaration* GetVertexDeclaration();
				#pragma endregion

				#pragma region Variables
				Vector3 position;
				Color	color;
				Vector3 velocity;
				Vector3 acceleration;
				float	size;
				float	timestamp;
				float	lifetime;
				float	rotation;
				float	type;
				#pragma endregion

				#pragma region Constructors and Finalizers
				ParticleVertex();
				ParticleVertex(float x, float y, float z, float velX, float velY, float velZ, float accX, float accY, float accZ, float r, float g, float b, float a, float size, float timestamp, float lifetime, float rotation, float type);
				ParticleVertex(Vector3 position, Vector3 velocity, Vector3 acceleration, Color color, float size, float timstamp, float lifetime, float rotation, float type);
				#pragma endregion
		};
	}
}