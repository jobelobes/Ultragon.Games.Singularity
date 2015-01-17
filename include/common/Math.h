struct Vector2
{
	public:
		float x, y;

	public:
		Vector2() {};
		Vector2( const float * );
		Vector2( float x, float y );

		// casting
		operator float* ();
		operator const float* () const;

		// assignment operators
		Vector2& operator += ( const Vector2& );
		Vector2& operator -= ( const Vector2& );
		Vector2& operator *= ( const Vector2& );
		Vector2& operator /= ( const Vector2& );
		Vector2& operator *= ( float );
		Vector2& operator /= ( float );

		// unary operators
		Vector2 operator + () const;
		Vector2 operator - () const;

		// binary operators
		Vector2 operator + ( const Vector2& ) const;
		Vector2 operator - ( const Vector2& ) const;
		Vector2 operator * ( const Vector2& ) const;
		Vector2 operator / ( const Vector2& ) const;
		Vector2 operator * ( float ) const;
		Vector2 operator / ( float ) const;

		bool operator == ( const Vector2& ) const;
		bool operator != ( const Vector2& ) const;

		float length() const;
		float squaredlength() const;
		float dot(const Vector2& value) const;
		Vector2 minimize(const Vector2& value) const;
		Vector2 maximize(const Vector2& value) const;
};

struct Vector3
{
	public:
		float x, y, z;

	public:
		Vector3() {};
		Vector3( const float * );
		Vector3( const Vector3& );
		Vector3( float fx, float fy, float fz);

		// casting
		operator float* ();
		operator const float* () const;

		// assignment operators
		Vector3& operator += ( const Vector3& );
		Vector3& operator -= ( const Vector3& );
		Vector3& operator *= ( const Vector3& );
		Vector3& operator /= ( const Vector3& );
		Vector3& operator *= ( float );
		Vector3& operator /= ( float );

		// unary operators
		Vector3 operator + () const;
		Vector3 operator - () const;

		// binary operators
		Vector3 operator + ( const Vector3& ) const;
		Vector3 operator - ( const Vector3& ) const;
		Vector3 operator * ( const Vector3& ) const;
		Vector3 operator / ( const Vector3& ) const;
		Vector3 operator * ( float ) const;
		Vector3 operator / ( float ) const;

		bool operator == ( const Vector3& ) const;
		bool operator != ( const Vector3& ) const;

		float length() const;
		float squaredlength() const;
		float dot( const Vector3& value) const;
		Vector3 cross( const Vector3& value) const;
		Vector3 normalize() const;
		Vector3 project() const;
		Vector3 minimize(const Vector3& value) const;
		Vector3 maximize(const Vector3& value) const;
};

struct Vector4
{
	public:
		float x, y, z, w;

	public:
		Vector4() {};
		Vector4( const float* );
		Vector4( const Vector3& xyz, float w );
		Vector4( float x, float y, float z, float w );

		// casting
		operator float* ();
		operator const float* () const;

		// assignment operators
		Vector4& operator += ( const Vector4& );
		Vector4& operator -= ( const Vector4& );
		Vector4& operator *= ( const Vector4& );
		Vector4& operator /= ( const Vector4& );
		Vector4& operator *= ( float );
		Vector4& operator /= ( float );

		// unary operators
		Vector4 operator + () const;
		Vector4 operator - () const;

		// binary operators
		Vector4 operator + ( const Vector4& ) const;
		Vector4 operator - ( const Vector4& ) const;
		Vector4 operator * ( const Vector4& ) const;
		Vector4 operator / ( const Vector4& ) const;
		Vector4 operator * ( float ) const;
		Vector4 operator / ( float ) const;

		bool operator == ( const Vector4& ) const;
		bool operator != ( const Vector4& ) const;

		float length() const;
		float squaredlength() const;
		float dot( const Vector4& value) const;
		Vector4 minimize(const Vector4& value) const;
		Vector4 maximize(const Vector4& value) const;
};

struct Quaternion;

struct Matrix : public D3DMATRIX
{
	public:
		Matrix();
		Matrix( const float * );
		Matrix( const Matrix& );
		Matrix( const Quaternion& );
		Matrix( float _11, float _12, float _13, float _14,
					float _21, float _22, float _23, float _24,
					float _31, float _32, float _33, float _34,
					float _41, float _42, float _43, float _44 );


		// access grants
		float& operator () ( unsigned Row, unsigned Col );
		float  operator () ( unsigned Row, unsigned Col ) const;

		// casting operators
		operator float* ();
		operator const float* () const;

		// assignment operators
		Matrix& operator *= ( const Matrix& );
		Matrix& operator += ( const Matrix& );
		Matrix& operator -= ( const Matrix& );
		Matrix& operator *= ( float );
		Matrix& operator /= ( float );

		// unary operators
		Matrix operator + () const;
		Matrix operator - () const;

		// binary operators
		Matrix operator * ( const Matrix& ) const;
		Matrix operator + ( const Matrix& ) const;
		Matrix operator - ( const Matrix& ) const;
		Matrix operator * ( float ) const;
		Matrix operator / ( float ) const;

		friend Matrix operator * ( float, const Matrix& );

		bool operator == ( const Matrix& ) const;
		bool operator != ( const Matrix& ) const;

		Matrix transpose() const;
		Matrix inverse() const;

		static Matrix CreateTranslation(const Vector3& translation);
		static Matrix CreateTransform(const Vector3* scalingCenter, const Quaternion* scalingRotation, const Vector3* scaling, const Vector3* rotationCenter, const Quaternion* rotation, const Vector3* translation);
		static Matrix CreateIdentity();
};

struct Quaternion
{
	public:
		float x, y, z, w;

	public:
		Quaternion() {};
		Quaternion( const float * );
		Quaternion( const Matrix& m );
		Quaternion( float x, float y, float z, float w );

		// casting
		operator float* ();
		operator const float* () const;

		// assignment operators
		Quaternion& operator += ( const Quaternion& );
		Quaternion& operator -= ( const Quaternion& );
		Quaternion& operator *= ( const Quaternion& );
		Quaternion& operator *= ( float );
		Quaternion& operator /= ( float );

		// unary operators
		Quaternion  operator + () const;
		Quaternion  operator - () const;

		// binary operators
		Quaternion operator + ( const Quaternion& ) const;
		Quaternion operator - ( const Quaternion& ) const;
		Quaternion operator * ( const Quaternion& ) const;
		Quaternion operator * ( float ) const;
		Quaternion operator / ( float ) const;

		friend Quaternion operator * (float, const Quaternion& );

		bool operator == ( const Quaternion& ) const;
		bool operator != ( const Quaternion& ) const;

		Quaternion inverse() const;
		Quaternion normalize() const;
		Quaternion conjugate() const;

		static Quaternion CreateFromYawPitchRoll(const float yaw, const float pitch, const float roll);
		static Quaternion CreateFromRotationAxis(const Vector3& axis, const float angle);
};

struct Color
{
	public:
		float r, g, b, a;
	public:
		Color() {};
		Color( unsigned  argb );
		Color( const float * );
		Color( float r, float g, float b, float a );

		// casting
		operator unsigned () const;

		operator float* ();
		operator const float* () const;

		// assignment operators
		Color& operator += ( const Color& );
		Color& operator -= ( const Color& );
		Color& operator *= ( float );
		Color& operator /= ( float );

		// unary operators
		Color operator + () const;
		Color operator - () const;

		// binary operators
		Color operator + ( const Color& ) const;
		Color operator - ( const Color& ) const;
		Color operator * ( float ) const;
		Color operator / ( float ) const;

		friend Color operator * ( float, const Color& );

		bool operator == ( const Color& ) const;
		bool operator != ( const Color& ) const;
};

#include "common\Math.inc"