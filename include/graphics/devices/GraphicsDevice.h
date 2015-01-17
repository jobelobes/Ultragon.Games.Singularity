#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Threading;

namespace Singularity
{
	namespace Graphics
	{
		class GraphicsDevice
		{
			public:
				#pragma region Static Methods
				static void DrawMesh(Mesh* mesh, Vector3 position, Quaternion rotation, Material* material, unsigned layer = 0, Camera* camera = NULL);

				static void DrawTexture(RECT screenRect, Texture2D* texture, Material* material = NULL);

				static void Blit(Texture2D* texture, Material* material = NULL, unsigned pass = -1);
				#pragma endregion
		};
	}
}