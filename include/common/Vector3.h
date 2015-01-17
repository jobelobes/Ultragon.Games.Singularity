#include "common\Singularity.Common.h"

class Vector3
{
	private:
		#pragma region Variables
		float x, y, z;
		#pragma endregion
	
	public:
		#pragma region Properties
		const float Get_ElapsedTime() const;
		const float Get_TotalTime() const;
		#pragma endregion

		#pragma region Constructors and Finalizers
		Vector3() {};
		Vector3(const float* values);
		Vector3(float x, float y);
		#pragma endregion

		#pragma region Methods
		operator float* ();
		operator const float* () const;

		Vector3 Normalize() const;
		float Dot() const;
		#pragma endregion

		#pragma region Operator Overloaded Methods
		Vector3& operator += (const Vector3&);
		Vector3& operator -= (const Vector3&);
		Vector3& operator *= (float);
		Vector3& operator /= (float);

		// unary operators
		Vector3 operator + () const;
		Vector3 operator - () const;

		// binary operators
		Vector3 operator + (const Vector3&) const;
		Vector3 operator - (const Vector3&) const;
		Vector3 operator * (float) const;
		Vector3 operator / (float) const;

		friend Vector3 operator * (float, const Vector3&);

		bool operator == (const Vector3&) const;
		bool operator != (const Vector3&) const;
		#pragma endregion
};