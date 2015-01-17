#include "components\scripting\Singularity.Components.Scripting.h"

namespace Singularity
{
	namespace Components
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
					static int lua_GetGameObject(lua_State* l);
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