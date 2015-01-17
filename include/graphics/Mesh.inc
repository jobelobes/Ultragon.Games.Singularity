#pragma region Methods
inline const Bounds Mesh::Get_Bounds() const { return this->m_kBounds; };

inline PrimitiveTopology Mesh::Get_Topology() const { return this->m_kTopology; };
inline void Mesh::Set_Topology(PrimitiveTopology value) { this->m_kTopology = value; };

inline VertexBuffer* Mesh::Get_VertexBuffer() const { return this->m_pVertices; };
inline void Mesh::Set_VertexBuffer(VertexBuffer* value) { this->m_pVertices = value; };

inline IndexBuffer* Mesh::Get_IndexBuffer() const { return this->m_pIndices; };
inline void Mesh::Set_IndexBuffer(IndexBuffer* value) { this->m_pIndices = value; };
#pragma endregion