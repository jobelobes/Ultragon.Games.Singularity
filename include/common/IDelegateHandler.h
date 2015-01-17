#include "common\Singularity.Common.h"

namespace Singularity
{
	class IDelegateHandler
	{
		public:
			#pragma region Methods
			virtual void Add(IDelegate* method) = 0;
			virtual void Remove(IDelegate* method) = 0;
			#pragma endregion

			#pragma region Overriden Operators
			virtual DelegateHandler& operator += (IDelegate* method) = 0;
			virtual DelegateHandler& operator -= (IDelegate* method) = 0;
			virtual bool operator == (const DelegateHandler* other) const = 0;
			#pragma endregion
	};
}