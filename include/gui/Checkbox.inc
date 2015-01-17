#pragma region Properties
inline const bool Checkbox::Get_IsChecked() const { return this->m_bIsChecked; };
inline void Checkbox::Set_IsChecked(const bool value) { this->m_bIsChecked = value; };
inline void Checkbox::Set_UncheckedTexture(NinePatch* value) { this->m_pUncheckedTexture = value; if(!this->m_bIsChecked) this->Set_Texture(this->m_pUncheckedTexture);};
inline void Checkbox::Set_CheckedTexture(NinePatch* value) { this->m_pCheckedTexture = value; if(this->m_bIsChecked) this->Set_Texture(this->m_pCheckedTexture);};
#pragma endregion