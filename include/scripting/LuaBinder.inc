#pragma region Constructors and Finalizers
inline String LuaBinder::Get_Path() const { return this->m_pPath; };
inline void LuaBinder::Set_Path(String value) { this->m_pPath = value; };

inline String LuaBinder::Get_FunctionName() const { return this->m_pFunctionCallback; };
inline void LuaBinder::Set_FunctionName(String value) { this->m_pFunctionCallback = value; };
#pragma endregion