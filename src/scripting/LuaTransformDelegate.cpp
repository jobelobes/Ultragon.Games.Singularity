#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaTransformDelegate, Singularity::Components::TransformDelegate);

		#pragma region Constructors and Finalizers
		LuaTransformDelegate::LuaTransformDelegate(unsigned luaFuncRef) 
			: TransformDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
		}

		LuaTransformDelegate::~LuaTransformDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaTransformDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
			tolua_pushusertype(state, this->m_pTransform, "Singularity::Components::Transform");

			if(lua_pcall(state, 1, 0, 0) != 0)
				printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));

			this->m_pInvoked = false;
		}

		void LuaTransformDelegate::Invoke(Transform* transform)
		{
			this->m_pInvoked = true;
			this->m_pTransform = transform;
		}
		#pragma endregion
	}
}