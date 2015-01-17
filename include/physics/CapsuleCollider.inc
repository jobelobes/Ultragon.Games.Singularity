#pragma region Properties
inline const float CapsuleCollider::Get_Radius() const { return this->m_fRadius; };
inline void CapsuleCollider::Set_Radius(const float value) 
{ 
	this->m_fRadius = max(0.0f, value); 
	if(this->m_pCollisionShape) 
	{
		btCapsuleShape* shape = (btCapsuleShape*)this->m_pCollisionShape;
		float scale = this->m_fRadius / shape->getRadius();
		shape->setLocalScaling(btVector3(scale, 1.0f, scale));
	}
};

inline const float CapsuleCollider::Get_Height() const { return this->m_fHeight; };
inline void CapsuleCollider::Set_Height(const float value) 
{ 
	this->m_fHeight = max(0.0f, value); 
	if(this->m_pCollisionShape) 
	{
		btCapsuleShape* shape = (btCapsuleShape*)this->m_pCollisionShape;
		float scale = (this->m_fHeight * 0.5f) / shape->getHalfHeight();
		shape->setLocalScaling(btVector3(1.0f, scale, 1.0f));
	}
};
#pragma endregion