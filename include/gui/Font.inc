#pragma region Methods
inline String Font::Get_FontName() { return m_cName; };
inline Texture2D* Font::Get_FontSpriteSheet() { return m_pSprite; };
inline int Font::Get_Kerning() const { return this->m_iKerning; };
inline void Font::Set_Kerning(int value) { this->m_iKerning = value; };
#pragma endregion