#pragma region Properties
inline Vector3 Transform::Get_ParentPosition()
{
	GameObject* obj = this->Get_GameObject()->Get_Parent();
	if(obj)
	{
		Matrix world = obj->Get_Transform()->Get_LocalToWorldMatrix();
		return Vector3( world._41, world._42, world._43);
	}
	else
		return Vector3(0,0,0);
}

inline Quaternion Transform::Get_ParentRotation()
{
	GameObject* obj = this->Get_GameObject()->Get_Parent();
	if(obj)
	{
		Quaternion rotation;
		Matrix world = obj->Get_Transform()->Get_LocalToWorldMatrix();
		return Quaternion(world).normalize();
	}
	else
		return Quaternion(0,0,0,1);
}

inline Vector3 Transform::Get_ParentScale()
{
	GameObject* obj = this->Get_GameObject()->Get_Parent();
	if(obj)
	{
		Matrix world = obj->Get_Transform()->Get_LocalToWorldMatrix();
		Vector3 scale;
		scale.x = Vector3(world._11, world._12, world._13).length(); 
		scale.y = Vector3(world._21, world._22, world._23).length();
		scale.z = Vector3(world._31, world._32, world._33).length();
		return scale;
	}
	else
		return Vector3(1,1,1);
}

inline Matrix Transform::Get_ParentLocalToWorldMatrix()
{
	Matrix ltw;
	GameObject* obj = this->Get_GameObject()->Get_Parent();
	if(obj)
		ltw = obj->Get_Transform()->Get_LocalToWorldMatrix();

	return ltw;
}

inline Vector3 Transform::Get_Position() 
{ 
	Matrix world = this->Get_LocalToWorldMatrix();
	return Vector3(world._41, world._42, world._43);
};

inline void Transform::Set_Position(Vector3& value) 
{ 
	this->SetDirty(); 
	this->m_kPosition = value - this->Get_ParentPosition(); 
};

inline Quaternion Transform::Get_Rotation() 
{ 
	return Quaternion(this->Get_LocalToWorldMatrix());
};

inline void Transform::Set_Rotation(Quaternion& value) 
{
	this->SetDirty();
	
	Quaternion parent = this->Get_ParentRotation().inverse();
	this->m_kRotation = parent * value;
};

inline void Transform::Set_Rotation(Vector3& value) 
{
	this->Set_Rotation(Quaternion::CreateFromYawPitchRoll(value.y, value.x, value.z));
};

inline Vector3 Transform::Get_Scale() 
{ 
	Vector3 parent = this->Get_ParentScale();
	return Vector3(parent.x * this->m_kScale.x, parent.y * this->m_kScale.y, parent.z * this->m_kScale.z);
}

inline void Transform::Set_Scale(Vector3& value)
{
	Vector3 parent = this->Get_ParentScale();
	this->SetDirty(); 
	this->m_kScale = Vector3(value.x / parent.x, value.y / parent.y, value.z / parent.z);
}

inline Vector3& Transform::Get_LocalPosition() { return this->m_kPosition; };
inline void Transform::Set_LocalPosition(Vector3& value) { this->SetDirty(); this->m_kPosition = value; };

inline Quaternion& Transform::Get_LocalRotation() { return this->m_kRotation; };
inline void Transform::Set_LocalRotation(Quaternion& value) { this->SetDirty(); this->m_kRotation = value; };

inline Vector3& Transform::Get_LocalScale() { return this->m_kScale; };
inline void Transform::Set_LocalScale(Vector3& value) { this->SetDirty(); this->m_kScale = value; };

inline void Transform::SetDirty()
{
	this->m_bDirty = true;
	
	for(unsigned i = 0; i < this->Changed.Count(); ++i)
		if(this->Changed[i]->GetType().Equals(TransformDelegate::Type))
			((TransformDelegate*)this->Changed[i])->Invoke(this);
}