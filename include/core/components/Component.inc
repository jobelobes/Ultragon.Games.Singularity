#pragma region Properties
inline String Component::Get_Name() const { return this->m_pName; };

inline GameObject* Component::Get_GameObject() const { return this->m_pGameObject; };

inline const bool Component::Get_Enabled() const { return this->m_bEnabled & this->m_pGameObject->Get_IsActive(); };
inline void Component::Set_Enabled(const bool value) { this->m_bEnabled = value; };
#pragma endregion