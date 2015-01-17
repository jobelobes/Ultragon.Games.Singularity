#pragma region Properties
inline const bool Camera::Get_Orthographic() const { return this->m_bOrthographic; };
inline void Camera::Set_Orthographic(const bool value) { this->m_bOrthographic = value; };

inline const Color Camera::Get_BackgroundColor() const { return this->m_kBackgroundColor; };
inline void Camera::Set_BackgroundColor(Color value) { this->m_kBackgroundColor = value; };

inline const float Camera::Get_FieldOfView() const { return this->m_fFieldOfView; };
inline void Camera::Set_FieldOfView(const float value) { this->m_fFieldOfView = value; };

inline const float Camera::Get_NearClippingPlane() const { return this->m_fNearClippingPlane; };
inline void Camera::Set_NearClippingPlane(const float value) { this->m_fNearClippingPlane = value; };

inline const float Camera::Get_FarClippingPlane() const { return this->m_fFarClippingPlane; };
inline void Camera::Set_FarClippingPlane(const float value) { this->m_fFarClippingPlane = value; };

inline const float Camera::Get_Aspect() const { return this->m_fAspect; };
inline void Camera::Set_Aspect(const float value) { this->m_fAspect = value; };

inline const float Camera::Get_Width() const { return this->m_fWidth; };

inline const float Camera::Get_Height() const { return this->m_fHeight; };
#pragma endregion
