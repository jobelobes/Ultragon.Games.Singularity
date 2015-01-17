#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaCollisionDelegate : public Singularity::Physics::CollisionDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned						m_pLuaFuncRef;
				Singularity::Physics::Collider*	m_pCollider, *m_pTarget;
				bool							m_pInvoked;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaCollisionDelegate(unsigned luaFuncRef);
				~LuaCollisionDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Physics::Collider* collider, Singularity::Physics::Collider* target);
				#pragma endregion

				friend class LuaTask;
		};
	}
}