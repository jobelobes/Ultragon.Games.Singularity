#pragma region Properties
inline Mesh* MeshRenderer::Get_Mesh() const { return this->m_pMesh; }
inline void MeshRenderer::Set_Mesh(Mesh* value) { this->m_pMesh = value; }

inline unsigned MeshRenderer::Get_Layer() const { return this->m_pLayer; }
inline void MeshRenderer::Set_Layer(unsigned value) { this->m_pLayer = value; }
#pragma endregion