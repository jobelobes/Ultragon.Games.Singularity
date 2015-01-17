#include "common\Singularity.Common.h"

namespace Singularity
{
	template<class Method, class Target>
	class CallbackDelegate : public IDelegate
	{
		private:
			#pragma region Variables
			DynamicSet<Method>	m_pMethods;
			Target				m_pTarget;
			#pragma endregion

		public:
			#pragma region Constructors and Finalizers
			CallbackDelegate(const Method& method, Target target);
			#pragma endregion

			#pragma region Methods
			void Invoke();
			#pragma endregion
	};

	#pragma region Constructors and Finalizers
	template<class Method, class Target>
	CallbackDelegate<Method, Target>::CallbackDelegate(const Method& method, Target target)
		: m_pTarget(target)
	{
		this->m_pMethods.insert(method);
	}
	#pragma endregion

	#pragma region Methods
	template<class Method, class Target>
	void CallbackDelegate<Method, Target>::Invoke()
	{
		(*this->m_pMethods.begin())(this->m_pTarget);
	}
	#pragma endregion
}