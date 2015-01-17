
inline Vector2::Vector2( const float *pf )
{
    x = pf[0];
    y = pf[1];
}

inline Vector2::Vector2( float fx, float fy )
{
    x = fx;
    y = fy;
}


// casting
inline Vector2::operator float* ()
{
    return (float *) &x;
}

inline Vector2::operator const float* () const
{
    return (const float *) &x;
}


// assignment operators
inline Vector2& Vector2::operator += ( const Vector2& v )
{
    x += v.x;
    y += v.y;
    return *this;
}

inline Vector2& Vector2::operator -= ( const Vector2& v )
{
    x -= v.x;
    y -= v.y;
    return *this;
}

inline Vector2& Vector2::operator *= ( float f )
{
    x *= f;
    y *= f;
    return *this;
}

inline Vector2& Vector2::operator *= ( const Vector2& value )
{
    x *= value.x;
    y *= value.y;
    return *this;
}

inline Vector2& Vector2::operator /= ( float f )
{
    float fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    return *this;
}

inline Vector2& Vector2::operator /= ( const Vector2& value )
{
    x /= value.x;
    y /= value.y;
    return *this;
}

inline Vector2 Vector2::operator + () const
{
    return *this;
}

inline Vector2 Vector2::operator - () const
{
    return Vector2(-x, -y);
}

inline Vector2 Vector2::operator + ( const Vector2& v ) const
{
    return Vector2(x + v.x, y + v.y);
}

inline Vector2 Vector2::operator - ( const Vector2& v ) const
{
    return Vector2(x - v.x, y - v.y);
}

inline Vector2 Vector2::operator * ( float f ) const
{
    return Vector2(x * f, y * f);
}

inline Vector2 Vector2::operator * (const Vector2& value ) const
{
    return Vector2(x * value.x, y * value.y);
}

inline Vector2 Vector2::operator / ( float f ) const
{
    float fInv = 1.0f / f;
    return Vector2(x * fInv, y * fInv);
}

inline Vector2 Vector2::operator / ( const Vector2& value) const
{
	return Vector2(x / value.x, y / value.y);
}

inline bool Vector2::operator == ( const Vector2& v ) const
{
    return x == v.x && y == v.y;
}

inline bool Vector2::operator != ( const Vector2& v ) const
{
    return x != v.x || y != v.y;
}

inline float Vector2::length() const
{
	return sqrtf(x * x + y * y);
}

inline float Vector2::squaredlength() const
{
	return x * x + y * y;
}

inline Vector2 Vector2::minimize(const Vector2& value) const
{
	return Vector2(x < value.x ? x : value.x, y < value.y ? y : value.y);
}

inline Vector2 Vector2::maximize(const Vector2& value) const
{
	return Vector2(x > value.x ? x : value.x, y > value.y ? y : value.y);
}

inline float Vector2::dot(const Vector2& value) const
{
	return x * value.x + y * value.x;
}

// Vector3 definition
inline Vector3::Vector3( const float *pf )
{
    x = pf[0];
    y = pf[1];
    z = pf[2];
}

inline Vector3::Vector3( const Vector3& v )
{
    x = v.x;
    y = v.y;
    z = v.z;
}

inline Vector3::Vector3( float fx, float fy, float fz )
{
    x = fx;
    y = fy;
    z = fz;
}


// casting
inline Vector3::operator float* ()
{
    return (float *) &x;
}

inline Vector3::operator const float* () const
{
    return (const float *) &x;
}


// assignment operators
inline Vector3& Vector3::operator += ( const Vector3& v )
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline Vector3& Vector3::operator -= ( const Vector3& v )
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline Vector3& Vector3::operator *= ( float f )
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

inline Vector3& Vector3::operator *= ( const Vector3& value )
{
    x *= value.x;
    y *= value.y;
    z *= value.z;
    return *this;
}

inline Vector3& Vector3::operator /= ( float f )
{
    float fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    z *= fInv;
    return *this;
}

inline Vector3& Vector3::operator /= ( const Vector3& value )
{
    x /= value.x;
    y /= value.y;
    z /= value.z;
    return *this;
}

inline Vector3 Vector3::operator + () const
{
    return *this;
}

inline Vector3 Vector3::operator - () const
{
    return Vector3(-x, -y, -z);
}


// binary operators
inline Vector3 Vector3::operator + ( const Vector3& v ) const
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}

inline Vector3 Vector3::operator - ( const Vector3& v ) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);
}

inline Vector3 Vector3::operator * ( float f ) const
{
    return Vector3(x * f, y * f, z * f);
}

inline Vector3 Vector3::operator * ( const Vector3& value ) const
{
    return Vector3(x * value.x, y * value.y, z * value.z);
}

inline Vector3 Vector3::operator / ( float f ) const
{
    float fInv = 1.0f / f;
    return Vector3(x * fInv, y * fInv, z * fInv);
}

inline Vector3 Vector3::operator / ( const Vector3& value ) const
{
    return Vector3(x * value.x, y * value.y, z * value.z);
}

inline bool Vector3::operator == ( const Vector3& v ) const
{
    return x == v.x && y == v.y && z == v.z;
}

inline bool Vector3::operator != ( const Vector3& v ) const
{
    return x != v.x || y != v.y || z != v.z;
}

inline float Vector3::length() const
{
    return sqrtf(x * x + y * y + z * z);
}

inline float Vector3::squaredlength() const
{
	return x * x + y * y + z * z;
}

inline float Vector3::dot( const Vector3& value) const
{
	return x * value.x + y * value.y + z * value.z;
}

inline Vector3 Vector3::cross( const Vector3& value) const
{
	return Vector3(y * value.z - z * value.y, z * value.x - x * value.z, x * value.y - y * value.x);
}

inline Vector3 Vector3::normalize() const
{
	float magnitude = 1.0f / sqrtf(x * x + y * y + z * z);
	return Vector3(x * magnitude, y * magnitude, z * magnitude); 
}

inline Vector3 Vector3::minimize(const Vector3& value) const
{
	return Vector3(x < value.x ? x : value.x, y < value.y ? y : value.y, z < value.z ? z : value.z);
}

inline Vector3 Vector3::maximize(const Vector3& value) const
{
	return Vector3(x > value.x ? x : value.x, y > value.y ? y : value.y, z > value.z ? z : value.z);
}

inline Vector4::Vector4( const float *pf )
{
    x = pf[0];
    y = pf[1];
    z = pf[2];
    w = pf[3];
}

inline Vector4::Vector4( const Vector3& v, float f )
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = f;
}

inline Vector4::Vector4( float fx, float fy, float fz, float fw )
{
    x = fx;
    y = fy;
    z = fz;
    w = fw;
}

inline Vector4::operator float* ()
{
    return (float *) &x;
}

inline Vector4::operator const float* () const
{
    return (const float *) &x;
}

inline Vector4& Vector4::operator += ( const Vector4& v )
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

inline Vector4& Vector4::operator -= ( const Vector4& v )
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

inline Vector4& Vector4::operator *= ( float f )
{
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
}

inline Vector4& Vector4::operator *= ( const Vector4& value)
{
    x *= value.x;
    y *= value.y;
    z *= value.z;
    w *= value.w;
    return *this;
}

inline Vector4& Vector4::operator /= ( float f )
{
    float fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    z *= fInv;
    w *= fInv;
    return *this;
}

inline Vector4& Vector4::operator /= ( const Vector4& value)
{
    x /= value.x;
    y /= value.y;
    z /= value.z;
    w /= value.w;
    return *this;
}

inline Vector4 Vector4::operator + () const
{
    return *this;
}

inline Vector4 Vector4::operator - () const
{
    return Vector4(-x, -y, -z, -w);
}

inline Vector4 Vector4::operator + ( const Vector4& v ) const
{
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

inline Vector4 Vector4::operator - ( const Vector4& v ) const
{
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

inline Vector4 Vector4::operator * ( float f ) const
{
    return Vector4(x * f, y * f, z * f, w * f);
}

inline Vector4 Vector4::operator * ( const Vector4& value) const
{
    return Vector4(x * value.x, y * value.y, z * value.z, w * value.w);
}

inline Vector4 Vector4::operator / ( float f ) const
{
    float fInv = 1.0f / f;
    return Vector4(x * fInv, y * fInv, z * fInv, w * fInv);
}

inline Vector4 Vector4::operator / ( const Vector4& value ) const
{
    return Vector4(x / value.x, y / value.y, z / value.z, w / value.w);
}

inline bool Vector4::operator == ( const Vector4& v ) const
{
    return x == v.x && y == v.y && z == v.z && w == v.w;
}

inline bool Vector4::operator != ( const Vector4& v ) const
{
    return x != v.x || y != v.y || z != v.z || w != v.w;
}

inline float Vector4::length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

inline float Vector4::squaredlength() const
{
	return x * x + y * y + z * z + w * w;
}

inline float Vector4::dot( const Vector4& value) const
{
	return x * value.x + y * value.y + z * value.z + w * value.w;
}

inline Vector4 Vector4::minimize(const Vector4& value) const
{
	return Vector4(x < value.x ? x : value.x, y < value.y ? y : value.y, z < value.z ? z : value.z, w < value.w ? w : value.w);
}

inline Vector4 Vector4::maximize(const Vector4& value) const
{
	return Vector4(x > value.x ? x : value.x, y > value.y ? y : value.y, z > value.z ? z : value.z, w > value.w ? w : value.w);
}

inline Matrix::Matrix()
{
	_11 = 1.0f; _12 = 0.0f; _13 = 0.0f; _14 = 0.0f;
    _21 = 0.0f; _22 = 1.0f; _23 = 0.0f; _24 = 0.0f;
    _31 = 0.0f; _32 = 0.0f; _33 = 1.0f; _34 = 0.0f;
    _41 = 0.0f; _42 = 0.0f; _43 = 0.0f; _44 = 1.0f;
}

inline Matrix::Matrix( const float* pf )
{
    memcpy(&_11, pf, sizeof(Matrix));
}

inline Matrix::Matrix( const Quaternion& rotation )
{
    D3DXMatrixRotationQuaternion((D3DXMATRIX*)this, (D3DXQUATERNION*)&rotation);
}

inline Matrix::Matrix( const Matrix& mat )
{
    memcpy(&_11, &mat, sizeof(Matrix));
}

inline Matrix::Matrix( float f11, float f12, float f13, float f14,
                        float f21, float f22, float f23, float f24,
                        float f31, float f32, float f33, float f34,
                        float f41, float f42, float f43, float f44 )
{
    _11 = f11; _12 = f12; _13 = f13; _14 = f14;
    _21 = f21; _22 = f22; _23 = f23; _24 = f24;
    _31 = f31; _32 = f32; _33 = f33; _34 = f34;
    _41 = f41; _42 = f42; _43 = f43; _44 = f44;
}

inline float& Matrix::operator () ( unsigned iRow, unsigned iCol )
{
    return m[iRow][iCol];
}

inline float Matrix::operator () ( unsigned iRow, unsigned iCol ) const
{
    return m[iRow][iCol];
}

inline Matrix::operator float* ()
{
    return (float *) &_11;
}

inline Matrix::operator const float* () const
{
    return (const float *) &_11;
}

inline Matrix& Matrix::operator *= ( const Matrix& mat )
{
    D3DXMatrixMultiply((D3DXMATRIX*)this, (D3DXMATRIX*)this, (D3DXMATRIX*)&mat);
    return *this;
}

inline Matrix& Matrix::operator += ( const Matrix& mat )
{
    _11 += mat._11; _12 += mat._12; _13 += mat._13; _14 += mat._14;
    _21 += mat._21; _22 += mat._22; _23 += mat._23; _24 += mat._24;
    _31 += mat._31; _32 += mat._32; _33 += mat._33; _34 += mat._34;
    _41 += mat._41; _42 += mat._42; _43 += mat._43; _44 += mat._44;
    return *this;
}

inline Matrix& Matrix::operator -= ( const Matrix& mat )
{
    _11 -= mat._11; _12 -= mat._12; _13 -= mat._13; _14 -= mat._14;
    _21 -= mat._21; _22 -= mat._22; _23 -= mat._23; _24 -= mat._24;
    _31 -= mat._31; _32 -= mat._32; _33 -= mat._33; _34 -= mat._34;
    _41 -= mat._41; _42 -= mat._42; _43 -= mat._43; _44 -= mat._44;
    return *this;
}

inline Matrix& Matrix::operator *= ( float f )
{
    _11 *= f; _12 *= f; _13 *= f; _14 *= f;
    _21 *= f; _22 *= f; _23 *= f; _24 *= f;
    _31 *= f; _32 *= f; _33 *= f; _34 *= f;
    _41 *= f; _42 *= f; _43 *= f; _44 *= f;
    return *this;
}

inline Matrix& Matrix::operator /= ( float f )
{
    float fInv = 1.0f / f;
    _11 *= fInv; _12 *= fInv; _13 *= fInv; _14 *= fInv;
    _21 *= fInv; _22 *= fInv; _23 *= fInv; _24 *= fInv;
    _31 *= fInv; _32 *= fInv; _33 *= fInv; _34 *= fInv;
    _41 *= fInv; _42 *= fInv; _43 *= fInv; _44 *= fInv;
    return *this;
}

inline Matrix Matrix::operator + () const
{
    return *this;
}

inline Matrix Matrix::operator - () const
{
    return Matrix(-_11, -_12, -_13, -_14,
                      -_21, -_22, -_23, -_24,
                      -_31, -_32, -_33, -_34,
                      -_41, -_42, -_43, -_44);
}

inline Matrix Matrix::operator * ( const Matrix& mat ) const
{
    Matrix matT;
    D3DXMatrixMultiply((D3DXMATRIX*)&matT, (D3DXMATRIX*)this, (D3DXMATRIX*)&mat);
    return matT;
}

inline Matrix Matrix::operator + ( const Matrix& mat ) const
{
    return Matrix(_11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
                      _21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
                      _31 + mat._31, _32 + mat._32, _33 + mat._33, _34 + mat._34,
                      _41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44);
}

inline Matrix Matrix::operator - ( const Matrix& mat ) const
{
    return Matrix(_11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
                      _21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
                      _31 - mat._31, _32 - mat._32, _33 - mat._33, _34 - mat._34,
                      _41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44);
}

inline Matrix Matrix::operator * ( float f ) const
{
    return Matrix(_11 * f, _12 * f, _13 * f, _14 * f,
                      _21 * f, _22 * f, _23 * f, _24 * f,
                      _31 * f, _32 * f, _33 * f, _34 * f,
                      _41 * f, _42 * f, _43 * f, _44 * f);
}

inline Matrix Matrix::operator / ( float f ) const
{
    float fInv = 1.0f / f;
    return Matrix(_11 * fInv, _12 * fInv, _13 * fInv, _14 * fInv,
                      _21 * fInv, _22 * fInv, _23 * fInv, _24 * fInv,
                      _31 * fInv, _32 * fInv, _33 * fInv, _34 * fInv,
                      _41 * fInv, _42 * fInv, _43 * fInv, _44 * fInv);
}

inline Matrix operator * ( float f, const Matrix& mat )
{
    return Matrix(f * mat._11, f * mat._12, f * mat._13, f * mat._14,
                      f * mat._21, f * mat._22, f * mat._23, f * mat._24,
                      f * mat._31, f * mat._32, f * mat._33, f * mat._34,
                      f * mat._41, f * mat._42, f * mat._43, f * mat._44);
}

inline bool Matrix::operator == ( const Matrix& mat ) const
{
    return 0 == memcmp(this, &mat, sizeof(Matrix));
}

inline bool Matrix::operator != ( const Matrix& mat ) const
{
    return 0 != memcmp(this, &mat, sizeof(Matrix));
}

inline Matrix Matrix::transpose() const
{
	Matrix transpose(*this);
	D3DXMatrixTranspose((D3DXMATRIX*)&transpose, (D3DXMATRIX*)&transpose);
	return transpose;
}

inline Matrix Matrix::inverse() const
{
	Matrix inverse(*this);
	D3DXMatrixInverse((D3DXMATRIX*)&inverse, NULL, (D3DXMATRIX*)&inverse);
	return inverse;
}

inline Matrix Matrix::CreateTranslation(const Vector3& translation)
{
	Matrix m;
	D3DXMatrixTranslation((D3DXMATRIX*)&m, translation.x, translation.y, translation.z);
	return m;
}

inline Matrix Matrix::CreateTransform(const Vector3* scalingCenter, const Quaternion* scalingRotation, const Vector3* scaling, const Vector3* rotationCenter, const Quaternion* rotation, const Vector3* translation)
{
	Matrix m;
	D3DXMatrixTransformation((D3DXMATRIX*)&m, (D3DXVECTOR3*)scalingCenter, (D3DXQUATERNION*)scalingRotation, (D3DXVECTOR3*)scaling, (D3DXVECTOR3*)rotationCenter, (D3DXQUATERNION*)rotation, (D3DXVECTOR3*)translation);
	return m;
}

inline Matrix Matrix::CreateIdentity()
{
	Matrix m;
	m._11 = 1.0f; m._12 = 0.0f; m._13 = 0.0f; m._14 = 0.0f;
    m._21 = 0.0f; m._22 = 1.0f; m._23 = 0.0f; m._24 = 0.0f;
    m._31 = 0.0f; m._32 = 0.0f; m._33 = 1.0f; m._34 = 0.0f;
    m._41 = 0.0f; m._42 = 0.0f; m._43 = 0.0f; m._44 = 1.0f;
    return m;
}

inline Quaternion::Quaternion( const float* pf )
{
    x = pf[0];
    y = pf[1];
    z = pf[2];
    w = pf[3];
}

inline Quaternion::Quaternion( float fx, float fy, float fz, float fw )
{
    x = fx;
    y = fy;
    z = fz;
    w = fw;
}

inline Quaternion::Quaternion( const Matrix& m )
{
	D3DXQuaternionRotationMatrix((D3DXQUATERNION*)this, (D3DXMATRIX*)&m);
}

inline Quaternion::operator float* ()
{
    return (float *) &x;
}

inline Quaternion::operator const float* () const
{
    return (const float *) &x;
}

inline Quaternion& Quaternion::operator += ( const Quaternion& q )
{
    x += q.x;
    y += q.y;
    z += q.z;
    w += q.w;
    return *this;
}

inline Quaternion& Quaternion::operator -= ( const Quaternion& q )
{
    x -= q.x;
    y -= q.y;
    z -= q.z;
    w -= q.w;
    return *this;
}

inline Quaternion& Quaternion::operator *= ( const Quaternion& q )
{
    D3DXQuaternionMultiply((D3DXQUATERNION*)this, (D3DXQUATERNION*)this, (D3DXQUATERNION*)&q);
    return *this;
}

inline Quaternion& Quaternion::operator *= ( float f )
{
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
}

inline Quaternion& Quaternion::operator /= ( float f )
{
    float fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    z *= fInv;
    w *= fInv;
    return *this;
}

inline Quaternion Quaternion::operator + () const
{
    return *this;
}

inline Quaternion Quaternion::operator - () const
{
    return Quaternion(-x, -y, -z, -w);
}

inline Quaternion Quaternion::operator + ( const Quaternion& q ) const
{
    return Quaternion(x + q.x, y + q.y, z + q.z, w + q.w);
}

inline Quaternion Quaternion::operator - ( const Quaternion& q ) const
{
    return Quaternion(x - q.x, y - q.y, z - q.z, w - q.w);
}

inline Quaternion Quaternion::operator * ( const Quaternion& q ) const
{
    Quaternion qT;
    D3DXQuaternionMultiply((D3DXQUATERNION*)&qT, (D3DXQUATERNION*)this, (D3DXQUATERNION*)&q);
    return qT;
}

inline Quaternion Quaternion::operator * ( float f ) const
{
    return Quaternion(x * f, y * f, z * f, w * f);
}

inline Quaternion Quaternion::operator / ( float f ) const
{
    float fInv = 1.0f / f;
    return Quaternion(x * fInv, y * fInv, z * fInv, w * fInv);
}


inline Quaternion operator * (float f, const Quaternion& q )
{
    return Quaternion(f * q.x, f * q.y, f * q.z, f * q.w);
}


inline bool Quaternion::operator == ( const Quaternion& q ) const
{
    return x == q.x && y == q.y && z == q.z && w == q.w;
}

inline bool Quaternion::operator != ( const Quaternion& q ) const
{
    return x != q.x || y != q.y || z != q.z || w != q.w;
}

inline Quaternion Quaternion::inverse() const
{
	return Quaternion(-x, -y, -z, w);
}

inline Quaternion Quaternion::normalize() const
{
	float magnitude = 1 / sqrtf(x * x + y * y + z * z + w * w);
	return Quaternion(x * magnitude, y * magnitude, z * magnitude, w * magnitude);
}

inline Quaternion Quaternion::conjugate() const
{
	Quaternion conjugate(*this);
	D3DXQuaternionConjugate((D3DXQUATERNION*)&conjugate, (D3DXQUATERNION*)&conjugate);
	return conjugate;
}

inline Quaternion Quaternion::CreateFromYawPitchRoll(const float yaw, const float pitch, const float roll)
{
	Quaternion q;
	D3DXQuaternionRotationYawPitchRoll((D3DXQUATERNION*)&q, yaw, pitch, roll);
	return q;
}

inline Quaternion Quaternion::CreateFromRotationAxis(const Vector3& axis, const float angle)
{
	Quaternion q;
	D3DXQuaternionRotationAxis((D3DXQUATERNION*)&q, (D3DXVECTOR3*)&axis, angle);
	return q;
}

inline Color::Color( unsigned dw )
{
    const float f = 1.0f / 255.0f;
    r = f * (float) (unsigned char) (dw >> 16);
    g = f * (float) (unsigned char) (dw >>  8);
    b = f * (float) (unsigned char) (dw >>  0);
    a = f * (float) (unsigned char) (dw >> 24);
}

inline Color::Color( const float* pf )
{
    r = pf[0];
    g = pf[1];
    b = pf[2];
    a = pf[3];
}

inline Color::Color( float fr, float fg, float fb, float fa )
{
    r = fr;
    g = fg;
    b = fb;
    a = fa;
}

inline Color::operator unsigned () const
{
    unsigned dwR = r >= 1.0f ? 0xff : r <= 0.0f ? 0x00 : (unsigned) (r * 255.0f + 0.5f);
    unsigned dwG = g >= 1.0f ? 0xff : g <= 0.0f ? 0x00 : (unsigned) (g * 255.0f + 0.5f);
    unsigned dwB = b >= 1.0f ? 0xff : b <= 0.0f ? 0x00 : (unsigned) (b * 255.0f + 0.5f);
    unsigned dwA = a >= 1.0f ? 0xff : a <= 0.0f ? 0x00 : (unsigned) (a * 255.0f + 0.5f);

    return (dwA << 24) | (dwR << 16) | (dwG << 8) | (dwB << 0);
}

inline Color::operator float * ()
{
    return (float *) &r;
}

inline Color::operator const float * () const
{
    return (const float *) &r;
}

inline Color& Color::operator += ( const Color& c )
{
    r += c.r;
    g += c.g;
    b += c.b;
    a += c.a;
    return *this;
}

inline Color& Color::operator -= ( const Color& c )
{
    r -= c.r;
    g -= c.g;
    b -= c.b;
    a -= c.a;
    return *this;
}

inline Color& Color::operator *= ( float f )
{
    r *= f;
    g *= f;
    b *= f;
    a *= f;
    return *this;
}

inline Color& Color::operator /= ( float f )
{
    float fInv = 1.0f / f;
    r *= fInv;
    g *= fInv;
    b *= fInv;
    a *= fInv;
    return *this;
}

inline Color Color::operator + () const
{
    return *this;
}

inline Color Color::operator - () const
{
    return Color(-r, -g, -b, -a);
}

inline Color Color::operator + ( const Color& c ) const
{
    return Color(r + c.r, g + c.g, b + c.b, a + c.a);
}

inline Color Color::operator - ( const Color& c ) const
{
    return Color(r - c.r, g - c.g, b - c.b, a - c.a);
}

inline Color Color::operator * ( float f ) const
{
    return Color(r * f, g * f, b * f, a * f);
}

inline Color Color::operator / ( float f ) const
{
    float fInv = 1.0f / f;
    return Color(r * fInv, g * fInv, b * fInv, a * fInv);
}

inline Color operator * (float f, const Color& c )
{
    return Color(f * c.r, f * c.g, f * c.b, f * c.a);
}

inline bool Color::operator == ( const Color& c ) const
{
    return r == c.r && g == c.g && b == c.b && a == c.a;
}

inline bool Color::operator != ( const Color& c ) const
{
    return r != c.r || g != c.g || b != c.b || a != c.a;
}