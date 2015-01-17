#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaBinder, Singularity::Components::Component);

		#pragma region Overriden Methods
		void LuaBinder::OnComponentAdded(GameObject* gameObject)
		{
			LuaTask::Instantiate()->RegisterComponent(this);
		}

		void LuaBinder::OnComponentRemoved(GameObject* gameObject)
		{
			LuaTask::Instantiate()->UnregisterComponent(this);
		}

		void LuaBinder::OnExecute(lua_State* state, float elapsedTime)
		{
			unsigned error;
			unsigned index;
			size_t found;
			String value, string;

			if(!this->m_bLoaded)
			{
				unsigned error;
				if(this->m_pPath.size() > 0)
				{
					if(luaL_loadfile(state, this->m_pPath.c_str()) != 0)
						throw SingularityException(lua_tostring(state, -1));

					if((error = lua_pcall(state, 0, 0, 0)) != 0)
						throw SingularityException(lua_tostring(state, -1));
				}

				if(this->m_pFunctionCallback.size() > 0)
				{
					index = LUA_GLOBALSINDEX;
					string = this->m_pFunctionCallback;
					found = 0;
					while(found != String.npos)
					{
						found = string.find(".");
						value = string.substr(0, found);
						
						lua_getfield(state, index, value.c_str());
						if (lua_isfunction(state, -1))
						{
							this->m_pFunctionIndex = lua_ref(state, -1);	
							break;
						}

						index = -1;
						if(found != String.npos)
							string = string.substr(found + 1);
					}
				}

				this->m_bLoaded = true;
			}

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pFunctionIndex);
			tolua_pushusertype(state,(void*)this,"Singularity::Scripting::LuaBinder");
			lua_pushnumber(state, elapsedTime);
			if((error = lua_pcall(state, 2, 0, 0)) != 0)
			{
				LuaRuntime::Dump();
				throw SingularityException(lua_tostring(state, -1), error);
			}			
		}
		#pragma endregion
	}
}