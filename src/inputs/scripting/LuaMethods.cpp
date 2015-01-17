#include "inputs\scripting\Singularity.Inputs.Scripting.h"

using namespace Singularity::Scripting;

namespace Singularity
{
	namespace Inputs
	{
		namespace Scripting
		{
			#pragma region Static Variables
			LuaMethods* LuaMethods::g_iInstance = LuaMethods::Register();
			#pragma endregion

			#pragma region Static Methods
			int LuaMethods::lua_GetMousePosition(lua_State* state)
			{
				LuaRuntime::Dump();
				Vector2 pos = Input::GetMousePosition();
				lua_pushnumber(state, pos.x);
				lua_pushnumber(state, pos.y);
				return 2;
			}

			int LuaMethods::lua_GetKey(lua_State* state)
			{
				int key = luaL_optint(state, 1, 0);
				lua_pushboolean(state, Input::GetKey(key));
				return 1;
			}

			LuaMethods* LuaMethods::Register()
			{
				LuaRuntime::RegisterFunction("GetMousePosition", (lua_CFunction)LuaMethods::lua_GetMousePosition);
				LuaRuntime::RegisterFunction("GetKey", (lua_CFunction)LuaMethods::lua_GetKey);
				return NULL;
			}
			#pragma endregion
		}
	}
}