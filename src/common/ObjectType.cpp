#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Constructors and Finalizers
	ObjectType::ObjectType(const String& name, const ObjectType* baseType)
		: m_pName(name), m_pBaseType(baseType) {}
	
	ObjectType::~ObjectType(){}
	#pragma endregion

	#pragma region Methods
	bool ObjectType::Equals(const ObjectType& type) const
	{
		return &type == this;
	}

	bool ObjectType::IsSubClassOf(const ObjectType& type) const
	{
		const ObjectType* searchType = this;
		while(searchType)
		{
			if(searchType == &type)
				return true;
			searchType = searchType->m_pBaseType;
		}
		return false;
	}
	#pragma endregion
}