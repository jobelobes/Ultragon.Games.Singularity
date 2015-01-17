#include "common\Singularity.Common.h"

namespace Singularity
{
	class DelegateHandler
	{
		private:
			#pragma region Variables
			DynamicList<IDelegate*> m_pDelegates;
			#pragma endregion

		public:
			#pragma region Constructors and Finalizers
			DelegateHandler();
			~DelegateHandler();
			#pragma endregion

			#pragma region Methods
			unsigned Count();
			#pragma endregion

			#pragma region Methods
			void Add(IDelegate* method);
			void Remove(IDelegate* method);
			void Clear();
			#pragma endregion

			#pragma region Overriden Operators
			DelegateHandler& operator += (IDelegate* method);
			DelegateHandler& operator -= (IDelegate* method);
			bool operator == (const DelegateHandler* other) const;
			IDelegate* operator [] (unsigned index) const;
			#pragma endregion
	};
}