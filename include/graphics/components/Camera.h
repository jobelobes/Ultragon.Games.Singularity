#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class Camera : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Static Variables
				static Singularity::Components::Scene*	g_pScene;
				static Camera*	g_pCurrent;
				#pragma endregion

				#pragma region Variables
				bool						m_bOrthographic;
				Color						m_kBackgroundColor;
				float						m_fFieldOfView;
				float						m_fNearClippingPlane;
				float						m_fFarClippingPlane;
				float						m_fAspect;
				float						m_fWidth;
				float						m_fHeight;

				bool						m_bDirty;
				Matrix						m_kProjection;

				//Singularity::Components::Transform*		m_kTransform;
				Vector3						m_kSnapshotPosition;
				Quaternion					m_kSnapshotRotation;
				CAMERA_DESC					m_kCameraDesc;
				#pragma endregion

				#pragma region Methods
				CAMERA_DESC Get_Description();
				void UpdateCameraSnapshot();
				#pragma endregion
		
			protected:
				#pragma region Event Methods
				void OnPreCull(Singularity::Graphics::Devices::DrawingContext* device);
				void OnPreRender(Singularity::Graphics::Devices::DrawingContext* device);
				void OnRenderImage(Singularity::Graphics::Devices::DrawingContext* device);
				void OnPostRender(Singularity::Graphics::Devices::DrawingContext* device);
				#pragma endregion

				#pragma region Overriden Methods
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Properties
				const bool Get_Orthographic() const;
				void Set_Orthographic(const bool value);

				const Color Get_BackgroundColor() const;
				void Set_BackgroundColor(Color value);

				const float Get_FieldOfView() const;
				void Set_FieldOfView(const float value);

				const float Get_NearClippingPlane() const;
				void Set_NearClippingPlane(const float value);

				const float Get_FarClippingPlane() const;
				void Set_FarClippingPlane(const float value);

				const float Get_Aspect() const;
				void Set_Aspect(const float value);

				const float Get_Width() const;

				const float Get_Height() const;

				Vector3 Get_Forward();

				Vector3 Get_Up();

				Vector3 Get_Right();

				Matrix Get_View();

				Matrix Get_Projection();
				#pragma endregion

				#pragma region Constructors and Finalizers
				Camera(String name = "");
				~Camera();
				#pragma endregion

				#pragma region Static Methods
				void Activate();
				#pragma endregion

				#pragma region Static Methods
				static Camera* Get_Current();
				#pragma endregion

				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
				friend class RenderTask;
				friend class RenderSubTask;
		};

		#include "graphics\components\Camera.inc"
	}
}