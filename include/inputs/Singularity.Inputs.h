#pragma once

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "XInput.lib")

#include <dinput.h>
#include <XInput.h>

// just to make the compiling go down easier
namespace Singularity 
{	
	namespace Inputs
	{
		class MouseState;
		class KeyboardState;

		class Input;
		class InputBuffer;
		class InputTask;
	}
}
#include "inputs\Singularity.Inputs.Defines.h"

#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "graphics\Singularity.Graphics.h"

#include "inputs\MouseState.h"
#include "inputs\KeyboardState.h"

#include "inputs\InputTask.h"
#include "inputs\Input.h"

