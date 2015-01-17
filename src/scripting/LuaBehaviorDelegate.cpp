#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaBehaviorDelegate, Singularity::Components::BehaviorDelegate);

		#pragma region Constructors and Finalizers
		LuaBehaviorDelegate::LuaBehaviorDelegate(unsigned luaFuncRef) 
			: BehaviorDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
		}

		LuaBehaviorDelegate::~LuaBehaviorDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaBehaviorDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
			tolua_pushusertype(state, this->m_pBehavior, "Singularity::Component::Behavior");
			tolua_pushnumber(state, this->m_fElapsedTime);

			if(lua_pcall(state, 2, 0, 0) != 0)
				printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));

			this->m_pInvoked = false;
		}

		void LuaBehaviorDelegate::Invoke(Behavior* behavior, float elapsedTime)
		{
			this->m_pInvoked = true;
			this->m_pBehavior = behavior;
			this->m_fElapsedTime = elapsedTime;
		}
		#pragma endregion
	}
}