struct Vector2
{
	public:
		float x, y;

		Vector2();
		Vector2( float x, float y);

		// assignment operators
		Vector2& operator += ( const Vector2& );
		Vector2& operator -= ( const Vector2& );
		Vector2& operator *= ( float );
		Vector2& operator /= ( float );
};

struct Vector3
{
	public:
		float x, y, z;

		Vector3();
		Vector3( float x, float y, float z);

		// assignment operators
		Vector3& operator += ( const Vector3& );
		Vector3& operator -= ( const Vector3& );
		Vector3& operator *= ( float );
		Vector3& operator /= ( float );
		
		Vector3 Project(Camera* camera);
};

struct Vector4
{
	public:
		float x, y, z;

		Vector4();
		Vector4( float x, float y, float z, float w);

		// assignment operators
		Vector4& operator += ( const Vector4& );
		Vector4& operator -= ( const Vector4& );
		Vector4& operator *= ( float );
		Vector4& operator /= ( float );
};

struct Color
{
	public:
		float r, g, b, a;

		Color() {};
		Color( unsigned  argb );
		Color( float r, float g, float b, float a );

		// assignment operators
		Color& operator += ( const Color& );
		Color& operator -= ( const Color& );
		Color& operator *= ( float );
		Color& operator /= ( float );

		
}

struct Quaternion
{
	public:
		float x, y, z, w;

		Quaternion() {};
		Quaternion( float x, float y, float z, float w );

		// assignment operators
		Quaternion& operator += ( const Quaternion& );
		Quaternion& operator -= ( const Quaternion& );
		Quaternion& operator *= ( const Quaternion& );
		Quaternion& operator *= ( float );
		Quaternion& operator /= ( float );
}

struct Matrix
{
    Matrix() {};
    Matrix( FLOAT _11, FLOAT _12, FLOAT _13, FLOAT _14,
                FLOAT _21, FLOAT _22, FLOAT _23, FLOAT _24,
                FLOAT _31, FLOAT _32, FLOAT _33, FLOAT _34,
                FLOAT _41, FLOAT _42, FLOAT _43, FLOAT _44 );


    // assignment operators
    Matrix& operator *= ( CONST Matrix& );
    Matrix& operator += ( CONST Matrix& );
    Matrix& operator -= ( CONST Matrix& );
    Matrix& operator *= ( FLOAT );
    Matrix& operator /= ( FLOAT );

    // binary operators
    Matrix operator * ( CONST Matrix& ) const;
    Matrix operator + ( CONST Matrix& ) const;
    Matrix operator - ( CONST Matrix& ) const;
    Matrix operator * ( FLOAT ) const;
    Matrix operator / ( FLOAT ) const;
} 