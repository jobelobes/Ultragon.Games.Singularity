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
		Vector2& operator *= ( float );
		Vector2& operator /= ( float );

		// unary operators
		Vector2 operator + () const;
		Vector2 operator - () const;

		// binary operators
		Vector2 operator + ( const Vector2& ) const;
		Vector2 operator - ( const Vector2& ) const;
		Vector2 operator * ( float ) const;
		Vector2 operator / ( float ) const;

		friend Vector2 operator * ( float, const Vector2& );

		BOOL operator == ( const Vector2& ) const;
		BOOL operator != ( const Vector2& ) const;
};


struct Vector3
{
	public:
		float x, y, z;

	public:
		Vector3() {};
		Vector3( const float * );
		Vector3( const Vector3& );
		Vector3( float x, float y, float z );

		// casting
		operator float* ();
		operator const float* () const;

		// assignment operators
		Vector3& operator += ( const Vector3& );
		Vector3& operator -= ( const Vector3& );
		Vector3& operator *= ( float );
		Vector3& operator /= ( float );

		// unary operators
		Vector3 operator + () const;
		Vector3 operator - () const;

		// binary operators
		Vector3 operator + ( const Vector3& ) const;
		Vector3 operator - ( const Vector3& ) const;
		Vector3 operator * ( float ) const;
		Vector3 operator / ( float ) const;

		friend Vector3 operator * ( float, const struct Vector3& );

		BOOL operator == ( const Vector3& ) const;
		BOOL operator != ( const Vector3& ) const;

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
		Vector4& operator *= ( float );
		Vector4& operator /= ( float );

		// unary operators
		Vector4 operator + () const;
		Vector4 operator - () const;

		// binary operators
		Vector4 operator + ( const Vector4& ) const;
		Vector4 operator - ( const Vector4& ) const;
		Vector4 operator * ( float ) const;
		Vector4 operator / ( float ) const;

		friend Vector4 operator * ( float, const Vector4& );

		BOOL operator == ( const Vector4& ) const;
		BOOL operator != ( const Vector4& ) const;
}

struct Matrix : public D3DMATRIX
{
	public:
		Matrix() {};
		Matrix( const float * );
		Matrix( const D3DMATRIX& );
		Matrix( const D3DXfloat16 * );
		Matrix( float _11, float _12, float _13, float _14,
					float _21, float _22, float _23, float _24,
					float _31, float _32, float _33, float _34,
					float _41, float _42, float _43, float _44 );


		// access grants
		float& operator () ( UINT Row, UINT Col );
		float  operator () ( UINT Row, UINT Col ) const;

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

		BOOL operator == ( const Matrix& ) const;
		BOOL operator != ( const Matrix& ) const;
};

struct Quaternion
{
	public:
		float x, y, z, w;

	public:
		Quaternion() {};
		Quaternion( const float * );
		Quaternion( const D3DXfloat16 * );
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

		BOOL operator == ( const Quaternion& ) const;
		BOOL operator != ( const Quaternion& ) const;
};

typedef struct Color
{
	public:
		float r, g, b, a;
	public:
		Color() {};
		Color( UINT  argb );
		Color( const float * );
		Color( const D3DXfloat16 * );
		Color( float r, float g, float b, float a );

		// casting
		operator UINT  () const;

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

		BOOL operator == ( const Color& ) const;
		BOOL operator != ( const Color& ) const;
};