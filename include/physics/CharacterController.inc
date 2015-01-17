#pragma region Properties
inline const float CharacterController::Get_Radius() const { return this->m_fRadius; };
inline void CharacterController::Set_Radius(const float value) { this->m_fRadius = max(0.0f, value); };

inline const float CharacterController::Get_Height() const { return this->m_fHeight; };
inline void CharacterController::Set_Height(const float value) { this->m_fHeight = max(0.0f, value); };

inline const float CharacterController::Get_SlopeLimit() const { return this->m_fSlopeLimit; };
inline void CharacterController::Set_SlopeLimit(const float value) { this->m_fSlopeLimit = value; };

inline const float CharacterController::Get_StepOffset() const { return this->m_fStepOffset; };
inline void CharacterController::Set_StepOffset(const float value) { this->m_fStepOffset = value; };
#pragma endregion