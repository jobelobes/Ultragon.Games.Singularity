#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class MeshRenderer : public Singularity::Graphics::Renderer
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				unsigned						m_pLayer;
				bool							m_bWireFrame;
				Singularity::Graphics::Mesh*	m_pMesh;
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnRender(DrawingContext* context, Camera* camera);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				MeshRenderer(Mesh* mesh = NULL, Material* material = NULL) : Renderer("", material), m_pLayer(0), m_pMesh(mesh) { }
				MeshRenderer(String name, Mesh* mesh = NULL, Material* material = NULL) : Renderer(name, material), m_pLayer(0), m_pMesh(mesh) { }
				~MeshRenderer() { }
				#pragma endregion

				#pragma region Properties
				Mesh* Get_Mesh() const;
				void Set_Mesh(Mesh* value);

				unsigned Get_Layer() const;
				void Set_Layer(unsigned value);
				#pragma endregion

				friend class RenderTask;
		};

		#include "graphics\components\MeshRenderer.inc"
	}
}