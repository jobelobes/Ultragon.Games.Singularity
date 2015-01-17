#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Gui;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaControlMouseDelegate, Singularity::Gui::ControlMouseDelegate);

		#pragma region Constructors and Finalizers
		LuaControlMouseDelegate::LuaControlMouseDelegate(unsigned luaFuncRef) 
			: ControlMouseDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
		}

		LuaControlMouseDelegate::~LuaControlMouseDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaControlMouseDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
			tolua_pushusertype(state, this->m_pControl, "Singularity::Gui::Control");
			tolua_pushusertype(state, this->m_kPosition, "Vector2");

			if(lua_pcall(state, 2, 0, 0) != 0)
				printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));

			this->m_pInvoked = false;
		}

		void LuaControlMouseDelegate::Invoke(Control* control, Vector2 position)
		{
			this->m_pInvoked = true;
			this->m_pControl = control;
			this->m_kPosition = position;
		}
		#pragma endregion
	}
}