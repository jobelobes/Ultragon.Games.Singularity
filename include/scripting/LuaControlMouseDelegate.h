#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaControlMouseDelegate : public Singularity::Gui::ControlMouseDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned					m_pLuaFuncRef;
				Singularity::Gui::Control*	m_pControl;
				Vector2						m_kPosition;
				bool						m_pInvoked;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaControlMouseDelegate(unsigned luaFuncRef);
				~LuaControlMouseDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Gui::Control* control, Vector2 position);
				#pragma endregion

				friend class LuaTask;
		};
	}
}