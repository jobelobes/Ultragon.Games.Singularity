#include "inputs\Singularity.Inputs.h"

namespace Singularity
{
	namespace Inputs
	{
		class Input
		{
			public:
				#pragma region Static Methods
				static MouseState GetMouseState();
				static KeyboardState GetKeyboardState();

				static void ResetMousePosition();
				static void SetMousePosition(int x, int y);
				static Vector2 GetMousePosition();
				static bool GetMouseButton(int button);

				static bool IsKeyDown(int key);
				static bool IsKeyUp(int key);
				#pragma endregion
		};
	}
}