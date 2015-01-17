#pragma region Properties
inline const UUID GameObject::Get_Id() const { return this->m_kId; };

inline const String GameObject::Get_Name() const { return this->m_kName; };

inline const bool GameObject::Get_IsActive() const { return this->m_bActive; };

inline Transform* GameObject::Get_Transform() { return this->m_pTransform; };

inline GameObject* GameObject::Get_Root() { return this->m_pRoot; };

inline GameObject* GameObject::Get_Parent() const { return this->m_pParent; };
inline void GameObject::Set_Parent(GameObject* parent) { this->m_pParent->DetachChild(this); parent->AttachChild(parent); };
#pragma endregion