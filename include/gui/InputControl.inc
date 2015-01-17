#pragma region Methods
inline void InputControl::RegisterClickCallback(GuiCallback value){ this->m_pClickCallback = value; }
inline void InputControl::RegisterMouseoverCallback(GuiCallback value){ this->m_pMouseoverCallback = value; }
#pragma endregion