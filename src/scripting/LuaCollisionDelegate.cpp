#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Physics;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaCollisionDelegate, Singularity::Physics::CollisionDelegate);

		#pragma region Constructors and Finalizers
		LuaCollisionDelegate::LuaCollisionDelegate(unsigned luaFuncRef) 
			: CollisionDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
		}

		LuaCollisionDelegate::~LuaCollisionDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaCollisionDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
			tolua_pushusertype(state, this->m_pCollider, "Singularity::Physics::Collider");
			tolua_pushusertype(state, this->m_pTarget, "Singularity::Physics::Collider");

			if(lua_pcall(state, 2, 0, 0) != 0)
				printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));

			this->m_pInvoked = false;
		}

		void LuaCollisionDelegate::Invoke(Collider* collider, Collider* target)
		{
			this->m_pInvoked = true;
			this->m_pTarget = target;
			this->m_pCollider = collider;
		}
		#pragma endregion
	}
}