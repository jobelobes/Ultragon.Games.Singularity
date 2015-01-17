#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaNetworkDelegate : public Singularity::Networking::NetworkDelegate, public Singularity::Scripting::ILuaDelegate
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				unsigned							m_pLuaFuncRef;
				bool								m_pInvoked;
				DynamicList<String>*				m_pData;
				CriticalSection						m_kLock;
				#pragma endregion

				#pragma region Methods
				void InternalInvoke(lua_State* state);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				LuaNetworkDelegate(unsigned luaFuncRef);
				~LuaNetworkDelegate();
				#pragma endregion

				#pragma region Methods
				void Invoke(Singularity::Networking::Packet* packet);
				#pragma endregion

				friend class LuaTask;
		};
	}
}