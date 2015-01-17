#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaBehaviorDelegate : public Singularity::Components::BehaviorDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned							m_pLuaFuncRef;
				Singularity::Components::Behavior*	m_pBehavior;
				float								m_fElapsedTime;
				bool								m_pInvoked;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaBehaviorDelegate(unsigned luaFuncRef);
				~LuaBehaviorDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Components::Behavior* behavior, float elapsedTime);
				#pragma endregion

				friend class LuaTask;
		};
	}
}