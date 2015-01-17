#include "core\Singularity.Core.h"

namespace Singularity
{
	namespace Components
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Components, Transform, Component);
	
		#pragma region Properties
		Matrix Transform::Get_LocalToWorldMatrix()
		{
			if(this->m_bDirty)
			{
				this->m_kTransform = Matrix::CreateTransform(NULL, NULL, &this->m_kScale, NULL, &this->m_kRotation, &this->m_kPosition);
				this->m_bDirty = false;
			}
			return this->m_kTransform * this->Get_ParentLocalToWorldMatrix();
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		Transform::Transform()
			: m_kPosition(0.0f,0.0f,0.0f), m_kRotation(0.0f,0.0f,0.0f,1.0f), m_kScale(1.0f,1.0f,1.0f)
		{
			this->m_bDirty = true;
			this->m_kTransform = Matrix();
		}

		Transform::~Transform()
		{
		}
		#pragma endregion

		#pragma region Methods
		void Transform::Reset()
		{
			this->m_kPosition = Vector3(0.0f,0.0f,0.0f);
			this->m_kRotation = Quaternion(0.0f,0.0f,0.0f,1.0f);
			this->m_kScale = Vector3(1.0f,1.0f,1.0f);
			this->m_kTransform = Matrix::CreateTransform(NULL, NULL, &this->m_kScale, NULL, &this->m_kRotation, &this->m_kPosition);
			this->Changed.Clear();
		}

		void Transform::Scale(const Vector3& value, Space space)
		{
			this->SetDirty();
			this->m_kScale.x *= value.x;
			this->m_kScale.y *= value.y;
			this->m_kScale.z *= value.z;
		}

		void Transform::Scale(const float x, const float y, const float z, Space space)
		{
			this->SetDirty();
			this->m_kScale.x *= x;
			this->m_kScale.y *= y;
			this->m_kScale.z *= z;
		}

		void Transform::Translate(const Vector3& translate, Space space)
		{
			this->SetDirty();
			this->m_kPosition += translate;
		}

		void Transform::Translate(const float x, const float y, const float z, Space space)
		{
			this->SetDirty();
			this->m_kPosition += Vector3(x,y,z);
		}

		void Transform::Rotate(const Vector3& value, Space space)
		{
			Quaternion rotation = Quaternion::CreateFromYawPitchRoll(value.y, value.x, value.z);
			this->SetDirty();
			this->m_kRotation *= rotation;
		}

		void Transform::Rotate(const float xAngle, const float yAngle, const float zAngle, Space space)
		{
			Quaternion rotation = Quaternion::CreateFromYawPitchRoll(yAngle, xAngle, zAngle);
			this->SetDirty();
			this->m_kRotation *= rotation;
		}

		void Transform::Rotate(const Vector3& axis, const float angle, Space space)
		{
			Quaternion rotation = Quaternion::CreateFromRotationAxis(axis, angle);
			this->SetDirty();
			this->m_kRotation *= rotation;
		}

		void Transform::Rotate(const Quaternion& angle, Space space)
		{
			this->SetDirty();
			this->m_kRotation *= angle;
		}

		void Transform::RotateAround(const Vector3& point, const Vector3& axis, float angle)
		{
			this->Translate(-point);
			this->Rotate(axis, angle);
			this->Translate(point);
			this->SetDirty();
		}

		void Transform::RotateAround(const Vector3& point, const Quaternion& value)
		{
			this->Translate(-point);
			this->Rotate(value.x, value.y, value.z);
			this->Translate(point);
			this->SetDirty();
		}

		void Transform::LookAt(const Vector3& target, Vector3 worldUp)
		{
			Vector3 direction, right;
			direction = (this->m_kPosition - target).normalize();
			right = worldUp.cross(direction);
			worldUp = direction.cross(right);
           
			this->m_kRotation.w = sqrt(1.0f + right.x + worldUp.y + direction.z) / 2.0f;
			this->m_kRotation.x = (direction.y - worldUp.z) / (this->m_kRotation.w * 4.0f);
            this->m_kRotation.y = (right.z - direction.x) / (this->m_kRotation.w * 4.0f);
            this->m_kRotation.z = (worldUp.x - right.y) / (this->m_kRotation.w * 4.0f);
			this->m_kRotation = this->m_kRotation.normalize();

			this->SetDirty();
		}

		void Transform::LookAt(Transform* target, Vector3 worldUp)
		{
			this->LookAt(target->Get_Position(), worldUp);
		}

		//returns Euler angles that point from one point to another
		Vector3 Transform::AngleTo(Vector3 from, Vector3 location)
		{
			Vector3 angle, v3;

			v3 = (location - from).normalize();

			angle.x = asinf(v3.y);
			angle.y = atan2f(-v3.z, -v3.x);

			return angle;
		}
		
		Quaternion Transform::EulerToRotation(Vector3 euler)
		{
			return Quaternion::CreateFromYawPitchRoll(euler.y, euler.x, euler.z);
		}

		//converts a Quaternion to Euler angles (X = pitch, Y = yaw, Z = roll)
		Vector3 Transform::RotationToEuler(Quaternion rotation)
		{
			if(rotation.w > 1)
				rotation = rotation.normalize();

			float x, y, z, w, yaw, pitch, roll;
			x = rotation.x;
			y = rotation.y;
			z = rotation.z;
			w = rotation.w;

			yaw, pitch, roll = 0.0f;

			float test = x * y + z * w;
			if(test > 0.499f)
			{
				yaw = 2.0f * atan2f(x, w);
				roll = D3DX_PIOVER2;
				pitch = 0.0f;
			}
			else if(test < -0.499f)
			{
				yaw = 2.0f * atan2f(x, w);
				roll = -D3DX_PIOVER2;
				pitch = 0.0f;
			}
			else
			{
				float sqx = x * x;
				float sqy = y * y;
				float sqz = z * z;

				yaw = atan2f(2.0f * y * w - 2.0f * x * z, 1.0f - 2.0f * sqy - 2.0f * sqz);
				roll = asinf(2.0f * test);
				pitch = atan2f(2.0f * x * w - 2.0f * y * z, 1.0f - 2.0f * sqx - 2.0f * sqz);
			}

			/*yaw = yaw * (180 / D3DX_PI);
			pitch = pitch * (180 / D3DX_PI);
			roll = roll * (180 / D3DX_PI);*/

			return Vector3(pitch, yaw, roll);
		}
		#pragma endregion
	}
}