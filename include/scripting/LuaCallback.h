#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class LuaCallback
		{
			private:
				int m_iAliasIndex;
				String m_sFunctionName;
			public:
				LuaCallback(int idx, String func);
				
				void SetAliasIndex(int idx);
				void SetFunctionName(String func);

				bool Call(void* sender, String senderType, String msg);
		};
	}
}