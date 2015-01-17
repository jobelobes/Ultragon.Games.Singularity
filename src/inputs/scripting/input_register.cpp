#pragma once

#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "scripting\Singularity.Scripting.h"
#include "inputs\Singularity.Inputs.h"

int input_getmouseposition(lua_State* state)
{
	Vector2 pos = Singularity::Inputs::Input::GetMousePosition();
	lua_pushnumber(state, pos.x);
	lua_pushnumber(state, pos.y);
	return 2;
}

int input_getkey(lua_State* state)
{
	int key = luaL_optint(state, 1, 0);
	lua_pushboolean(state, Singularity::Inputs::Input::GetKey(key));
	return 1;
}

static const luaL_reg input_methods[] = {
	{"GetMousePosition", input_getmouseposition},
	{"GetKey", input_getkey},
	{0,0}
};

void input_register(lua_State* state)
{



}