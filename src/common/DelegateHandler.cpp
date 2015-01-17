#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Constructors and Finalizers
	DelegateHandler::DelegateHandler() { }

	DelegateHandler::~DelegateHandler()
	{
		this->m_pDelegates.clear();
	}
	#pragma endregion

	#pragma region Methods
	unsigned DelegateHandler::Count() { return this->m_pDelegates.size(); }
	#pragma endregion

	#pragma region Methods
	void DelegateHandler::Add(IDelegate* method)
	{
		this->m_pDelegates.push_back(method);
	}
	
	void DelegateHandler::Remove(IDelegate* method)
	{
		//this->m_pDelegates.erase(method);
	}

	void DelegateHandler::Clear()
	{
		this->m_pDelegates.clear();
	}
	#pragma endregion

	#pragma region Overriden Operators
	DelegateHandler& DelegateHandler::operator += (IDelegate* method)
	{
		this->m_pDelegates.push_back(method);
		return *this;
	}

	DelegateHandler& DelegateHandler::operator -= (IDelegate* method)
	{
		//this->m_pDelegates.erase(method);
		return *this;
	}
	bool DelegateHandler::operator == (const DelegateHandler* other) const
	{
		if(this->m_pDelegates.size() == 0 && other == NULL)
			return true;
		return false;
	}
	IDelegate* DelegateHandler::operator [] (unsigned index) const
	{
		if(index >= this->m_pDelegates.size())
			return NULL;

		return this->m_pDelegates[index];
	}
	#pragma endregion
}