#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class Axis : public Singularity::Graphics::MeshRenderer
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static Mesh* g_pMesh;
				#pragma endregion

				#pragma region Static Methods
				Mesh* CreateAxisMesh();
				#pragma endregion

			protected:
				#pragma region Event Methods
				void OnRender(DrawingContext* context, Camera* camera);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				Axis(String name = "");
				~Axis() { }
				#pragma endregion
		};
	}
}