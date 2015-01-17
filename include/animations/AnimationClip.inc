inline float AnimationClip::Get_Duration() const { return this->m_fDuration; };
inline void AnimationClip::Set_Duration(float value) { this->m_fDuration = value; }

inline DynamicList<Frame> AnimationClip::Get_Frames() { return this->m_pFrames; };
	
inline unsigned AnimationClip::Get_FrameCount() const { return this->m_pFrames.size(); };

inline String AnimationClip::Get_Name() const { return this->m_sName; };
							
inline void AnimationClip::AddKeyframe(Frame value) { this->m_pFrames.push_back(value); }