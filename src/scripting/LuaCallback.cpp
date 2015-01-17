#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		LuaCallback::LuaCallback(int idx, String func)
		{
			m_iAliasIndex = idx;
			m_sFunctionName = func;
		}		

		bool LuaCallback::Call(void* sender, String senderType, String msg)
		{
			lua_State* state = LuaRuntime::Create()->Stack;

			lua_getglobal(state, "Memory");
			if(lua_istable(state,-1))
			{			
				lua_getfield(state, -1, "Aliases");

				if(lua_istable(state, -1))
				{
					lua_Integer alias = m_iAliasIndex;
					lua_pushinteger(state, alias);
					lua_gettable(state, -2);
					if(lua_istable(state, -1) || lua_isuserdata(state, -1))
					{
						lua_getfield(state, -1, m_sFunctionName.c_str());
						if(lua_isfunction(state,-1))
						{
							//put self on stack
							lua_pushvalue(state, -2);
							//put sender on stack
							tolua_pushusertype(state, sender, senderType.c_str());
							lua_pushstring(state, msg.c_str());
							lua_call(state,3,1);

							return lua_toboolean(state,-1);
						}
						else
						{
							printf("Callback Failure: Object doesn't have function \"%s\"",m_sFunctionName.c_str());
						}
					}
					else
					{
						printf("Callback Failure: Index %d doesn't exist in Alias Table.", m_iAliasIndex);
					}
				}
				else
				{
					printf("Callback Failure: Aliases Table doesn't exist.");
				}
			}
			else
			{
				printf("Callback Failure: Memory Table doesn't exist.");
			}

			return false
;
		}

		void LuaCallback::SetAliasIndex(int idx)
		{
			m_iAliasIndex = idx;
		}

		void LuaCallback::SetFunctionName(String func)
		{
			m_sFunctionName = func;
		}
	}
}