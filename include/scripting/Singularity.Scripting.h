#pragma once

#pragma comment(lib, "lua51.lib")

namespace Singularity
{
	namespace Scripting
	{
		class LuaBinder;
		class LuaTask;
		class LuaSubTask;
	}
}

#include "scripting\Singularity.Scripting.Defines.h"

extern "C" {
#include "3rdparty\lua\lua.h"
#include "3rdparty\lua\lauxlib.h"
#include "3rdparty\lua\lualib.h"
}

#include "lua\tolua++.h"

// extensions
#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "animations\Singularity.Animations.h"
#include "graphics\Singularity.Graphics.h"
#include "inputs\Singularity.Inputs.h"
#include "gui\Singularity.Gui.h"
#include "audio\Singularity.Audio.h"
#include "physics\Singularity.Physics.h"
#include "networking\Singularity.Networking.h"
#include "particles\Singularity.Particles.h"
#include "content\Singularity.Content.h"

#include "scripting\ILuaDelegate.h"
#include "scripting\LuaRuntime.h"
#include "scripting\LuaBehaviorDelegate.h"
#include "scripting\LuaTransformDelegate.h"
#include "scripting\LuaControlDelegate.h"
#include "scripting\LuaControlMouseDelegate.h"
#include "scripting\LuaControlKeyboardDelegate.h"
#include "scripting\LuaListBoxDelegate.h"
#include "scripting\LuaCollisionDelegate.h"
#include "scripting\LuaNetworkDelegate.h"
#include "scripting\LuaNetworkPacket.h"
#include "scripting\LuaBinder.h"

#include "scripting\LuaTask.h"
#include "scripting\LuaSubTask.h"

#include "scripting\ScriptingOverrides.inc"
#include "scripting\Scripting.Definitions.h"

