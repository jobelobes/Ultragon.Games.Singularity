#pragma region Properties
inline const unsigned Material::Get_PassCount() const { return this->m_pShader->m_sTechniqueDesc.Passes; };

inline void Material::Set_Pass(const unsigned value) { this->m_iPass = value; };

inline const Color Material::Get_Color() const { return this->m_kDescription.Color; };
inline void Material::Set_Color(const Color value) { this->m_kDescription.Color = value; };

inline const Texture2D* Material::Get_MainTexture() const { return this->m_pTexture; };
inline void Material::Set_MainTexture(Texture2D* value) { this->m_pTexture = value; };
#pragma endregion