#include "scripting\Singularity.Scripting.h"

using namespace Singularity::Gui;

namespace Singularity
{
	namespace Scripting
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Scripting, LuaListBoxDelegate, Singularity::Gui::ListBoxDelegate);

		#pragma region Constructors and Finalizers
		LuaListBoxDelegate::LuaListBoxDelegate(unsigned luaFuncRef) 
			: ListBoxDelegate(NULL), m_pLuaFuncRef(luaFuncRef), m_pInvoked(false)
		{
			LuaTask::Instantiate()->RegisterDelegate(this);
		}

		LuaListBoxDelegate::~LuaListBoxDelegate()
		{
			LuaTask::Instantiate()->UnregisterDelegate(this);
		}
		#pragma endregion

		#pragma region Methods
		void LuaListBoxDelegate::InternalInvoke(lua_State* state)
		{
			if(!this->m_pInvoked)
				return;

			lua_rawgeti(state, LUA_REGISTRYINDEX, this->m_pLuaFuncRef);
			tolua_pushusertype(state, this->m_pListbox, "Singularity::Gui::ListBox");
			tolua_pushusertype(state, this->m_pListboxElement, "Singularity::Gui::ListBoxElement");

			if(lua_pcall(state, 2, 0, 0) != 0)
				printf("Failed to call delegate callback: %s\n", lua_tostring(state, -1));

			this->m_pInvoked = false;
		}

		void LuaListBoxDelegate::Invoke(ListBox* listbox, ListBoxElement* element)
		{
			this->m_pInvoked = true;
			this->m_pListbox = listbox;
			this->m_pListboxElement = element;
		}
		#pragma endregion
	}
}