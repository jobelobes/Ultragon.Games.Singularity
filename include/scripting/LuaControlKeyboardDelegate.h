#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaControlKeyboardDelegate : public Singularity::Gui::ControlKeyboardDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned					m_pLuaFuncRef;
				Singularity::Gui::Control*	m_pControl;
				bool						m_bShift;
				bool						m_bControl;
				int							m_iKeyindex;
				bool						m_pInvoked;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaControlKeyboardDelegate(unsigned luaFuncRef);
				~LuaControlKeyboardDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Gui::Control* control, bool isShift, bool isControl, int keyIndex);
				#pragma endregion

				friend class LuaTask;
		};
	}
}