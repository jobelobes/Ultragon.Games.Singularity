#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Gui;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaControlDelegate, Singularity::Gui::ControlDelegate);

		#pragma region Constructors and Finalizers
		LuaControlDelegate::LuaControlDelegate(unsigned luaFuncRef) 
			: ControlDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
		}

		LuaControlDelegate::~LuaControlDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaControlDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
			tolua_pushusertype(state, this->m_pControl, "Singularity::Gui::Control");

			if(lua_pcall(state, 1, 0, 0) != 0)
				printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));

			this->m_pInvoked = false;
		}

		void LuaControlDelegate::Invoke(Control* control)
		{
			this->m_pInvoked = true;
			this->m_pControl = control;
		}
		#pragma endregion
	}
}