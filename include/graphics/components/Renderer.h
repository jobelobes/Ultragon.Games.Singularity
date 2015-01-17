#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class Renderer : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Variables
				bool				m_bVisible;
				Material*			m_pMaterial;
				RenderCallback		m_pCallback;
				Bounds				m_kBounds;
				#pragma endregion

				#pragma region Event Methods
				void InternalOnRender(DrawingContext* context, Camera* camera);
				void UpdateRendererSnapshot();
				#pragma endregion

			protected:
				#pragma region Constructors and Finalizers
				Renderer(String name = "", Material* material = NULL) : Component(name), m_bVisible(true), m_pMaterial(material), m_pCallback(NULL), m_kBounds(Bounds::Empty), m_bTiedToCamera(false) { }
				#pragma endregion

				#pragma region Variables
				bool				m_bTiedToCamera;
				Matrix				m_kLocalToWorld;
				#pragma endregion

				#pragma region Event Methods
				virtual void OnRender(DrawingContext* context, Camera* camera) = 0;
				virtual void OnBecameVisible() { };
				virtual void OnBecameInvisible() { };
				#pragma endregion

				#pragma region Overriden Methods
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				~Renderer() { }
				#pragma endregion

				#pragma region Properties
				const bool Get_IsVisible() const;

				Material* Get_Material() const;
				void Set_Material(Material* value);

				const bool Get_IsTiedToCamera() const;
				void Set_IsTiedToCamera(bool value);

				const Bounds Get_Bounds() const;
				#pragma endregion

				#pragma region Methods
				void RegisterCallback(RenderCallback value);
				#pragma endregion

				friend class RenderSubTask;
				friend class RenderTask;
		};

		#include "graphics\components\Renderer.inc"
	}
}