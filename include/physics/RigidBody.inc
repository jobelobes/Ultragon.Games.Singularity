inline Vector3 RigidBody::Get_Velocity() const 
{ 
	if(this->m_pRigidBody != NULL)
	{
		btVector3 velocity = this->m_pRigidBody->getLinearVelocity(); 
		return Vector3(velocity.getX(), velocity.getY(), velocity.getZ()); 
	}
	return Vector3(0,0,0);
}

inline Vector3 RigidBody::Get_AngularVelocity() const
{ 
	if(this->m_pRigidBody != NULL)
	{
		btVector3 velocity = this->m_pRigidBody->getAngularVelocity(); 
		return Vector3(velocity.getX(), velocity.getY(), velocity.getZ());
	}
	return Vector3(0,0,0);	
}

inline const float RigidBody::Get_Mass() const { return this->m_fMass; };
inline void RigidBody::Set_Mass(const float value)
{
	this->m_fMass = value; 
	if(this->m_pRigidBody != NULL)
	{
		btVector3 inertia;
		this->m_pCollisionShape->calculateLocalInertia(this->m_fMass, inertia);
		this->m_pRigidBody->setMassProps(this->m_fMass, inertia);
	} 
}

inline Vector3 RigidBody::Get_CenterOfMass() const { return this->m_kCenterOfMass; };
inline void RigidBody::Set_CenterOfMass(const Vector3& value) 
{ 
	this->m_kCenterOfMass = value; 
	if(this->m_pRigidBody != NULL)
	{
		btTransform centerOfMass;
		centerOfMass.setOrigin(btVector3(value.x, value.y, value.z));
		this->m_pRigidBody->setCenterOfMassTransform(centerOfMass);
	}
};

inline const bool RigidBody::Get_FreezeRotation() const { return this->m_bFreezeRotation; };
inline void RigidBody::Set_FreezeRotation(const bool value) 
{ 
	this->m_bFreezeRotation = value;
	if(this->m_pRigidBody != NULL)
		this->m_pRigidBody->setAngularFactor(btVector3(value?0.0f:1.0f,value?0.0f:1.0f,value?0.0f:1.0f)); 
};
				
inline float RigidBody::Get_Drag() const { return this->m_fDrag; };
inline void RigidBody::Set_Drag(const float value) 
{
	this->m_fDrag = value;
	if(this->m_pRigidBody != NULL)
		this->m_pRigidBody->setDamping(value, this->m_pRigidBody->getAngularDamping()); 
};

inline float RigidBody::Get_AngularDrag() const { return this->m_fAngularDrag; };
inline void RigidBody::Set_AngularDrag(const float value) 
{
	this->m_fAngularDrag = value; 
	if(this->m_pRigidBody != NULL)
		this->m_pRigidBody->setDamping(this->m_pRigidBody->getLinearDamping(), value); 
};

inline Vector3 RigidBody::Get_Gravity() const { return this->m_kGravity; };
inline void RigidBody::Set_Gravity(const Vector3& value) 
{
	this->m_kGravity = value; 
	if(this->m_pRigidBody != NULL)
		this->m_pRigidBody->setGravity(btVector3(value.x,value.y,value.z)); 
};

inline const bool RigidBody::Get_IgnoreGravity() { return this->m_bIgnoreGravity; };
inline void RigidBody::Set_IgnoreGravity(const bool value) 
{ 
	this->m_bIgnoreGravity = value;
	if(this->m_pRigidBody != NULL)
		this->m_pRigidBody->setGravity(btVector3(value?0:this->m_kGravity.x,value?0:this->m_kGravity.y,value?0:this->m_kGravity.z));
};