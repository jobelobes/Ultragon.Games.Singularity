#pragma region Methods
template<typename MethodSignature>
void DelegateHandler2<MethodSignature>::Add(MethodSignature method)
{
	this->m_pMethods.insert(method);
}

template<typename MethodSignature>
void DelegateHandler2<MethodSignature>::Remove(MethodSignature method)
{
	this->m_pMethods.erase(method);
}
#pragma endregion

#pragma region Overriden Operators
template<typename MethodSignature>
DelegateHandler2<MethodSignature>& DelegateHandler2<MethodSignature>::operator += (MethodSignature method)
{
	this->m_pMethods.insert(method);
	return *this;
}

template<typename MethodSignature>
DelegateHandler2<MethodSignature>& DelegateHandler2<MethodSignature>::operator -= (MethodSignature method)
{
	this->m_pMethods.erase(method);
	return *this;
}

template<typename MethodSignature>
bool DelegateHandler2<MethodSignature>::operator == (const DelegateHandler2<MethodSignature>* other) const
{
	if(this->m_pMethods.size() == 0 && other == NULL)
		return true;
	return false;
}
#pragma endregion