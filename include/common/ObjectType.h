#include "common\Singularity.Common.h"

namespace Singularity
{
	class ObjectType
	{
		private:
			#pragma region Variables
			String				m_pName;
			const ObjectType*	m_pBaseType;
			#pragma endregion

		public:
			#pragma region Properties
			inline const String Get_FullName() const { return this->m_pName; };
			#pragma endregion

			#pragma region Constructors and Finalizers
			ObjectType(const String& name, const ObjectType* baseType);
			~ObjectType();
			#pragma endregion

			#pragma region Methods
			bool Equals(const ObjectType& type) const;
			bool IsSubClassOf(const ObjectType& type) const;
			#pragma endregion
	};
}