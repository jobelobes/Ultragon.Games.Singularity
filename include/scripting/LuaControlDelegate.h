#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaControlDelegate : public Singularity::Gui::ControlDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned					m_pLuaFuncRef;
				Singularity::Gui::Control*	m_pControl;
				bool						m_pInvoked;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaControlDelegate(unsigned luaFuncRef);
				~LuaControlDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Gui::Control* control);
				#pragma endregion

				friend class LuaTask;
		};
	}
}