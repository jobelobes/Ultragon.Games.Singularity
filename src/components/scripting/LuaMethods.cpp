#include "components\scripting\Singularity.Components.Scripting.h"

using namespace Singularity::Scripting;

namespace Singularity
{
	namespace Components
	{
		namespace Scripting
		{
			#pragma region Static Variables
			LuaMethods* LuaMethods::g_iInstance = LuaMethods::Register();
			#pragma endregion

			#pragma region Static Methods
			int LuaMethods::lua_GetGameObject(lua_State* state)
			{
				/*lua_getfield(state, LUA_GLOBALSINDEX, "Component");
				lua_setmetatable(state, -1);*/
				lua_pushnumber(state, 1);
				return 0;
			}

			LuaMethods* LuaMethods::Register()
			{
				/*int m_iThisRef;
				LuaRuntime* runtime = LuaRuntime::Create();
				lua_createtable(runtime->Stack, 0, 0);

				luaL_ref(runtime->Stack, LUA_REGISTRYINDEX)
				lua_rawgeti (state, LUA_REGISTRYINDEX, m_iThisRef);
				lua_pushlightuserdata (state, (void*)this);
				lua_rawseti (state, -2, 0);


				lua_createtable(runtime->Stack, 0, 1);
				lua_pushcfunction(runtime->Stack, (lua_CFunction)LuaMethods::lua_GetGameObject);
				lua_setfield(runtime->Stack, -2, "Get_GameObject");
				lua_setmetatable(runtime->Stack, -2);
				lua_setfield(runtime->Stack, LUA_GLOBALSINDEX, "Component");
				lua_pop(runtime->Stack, -1);
				lua_pop(runtime->Stack, -2);
				LuaRuntime::Dump();

				LuaRuntime::RegisterFunction("Get_GameObject", (lua_CFunction)LuaMethods::lua_GetGameObject);*/
				return NULL;
			}
			#pragma endregion
		}
	}
}