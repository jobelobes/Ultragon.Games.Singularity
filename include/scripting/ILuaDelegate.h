#include "scripting\Singularity.Scripting.h"

namespace Singularity
{
	namespace Scripting
	{
		class ILuaDelegate
		{
			public:
				#pragma region Methods
				virtual void InternalInvoke(lua_State* state) = 0;
				#pragma endregion

				friend class LuaTask;
		};
	}
}