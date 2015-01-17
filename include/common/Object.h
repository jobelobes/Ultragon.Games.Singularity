#include "common\Singularity.Common.h"

namespace Singularity
{
	class Object
	{
		public:
			#pragma region Static Variables
			static const ObjectType Type;
			#pragma endregion

			#pragma region Methods
			virtual const ObjectType& GetType() const { return Type; };
			#pragma endregion
	};
}