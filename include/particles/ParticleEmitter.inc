#pragma region Properties
inline void ParticleEmitter::Set_LifeTime(float value) { this->m_fLifeTime = value; }

inline void ParticleEmitter::Set_MainTexture(Singularity::Graphics::Texture2D* value) { this->m_pMainTexture = value; }
inline void ParticleEmitter::Set_SecondaryTexture(Singularity::Graphics::Texture2D* value) { this->m_pSecondaryTexture = value; }
inline void ParticleEmitter::Set_TertiaryTexture(Singularity::Graphics::Texture2D* value) { this->m_pTertiaryTexture = value; }

inline void ParticleEmitter::Set_ParticleCount(int value) { this->m_iParticleCount = value; }

inline void ParticleEmitter::Set_PositionOffset(Vector3 value) { this->m_kTranslation + value; }

inline void ParticleEmitter::Set_Radius(float value) { this->m_fRadius = value; }
inline void ParticleEmitter::Set_Radius2(float value) { this->m_fRadius2 = value; }

inline void ParticleEmitter::Set_EmitterRepeats(int value) { this->m_iEmitterRepeats = value; }
inline void ParticleEmitter::Set_ParticleRepeats(int value) { this->m_iParticleRepeats = value; }
inline void ParticleEmitter::Set_ParticleSize(float value) { this->m_iParticleSize = value; }

inline void ParticleEmitter::Set_Dimensions(Vector3 value) { this->m_kDimensions = value; }
inline void ParticleEmitter::Set_Direction(Vector3 value) { this->m_kDirection = value; }

inline void ParticleEmitter::Set_Delay(float value) { this->m_fDelay = value; }

inline void ParticleEmitter::Set_RandomizeColor(bool value) { this->m_bRandomizeColor = value; }
inline void ParticleEmitter::Set_ColorLimit(Color value) { this->m_kColorLimit = value; }

inline EmitterType ParticleEmitter::Get_EmitterType() { return this->m_eType; }
inline void ParticleEmitter::Set_EmitterType(EmitterType value)
{
	this->m_eType = value;
	this->Reset();
}

#pragma endregion