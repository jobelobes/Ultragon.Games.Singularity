#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaListBoxDelegate : public Singularity::Gui::ListBoxDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned							m_pLuaFuncRef;
				Singularity::Gui::ListBox*			m_pListbox;
				Singularity::Gui::ListBoxElement*	m_pListboxElement;
				bool								m_pInvoked;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaListBoxDelegate(unsigned luaFuncRef);
				~LuaListBoxDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Gui::ListBox* listbox, Singularity::Gui::ListBoxElement* element);
				#pragma endregion

				friend class LuaTask;
		};
	}
}