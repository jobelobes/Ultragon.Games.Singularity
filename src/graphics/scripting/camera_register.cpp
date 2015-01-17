#pragma once

#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "scripting\Singularity.Scripting.h"
#include "graphics\Singularity.Graphics.h"

int camera_create(lua_State* state)
{
	return 1;
}

int camera_getbackgroundcolor(lua_State* state)
{
	return 1;
}

int camera_setbackgroundcolor(lua_State* state)
{
	return 1;
}

static const luaL_reg camera_methods[] = {
	{"Camera:Create", camera_create},
	{"Get_BackgroundColor", camera_getbackgroundcolor},
	{"Set_BackgroundColor", camera_setbackgroundcolor},
	{0,0}
};

void camera_register(lua_State* state)
{



}