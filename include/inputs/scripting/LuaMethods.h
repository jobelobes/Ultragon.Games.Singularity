#include "inputs\scripting\Singularity.Inputs.Scripting.h"

namespace Singularity
{
	namespace Inputs
	{
		namespace Scripting
		{
			class LuaMethods
			{
				private:
					#pragma region Static Variables
					static LuaMethods* g_iInstance;
					#pragma endregion

					#pragma region Static Methods
					static int lua_GetMousePosition(lua_State* l);
					static int lua_GetKey(lua_State* l);
					#pragma endregion

					#pragma region Constructors and Finalizers
					LuaMethods() { };
					~LuaMethods() { };
					#pragma endregion

				public:
					#pragma region Static Methods
					static LuaMethods* Register();
					#pragma endregion
			};
		}
	}
}