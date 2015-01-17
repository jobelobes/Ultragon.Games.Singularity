#pragma region Properties
inline const LightType Light::Get_Type() const { return (LightType)this->m_kDescription.Type; };
inline void Light::Set_Type(const LightType value) { this->m_kDescription.Type = value; };

inline const Color Light::Get_Color() const { return this->m_kDescription.Color; };
inline void Light::Set_Color(Color value) { this->m_kDescription.Color = value; };

inline const float Light::Get_Falloff() const { return this->m_kDescription.Falloff; };
inline void Light::Set_Falloff(const float value) { this->m_kDescription.Falloff = value; };

inline const float Light::Get_Range() const { return this->m_kDescription.Range; };
inline void Light::Set_Range(const float value) { this->m_kDescription.Range = value; };

inline const float Light::Get_Intensity() const { return this->m_kDescription.Intensity; };
inline void Light::Set_Intensity(const float value) { this->m_kDescription.Intensity = value; };
#pragma endregion