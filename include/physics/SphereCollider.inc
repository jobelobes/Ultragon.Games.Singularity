#pragma region Properties
inline const float SphereCollider::Get_Radius() const { return this->m_fRadius; };
inline void SphereCollider::Set_Radius(const float value) { this->m_fRadius = max(0.0f, value); };
#pragma endregion