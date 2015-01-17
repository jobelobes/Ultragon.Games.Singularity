#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Graphics
	{
		class SkinnedMeshRenderer : public Singularity::Graphics::MeshRenderer
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static Singularity::Graphics::Material*		g_pAnimatedMaterial;
				#pragma endregion

				#pragma region Variables
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnRender(DrawingContext* context, Camera* camera);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				SkinnedMeshRenderer(Singularity::Graphics::Mesh* mesh = NULL);
				SkinnedMeshRenderer(String name, Singularity::Graphics::Mesh* mesh = NULL);
				virtual ~SkinnedMeshRenderer() { }
				#pragma endregion

				#pragma region Static Methods
				static Singularity::Graphics::Material* CreateAnimatedMaterial();
				#pragma endregion
		};
	}
}