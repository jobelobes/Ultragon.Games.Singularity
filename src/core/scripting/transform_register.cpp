#pragma once

#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "scripting\Singularity.Scripting.h"

void lua_pushtransform(lua_State* state, Component* obj)
{
	
}

Transform* lua_totransform(lua_State* state, int n)
{
	return NULL;
}

int transform_translate(lua_State* state)
{
	return 0;
}

int transform_lookat(lua_State* state)
{
	return 0;
}

static const luaL_reg transform_methods[] = {
	{"Translate", transform_translate},
	{"LookAt", transform_lookat},
	{0,0}
};

void transform_register(lua_State* state)
{



}