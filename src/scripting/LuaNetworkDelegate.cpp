#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Networking;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaNetworkDelegate, Singularity::Networking::NetworkDelegate);

		#pragma region Constructors and Finalizers
		LuaNetworkDelegate::LuaNetworkDelegate(unsigned luaFuncRef) 
			: NetworkDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
			m_pData = new DynamicList<String>();
		}

		LuaNetworkDelegate::~LuaNetworkDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaNetworkDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			Autolock(this->m_kLock)
			{
				for(unsigned i = 0; i < m_pData->size(); i++)
				{
					lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
					//tolua_pushusertype(state, this->m_pPacket, "Singularity::Networking::Packet");
					tolua_pushcppstring(state, this->m_pData->at(i));

					if(lua_pcall(state, 1, 0, 0) != 0)
						printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));
				}

				this->m_pInvoked = false;
				this->m_pData->clear();
			}
		}

		void LuaNetworkDelegate::Invoke(Packet* packet)
		{
			this->m_pInvoked = true;
			Autolock(this->m_kLock)
			{
				this->m_pData->push_back(String((char*)&packet->Data));
			}
		}
		#pragma endregion
	}
}