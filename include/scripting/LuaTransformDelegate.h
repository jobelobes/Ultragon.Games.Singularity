#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaTransformDelegate : public Singularity::Components::TransformDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned							m_pLuaFuncRef;
				Singularity::Components::Transform*	m_pTransform;
				bool								m_pInvoked;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaTransformDelegate(unsigned luaFuncRef);
				~LuaTransformDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Components::Transform* transform);
				#pragma endregion

				friend class LuaTask;
		};
	}
}