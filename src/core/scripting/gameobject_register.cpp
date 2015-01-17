#pragma once

#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "scripting\Singularity.Scripting.h"

void lua_pushgameobject(lua_State* state, GameObject* obj)
{

}

GameObject* lua_togameobject(lua_State* state, int n)
{
	return NULL;
}

int gameobject_create(lua_State* state)
{

	return 1;
}

int gameobject_getname(lua_State* state)
{

	return 1;
}

int gameobject_getactive(lua_State* state)
{

	return 1;
}

int gameobject_setactive(lua_State* state)
{

	return 0;
}

int gameobject_getroot(lua_State* state)
{

	return 1;
}

int gameobject_getparent(lua_State* state)
{

	return 1;
}

int gameobject_gettransform(lua_State* state)
{
	return 1;
}

int gameobject_attachchild(lua_State* state)
{

	return 0;
}

int gameobject_detachchild(lua_State* state)
{

	return 0;
}

int gameobject_detachchildren(lua_State* state)
{

	return 0;
}

int gameobject_getcomponent(lua_State* state)
{

	return 1;
}

int gameobject_addcomponent(lua_State* state)
{

	return 0;
}

int gameobject_removecomponent(lua_State* state)
{

	return 0;
}

static const luaL_reg input_methods[] = {
	{"GameObject:Create", gameobject_create},
	{"Get_Name", gameobject_getname},
	{"Get_Active", gameobject_getactive},
	{"Set_Active", gameobject_setactive},
	{"Get_Root", gameobject_getroot},
	{"Get_Parent", gameobject_getparent},
	{"Get_Transform", gameobject_gettransform},
	{"AttachChild", gameobject_attachchild},
	{"DetachChild", gameobject_detachchild},
	{"DetachChildren", gameobject_detachchildren},
	{"GetComponent", gameobject_getcomponent},
	{"AddComponent", gameobject_addcomponent},
	{"RemoveComponent", gameobject_removecomponent},
	{0,0}
};

void component_register(lua_State* state)
{



} 