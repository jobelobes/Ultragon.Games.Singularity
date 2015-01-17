#pragma region Properties
inline const bool Renderer::Get_IsVisible() const { return this->m_bVisible; }

inline Material* Renderer::Get_Material() const { return this->m_pMaterial; }
inline void Renderer::Set_Material(Material* value) { this->m_pMaterial = value; }

inline const bool Renderer::Get_IsTiedToCamera() const { return this->m_bTiedToCamera; }

inline const Bounds Renderer::Get_Bounds() const{ return Bounds(this->Get_GameObject()->Get_Transform()->Get_Position(), Vector3(1,1,1)); }
#pragma endregion

#pragma region Methods
inline void Renderer::RegisterCallback(RenderCallback value){ this->m_pCallback = value; }
#pragma endregion