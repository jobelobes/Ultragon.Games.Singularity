#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Static Variables
	const Transformation Transformation::Identity = Transformation();
	#pragma endregion

	#pragma region Static Methods
	Transformation Transformation::FromTranslation(const Vector3 translation)
	{	
		Transformation transform;
		transform.m_kTranslate = Vector3(translation);
		return transform;
	}

	Transformation Transformation::FromScale(const Vector3 scale)
	{	
		Transformation transform;
		transform.m_kScale = Vector3(scale);
		return transform;
	}

	Transformation Transformation::FromRotation(const Quaternion rotation)
	{	
		Transformation transform;
		transform.m_kRotation = Quaternion(rotation);
		return transform;
	}

	//returns Euler angles that point from one point to another
	Vector3 Transformation::AngleTo(Vector3 from, Vector3 location)
	{
		Vector3 angle, v3;

		D3DXVec3Normalize(&v3, &(location - from));

		angle.x = asinf(v3.y);
		angle.y = atan2f(-v3.z, -v3.x);

		return angle;
	}

	//converts a Quaternion to Euler angles (X = pitch, Y = yaw, Z = roll)
	Vector3 Transformation::RotationToEuler(Quaternion rotation)
	{
		if(rotation.w > 1)
			D3DXQuaternionNormalize(&rotation, &rotation);

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

			yaw = atan2f(2.0f * y * w * x * z, 1 - 2 * sqy - 2 * sqz);
			roll = asin(2 * test);
			pitch = atan2f(2 * x * w - 2 * y * z, 1 - 2 * sqx - 2 * sqz);
		}

		yaw = yaw * (180 / D3DX_PI);
		pitch = pitch * (180 / D3DX_PI);
		roll = roll * (180 / D3DX_PI);

		return Vector3(pitch, yaw, roll);
	}
	#pragma endregion

	#pragma region Constructors and Deconstructors
	Transformation::Transformation()
		: m_bDirty(true), m_kTranslate(0.0f,0.0f,0.0f), m_kRotation(0.0f,0.0f,0.0f,1.0f), m_kScale(1.0f,1.0f,1.0f) { }

	Transformation::Transformation(Vector3 position)
		: m_bDirty(true), m_kTranslate(position), m_kRotation(0.0f,0.0f,0.0f,1.0f), m_kScale(1.0f,1.0f,1.0f) { }

	Transformation::Transformation(Vector3 position, Quaternion rotation)
		: m_bDirty(true), m_kTranslate(position), m_kRotation(rotation), m_kScale(1.0f,1.0f,1.0f) { }

	Transformation::Transformation(Vector3 position, Quaternion rotation, Vector3 scale)
		: m_bDirty(true), m_kTranslate(position), m_kRotation(rotation), m_kScale(scale) { }

	Transformation::~Transformation() { }
	#pragma endregion

	#pragma region Methods
	void Transformation::_CalculateTransform()
	{
		D3DXMatrixTransformation(&this->m_kTransformMatrix,
			NULL, NULL,
			&this->m_kScale,
			NULL, &this->m_kRotation,
			&this->m_kTranslate);
	}

	bool Transformation::IsIdentity () const
	{
		return false;
	}

	bool Transformation::IsUniformScale () const
	{
		return false;
	}

	void Transformation::Translate(Vector3 value)
	{
		this->m_kTranslate += value;
	}

	void Transformation::Rotate(Vector3 angles)
	{
		Quaternion rotation;
		D3DXQuaternionRotationYawPitchRoll(&rotation, angles.y, angles.x, angles.z);
		this->m_kRotation *= rotation;
	}

	void Transformation::RotateAround(Vector3 point, Vector3 degrees)
	{

	}

	void Transformation::LookAt(Vector3 at, Vector3 up)
	{
		Matrix lookat;
		Vector3 Scale;

		D3DXMatrixLookAtLH(&lookat, &this->m_kTranslate, &at, &up);
		D3DXMatrixDecompose(&Scale, &this->m_kRotation, &this->m_kTranslate, &lookat);
	}
	#pragma endregion

	#pragma region Operator Overloaded Methods
	Transformation Transformation::operator* (const Transformation& c) const
	{
		Transformation transform;
		transform.m_kTranslate = this->m_kTranslate + c.m_kTranslate;
		transform.m_kRotation = this->m_kRotation * c.m_kRotation;
		transform.m_kScale.x = this->m_kScale.x * c.m_kScale.x;
		transform.m_kScale.y = this->m_kScale.y * c.m_kScale.y;
		transform.m_kScale.z = this->m_kScale.z * c.m_kScale.z;
		return transform;
	}
	#pragma endregion
}