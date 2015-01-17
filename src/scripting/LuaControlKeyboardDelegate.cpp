#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Gui;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaControlKeyboardDelegate, Singularity::Gui::ControlDelegate);

		#pragma region Constructors and Finalizers
		LuaControlKeyboardDelegate::LuaControlKeyboardDelegate(unsigned luaFuncRef) 
			: ControlKeyboardDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
		}

		LuaControlKeyboardDelegate::~LuaControlKeyboardDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaControlKeyboardDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
			tolua_pushusertype(state, this->m_pControl, "Singularity::Gui::Control");
			tolua_pushboolean(state, this->m_bShift);
			tolua_pushboolean(state, this->m_bControl);
			tolua_pushnumber(state, this->m_iKeyindex);

			if(lua_pcall(state, 4, 0, 0) != 0)
				printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));

			this->m_pInvoked = false;
		}

		void LuaControlKeyboardDelegate::Invoke(Control* control, bool isShift, bool isControl, int keyIndex)
		{
			this->m_pInvoked = true;
			this->m_pControl = control;
			this->m_bShift = isShift;
			this->m_bControl = isControl;
			this->m_iKeyindex = keyIndex;
		}
		#pragma endregion
	}
}