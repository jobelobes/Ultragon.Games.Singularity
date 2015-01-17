static int tolua_Singularity_scripting_Singularity_Scripting_LuaDelegate_new00(lua_State* tolua_S)
{
	unsigned objRef;
	unsigned funcRef;
	tolua_Error tolua_err;
	Singularity::Scripting::LuaDelegate* tolua_ret;

	if(!tolua_isusertable(tolua_S,1,"Singularity::Scripting::LuaDelegate",0,&tolua_err) || !tolua_isnoobj(tolua_S,4,&tolua_err) || !lua_isfunction(tolua_S,3))
		goto tolua_lerror;

	objRef = lua_ref(tolua_S, 2);	
	funcRef = lua_ref(tolua_S, 3);

	tolua_ret = (Singularity::Scripting::LuaDelegate*) Mtolua_new((Singularity::Scripting::LuaDelegate)(objRef, funcRef));
	tolua_pushusertype(tolua_S, (void*)tolua_ret, "Singularity::Scripting::LuaDelegate");
	return 1;

	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
	return 0;
};