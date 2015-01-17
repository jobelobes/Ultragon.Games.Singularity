#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		enum KeyState { Up = 0x00000000, Down = 0x00000080, Pressed = 0x00000081, Released = 0x00000001 };

		class InputBuffer
		{
			public:
				#pragma region Variables
				unsigned char	KeyStates[256];
				bool			MouseDown[4];
				bool			KeyDown[256];
				#pragma endregion

				#pragma region Constructors and Finalizers
				InputBuffer()
				{
					ZeroMemory(&KeyStates, sizeof(unsigned char) * 256);
				}
				#pragma endregion	
		};
	}
}