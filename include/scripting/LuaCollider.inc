static int tolua_Singularity_scripting_Singularity_Physics_Collider_SphereCast00(lua_State* tolua_S)
{
	Vector3 centerpoint = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
	float radius = ((float)  tolua_tonumber(tolua_S,3,0));
	int count = ((int)  tolua_tonumber(tolua_S,4,0));
	{
		DynamicList<Singularity::Physics::Collider*> colliders = Singularity::Physics::Collider::SphereCast(centerpoint,radius,count);
		
		lua_newtable(tolua_S);
		int top = lua_gettop(tolua_S);

		for (int i = 0; i < count; ++i)
		{
			tolua_pushnumber(tolua_S, i);
			tolua_pushusertype(tolua_S, colliders[i], "Singularity::Physics::Collider");
			lua_settable(tolua_S, top);
		}

		tolua_pushnumber(tolua_S,(lua_Number)count);
	}
	return 2;
}