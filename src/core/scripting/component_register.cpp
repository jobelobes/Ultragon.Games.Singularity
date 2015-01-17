#pragma once

#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "scripting\Singularity.Scripting.h"

void lua_pushcomponent(lua_State* state, Component* obj)
{

}

Component* lua_tocomponent(lua_State* state, int n)
{
	return NULL;
}

int component_getgameobject(lua_State* state)
{
	return 1;
}

int component_getname(lua_State* state)
{

	return 1;
}

int component_getenabled(lua_State* state)
{

	return 1;
}

int component_setenabled(lua_State* state)
{

	return 0;
}

static const luaL_reg input_methods[] = {
	{"Get_GameObject", component_getgameobject},
	{"Get_Name", component_getname},
	{"Get_Enabled", component_getenabled},
	{"Set_Enabled", component_setenabled},
	{0,0}
};

void component_register(lua_State* state)
{



}