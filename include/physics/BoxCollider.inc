#pragma region Properties
inline Vector3& BoxCollider::Get_Size() { return this->m_kSize; };
inline void BoxCollider::Set_Size(const Vector3& value) 
{ 
	this->m_kSize = Vector3(max(0.0f, value.x), max(0.0f, value.y), max(0.0f, value.z)); 
};
#pragma endregion
