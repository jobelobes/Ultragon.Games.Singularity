#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaRuntime, Singularity::Object);

		#pragma region Static Variables
		LuaRuntime* LuaRuntime::g_pInstance = NULL;
		#pragma endregion

		#pragma region Constructors and Finalizers
		LuaRuntime::LuaRuntime()
		{
			this->Stack = lua_open();
			luaopen_base(this->Stack);
			luaopen_table(this->Stack);
			luaopen_string(this->Stack);
			luaopen_math(this->Stack);
			luaopen_os(this->Stack);

			lua_pushcfunction(this->Stack, luaopen_io);
			lua_call(this->Stack, 0, 0);

			tolua_Singularity_scripting_open(this->Stack);
		}

		LuaRuntime::~LuaRuntime()
		{
			lua_close(this->Stack);
		}
		#pragma endregion

		#pragma region Methods
		void LuaRuntime::LoadFile(String name)
		{
			unsigned error;
			if(luaL_loadfile(LuaRuntime::Create()->Stack, name.c_str()) != 0)
				throw SingularityException("Unknown error loading Lua script file.");

			if((error = lua_pcall(LuaRuntime::g_pInstance->Stack, 0, 0, 0)) != 0)
				throw SingularityException("Unable to add function to lua stack.", error);
		}

		void LuaRuntime::RegisterFunction(String name, lua_CFunction function)
		{
			lua_register(LuaRuntime::Create()->Stack, name.c_str(), function);
		}

		void LuaRuntime::ExecuteFunction(String name, float value)
		{
			unsigned error;

			lua_getglobal(LuaRuntime::Create()->Stack, name.c_str());
			if(lua_isfunction(LuaRuntime::g_pInstance->Stack, -1))
			{
				lua_pushnumber(LuaRuntime::g_pInstance->Stack, value);
				if((error = lua_pcall(LuaRuntime::g_pInstance->Stack, 1, 0, 0)) != 0)
				{
					LuaRuntime::Dump();
					throw SingularityException(lua_tostring(LuaRuntime::g_pInstance->Stack, -1), error);
				}
			}
		}

		void LuaRuntime::Dump()
		{
			int i;
			int top = lua_gettop(LuaRuntime::Create()->Stack);

			printf("total in stack %d\n",top);

			for (i = 1; i <= top; i++)
			{  /* repeat for each level */
				int t = lua_type(LuaRuntime::g_pInstance->Stack, i);
				switch (t) {
					case LUA_TSTRING:  /* strings */
						printf("string: '%s'\n", lua_tostring(LuaRuntime::g_pInstance->Stack, i));
						break;
					case LUA_TBOOLEAN:  /* booleans */
						printf("boolean %s\n",lua_toboolean(LuaRuntime::g_pInstance->Stack, i) ? "true" : "false");
						break;
					case LUA_TNUMBER:  /* numbers */
						printf("number: %g\n", lua_tonumber(LuaRuntime::g_pInstance->Stack, i));
						break;
					default:  /* other values */
						printf("%s\n", lua_typename(LuaRuntime::g_pInstance->Stack, t));
						break;
				}
				printf("  ");  /* put a separator */
			}
			printf("\n");  /* end the listing */
		}

		LuaRuntime* LuaRuntime::Create()
		{
			if(LuaRuntime::g_pInstance == NULL)
				LuaRuntime::g_pInstance = new LuaRuntime();
			return LuaRuntime::g_pInstance;
		}
		#pragma endregion
	}
}