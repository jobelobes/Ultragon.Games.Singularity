#pragma region Properties
inline const bool Control::Get_HasFocus() const { return this->m_bHasFocus; };

inline String Control::Get_Name() const { return this->m_kName; };
inline void Control::Set_Name(String value) { this->m_kName = value; };

inline float Control::Get_Depth() const { return this->m_fDepth; };

inline Vector2 Control::Get_Size() const { return this->m_sSize; }

inline NinePatch* Control::Get_Texture() const { return this->m_pTexture; }
inline void Control::Set_Texture(NinePatch* value) { this->m_pTexture = value; this->m_bNeedToRecalc = true; };

inline const bool Control::Get_Visible() const { return this->m_bVisible; };

inline const bool Control::Get_Enabled() const { return this->m_bEnabled; };

inline Control* Control::Get_Parent() const { return this->m_pParent; }
inline void Control::Set_Parent(Control* value) { this->m_pParent = value; this->m_bNeedToRecalc = true; }

inline void Control::Set_Color(Color color) { this->m_pMaterial->Set_Color(color); };

inline int Control::Get_NumberOfChildren() const { return this->m_pChildControls.size(); };

inline Material* Control::Get_Material() const { return this->m_pMaterial; }
inline void Control::Set_Material(Material* value) { this->m_pMaterial = value; }
#pragma endregion