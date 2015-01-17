#include "graphics\Singularity.Graphics.h"

using namespace Singularity;
using namespace Singularity::Components;

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, Camera, Component);

		#pragma region Static Variables
		Scene* Camera::g_pScene = NULL;
		Camera* Camera::g_pCurrent = NULL;
		#pragma endregion

		#pragma region Properties
		Vector3 Camera::Get_Forward()
		{
			Quaternion curRot, vecRot, inverse, result;
			//curRot = this->Get_GameObject()->Get_Transform()->Get_Rotation();
			//curRot = this->m_kTransform->Get_Rotation();
			curRot = m_kSnapshotRotation;

			vecRot.x = 0.0f;
			vecRot.y = 0.0f;
			vecRot.z = -1.0f;
			vecRot.w = 1.0f;

			inverse = curRot.conjugate();

			result = curRot * vecRot * inverse;
			return Vector3(result.x, result.y, result.z);
		}

		Vector3 Camera::Get_Up()
		{
			Quaternion curRot, vecRot, inverse, result;
			//curRot = this->Get_GameObject()->Get_Transform()->Get_Rotation();
			//curRot = this->m_kTransform->Get_Rotation();
			curRot = m_kSnapshotRotation;

			vecRot.x = 0.0f;
			vecRot.y = 1.0f;
			vecRot.z = 0.0f;
			vecRot.w = 1.0f;

			inverse = curRot.conjugate();

			result = curRot * vecRot * inverse;
			return Vector3(result.x, result.y, result.z);
		}

		Vector3 Camera::Get_Right()
		{
			Quaternion curRot, vecRot, inverse, result;
			//curRot = this->Get_GameObject()->Get_Transform()->Get_Rotation();
			//curRot = this->m_kTransform->Get_Rotation();
			curRot = m_kSnapshotRotation;

			vecRot.x = 1.0f;
			vecRot.y = 0.0f;
			vecRot.z = 0.0f;
			vecRot.w = 1.0f;

			inverse = curRot.conjugate();

			result = curRot * vecRot * inverse;
			return Vector3(result.x, result.y, result.z);
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		Camera::Camera(String name) 
			: Component(name), m_bDirty(true), m_fFieldOfView(D3DX_PIOVER4), m_fAspect(1.3333f),  m_fNearClippingPlane(1.0f), m_fFarClippingPlane(10000.0f), m_bOrthographic(false), m_kBackgroundColor(Color(0xFF6495ED))
		{
			if(Camera::g_pCurrent == NULL)
				Camera::g_pCurrent = this;
		}
		
		Camera::~Camera() { }
		#pragma endregion

		#pragma region Methods
		CAMERA_DESC Camera::Get_Description()
		{
			// Why bother? I'd rather just store it ONCE and use it again and again

			//Transform* transform;
			//Quaternion rotation;
			//CAMERA_DESC desc;
			//unsigned width, height;

			//Screen::GetResolution(width, height);
			//transform = this->Get_GameObject()->Get_Transform();
			////transform = this->m_kTransform;
			////desc.Position = transform->Get_Position();
			//rotation = this->m_kSnapshotRotation;
			//desc.Position = m_kSnapshotPosition;
			//desc.Resolution = Vector2((float)width, (float)height);

			//if(this->m_bOrthographic)
			//	D3DXMatrixOrthoRH((D3DXMATRIX*)&desc.Projection, this->m_fWidth, this->m_fHeight, this->m_fNearClippingPlane, this->m_fFarClippingPlane);
			//else
			//	D3DXMatrixPerspectiveFovRH((D3DXMATRIX*)&desc.Projection, this->m_fFieldOfView, this->m_fAspect, this->m_fNearClippingPlane, this->m_fFarClippingPlane);

			////desc.View = Matrix::CreateTransform(NULL, NULL, &transform->Get_Scale(), &desc.Position, &transform->Get_Rotation(), &(desc.Position * -1.0f));
			//desc.View = Matrix::CreateTransform(NULL, NULL, &transform->Get_Scale(), &desc.Position, &rotation, &(desc.Position * -1.0f));

			//desc.Projection = desc.Projection.transpose(); // fix for MS SetRawValue bug
			//desc.View = desc.View.transpose(); // fix for MS SetRawValue bug

			//return desc;

			return m_kCameraDesc;
		}

		void Camera::UpdateCameraSnapshot()
		{
			//m_kTransform = this->Get_GameObject()->Get_Transform();
			this->m_kSnapshotPosition = this->Get_GameObject()->Get_Transform()->Get_Position();
			this->m_kSnapshotRotation = this->Get_GameObject()->Get_Transform()->Get_Rotation();

			Transform* transform;
			Quaternion rotation;
			CAMERA_DESC desc;
			unsigned width, height;

			Screen::GetResolution(width, height);
			transform = this->Get_GameObject()->Get_Transform();
			//transform = this->m_kTransform;
			//desc.Position = transform->Get_Position();
			rotation = this->m_kSnapshotRotation;
			desc.Position = m_kSnapshotPosition;
			desc.Resolution = Vector2((float)width, (float)height);

			if(this->m_bOrthographic)
				D3DXMatrixOrthoRH((D3DXMATRIX*)&desc.Projection, this->m_fWidth, this->m_fHeight, this->m_fNearClippingPlane, this->m_fFarClippingPlane);
			else
				D3DXMatrixPerspectiveFovRH((D3DXMATRIX*)&desc.Projection, this->m_fFieldOfView, this->m_fAspect, this->m_fNearClippingPlane, this->m_fFarClippingPlane);

			//desc.View = Matrix::CreateTransform(NULL, NULL, &transform->Get_Scale(), &desc.Position, &transform->Get_Rotation(), &(desc.Position * -1.0f));
			desc.View = Matrix::CreateTransform(NULL, NULL, &transform->Get_Scale(), &desc.Position, &rotation, &(desc.Position * -1.0f));

			desc.Projection = desc.Projection.transpose(); // fix for MS SetRawValue bug
			desc.View = desc.View.transpose(); // fix for MS SetRawValue bug

			m_kCameraDesc = desc;
		}
		
		Matrix Camera::Get_View()
		{
			Vector3 pos, invPos;
			Quaternion rotation;
			Transform* transform;

			transform = this->Get_GameObject()->Get_Transform();
			//transform = this->m_kTransform;
			//pos = transform->Get_Position();
			pos = m_kSnapshotPosition;
			invPos = pos;
			invPos.x *= -1; invPos.y *= -1; invPos.z *= -1;

			//rotation = transform->Get_Rotation();
			rotation = m_kSnapshotRotation;

			return Matrix::CreateTransform(NULL, NULL, &transform->Get_Scale(), &pos, &rotation, &invPos);
		}

		Matrix Camera::Get_Projection()
		{
			Matrix projection;
			if(this->m_bOrthographic)
				D3DXMatrixOrthoRH((D3DXMATRIX*)&projection, this->m_fWidth, this->m_fHeight, this->m_fNearClippingPlane, this->m_fFarClippingPlane);
			else
				D3DXMatrixPerspectiveFovRH((D3DXMATRIX*)&projection, this->m_fFieldOfView, this->m_fAspect, this->m_fNearClippingPlane, this->m_fFarClippingPlane);				
			
			return projection;
		}
		#pragma endregion

		#pragma region Event Methods
		void Camera::OnPreCull(DrawingContext* context)
		{
			//this->UpdateCameraSnapshot();
		}

		void Camera::OnPreRender(DrawingContext* context)
		{
			context->Clear(this->m_kBackgroundColor);
			
			((DeferredDrawingContext*)context)->SetGBuffer();
		}

		void Camera::OnRenderImage(DrawingContext* context)
		{

		}

		void Camera::OnPostRender(DrawingContext* context)
		{
			context->Flush();
		}
		#pragma endregion

		#pragma region Overriden Methods
		void Camera::OnComponentAdded(GameObject* gameObject)
		{
			RenderTask::Instantiate()->RegisterComponent(this);
			this->UpdateCameraSnapshot();
		}

		void Camera::OnComponentRemoved(GameObject* gameObject)
		{
			RenderTask::Instantiate()->UnregisterComponent(this);
		}
		#pragma endregion

		#pragma region Static Methods
		void Camera::Activate()
		{
			Camera::g_pCurrent = this;
			this->UpdateCameraSnapshot();
		}
		#pragma endregion

		#pragma region Static Methods
		Camera* Camera::Get_Current()
		{
			return Camera::g_pCurrent;
		}
		#pragma endregion
	}
}