#pragma region Properties

inline int NinePatch::Get_Height() const { return (int)this->m_kSize.y; };
inline void NinePatch::Set_Height(int value) { this->m_kSize.y = (float)value; }

inline int NinePatch::Get_Width() const { return (int)this->m_kSize.x; };
inline void NinePatch::Set_Width(int value) { this->m_kSize.x = (float)value; }


inline Vector4 NinePatch::Get_Padding() const { return this->m_kPadding; };
inline void NinePatch::Set_Padding(Vector4 value) { this->m_kPadding = value; }

#pragma endregion