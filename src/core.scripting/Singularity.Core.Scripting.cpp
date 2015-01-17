/*
** Lua binding: Singularity_Core
** Generated automatically by tolua++-1.0.92 on 04/19/10 13:20:14.
*/

#include "Core.Scripting\Singularity.Core.Scripting.h"


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Singularity__Bounds (lua_State* tolua_S)
{
 Singularity::Bounds* self = (Singularity::Bounds*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Singularity__Components__Scene (lua_State* tolua_S)
{
 Singularity::Components::Scene* self = (Singularity::Components::Scene*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Singularity__Graphics__CAMERA_DESC (lua_State* tolua_S)
{
 Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Singularity__Graphics__Camera (lua_State* tolua_S)
{
 Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_String (lua_State* tolua_S)
{
 String* self = (String*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Singularity__Components__GameObject (lua_State* tolua_S)
{
 Singularity::Components::GameObject* self = (Singularity::Components::GameObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Matrix (lua_State* tolua_S)
{
 Matrix* self = (Matrix*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"String");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Singularity::Components::Scene");
 tolua_usertype(tolua_S,"DynamicList<Singularity::Components::GameObject*>");
 tolua_usertype(tolua_S,"Singularity::ObjectType");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"DrawingContext");
 tolua_usertype(tolua_S,"Matrix");
 tolua_usertype(tolua_S,"Singularity::Components::Component");
 tolua_usertype(tolua_S,"Singularity::Bounds");
 tolua_usertype(tolua_S,"Singularity::Graphics::CAMERA_DESC");
 tolua_usertype(tolua_S,"Singularity::Components::GameObject");
 tolua_usertype(tolua_S,"Singularity::Object");
 tolua_usertype(tolua_S,"DynamicList<Singularity::Components::Component*>");
 tolua_usertype(tolua_S,"Singularity::Graphics::Camera");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"namespace");
 tolua_usertype(tolua_S,"Singularity::Components::Transform");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Singularity::Threading::CriticalSection");
}

/* get function: Empty of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Bounds_Empty
static int tolua_get_Singularity__Bounds_Empty(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Singularity::Bounds::Empty,"const Singularity::Bounds");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Center of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Bounds_Center
static int tolua_get_Singularity__Bounds_Center(lua_State* tolua_S)
{
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Center'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Center,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Center of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Bounds_Center
static int tolua_set_Singularity__Bounds_Center(lua_State* tolua_S)
{
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Center'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Center = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Size of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Bounds_Size
static int tolua_get_Singularity__Bounds_Size(lua_State* tolua_S)
{
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Size,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Size of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Bounds_Size
static int tolua_set_Singularity__Bounds_Size(lua_State* tolua_S)
{
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Size = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Min of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_Get_Min00
static int tolua_Singularity_Core_Singularity_Bounds_Get_Min00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Bounds",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Bounds* self = (const Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Min'", NULL);
#endif
  {
   const Vector3 tolua_ret = (const Vector3)  self->Get_Min();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"const Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Min'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Max of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_Get_Max00
static int tolua_Singularity_Core_Singularity_Bounds_Get_Max00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Bounds",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Bounds* self = (const Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Max'", NULL);
#endif
  {
   const Vector3 tolua_ret = (const Vector3)  self->Get_Max();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"const Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Max'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_new00
static int tolua_Singularity_Core_Singularity_Bounds_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float cx = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float cy = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float cz = ((const float)  tolua_tonumber(tolua_S,4,0));
  const float sx = ((const float)  tolua_tonumber(tolua_S,5,0));
  const float sy = ((const float)  tolua_tonumber(tolua_S,6,0));
  const float sz = ((const float)  tolua_tonumber(tolua_S,7,0));
  {
   Singularity::Bounds* tolua_ret = (Singularity::Bounds*)  Mtolua_new((Singularity::Bounds)(cx,cy,cz,sx,sy,sz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Bounds");
   tolua_pushnumber(tolua_S,(lua_Number)cx);
   tolua_pushnumber(tolua_S,(lua_Number)cy);
   tolua_pushnumber(tolua_S,(lua_Number)cz);
   tolua_pushnumber(tolua_S,(lua_Number)sx);
   tolua_pushnumber(tolua_S,(lua_Number)sy);
   tolua_pushnumber(tolua_S,(lua_Number)sz);
  }
 }
 return 7;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_new00_local
static int tolua_Singularity_Core_Singularity_Bounds_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float cx = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float cy = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float cz = ((const float)  tolua_tonumber(tolua_S,4,0));
  const float sx = ((const float)  tolua_tonumber(tolua_S,5,0));
  const float sy = ((const float)  tolua_tonumber(tolua_S,6,0));
  const float sz = ((const float)  tolua_tonumber(tolua_S,7,0));
  {
   Singularity::Bounds* tolua_ret = (Singularity::Bounds*)  Mtolua_new((Singularity::Bounds)(cx,cy,cz,sx,sy,sz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Bounds");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
   tolua_pushnumber(tolua_S,(lua_Number)cx);
   tolua_pushnumber(tolua_S,(lua_Number)cy);
   tolua_pushnumber(tolua_S,(lua_Number)cz);
   tolua_pushnumber(tolua_S,(lua_Number)sx);
   tolua_pushnumber(tolua_S,(lua_Number)sy);
   tolua_pushnumber(tolua_S,(lua_Number)sz);
  }
 }
 return 7;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_new01
static int tolua_Singularity_Core_Singularity_Bounds_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* size = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Singularity::Bounds* tolua_ret = (Singularity::Bounds*)  Mtolua_new((Singularity::Bounds)(*center,*size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Bounds");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Bounds_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_new01_local
static int tolua_Singularity_Core_Singularity_Bounds_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* size = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Singularity::Bounds* tolua_ret = (Singularity::Bounds*)  Mtolua_new((Singularity::Bounds)(*center,*size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Bounds");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Bounds_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_delete00
static int tolua_Singularity_Core_Singularity_Bounds_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinMax of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_SetMinMax00
static int tolua_Singularity_Core_Singularity_Bounds_SetMinMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* min = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* max = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinMax'", NULL);
#endif
  {
   self->SetMinMax(*min,*max);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Encapsulate of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_Encapsulate00
static int tolua_Singularity_Core_Singularity_Bounds_Encapsulate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Encapsulate'", NULL);
#endif
  {
   self->Encapsulate(*point);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Encapsulate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Expand of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_Expand00
static int tolua_Singularity_Core_Singularity_Bounds_Expand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
  const float amount = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Expand'", NULL);
#endif
  {
   self->Expand(amount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Expand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Expand of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_Expand01
static int tolua_Singularity_Core_Singularity_Bounds_Expand01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
  const Vector3 amount = *((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Expand'", NULL);
#endif
  {
   self->Expand(amount);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Bounds_Expand00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Contains of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_Contains00
static int tolua_Singularity_Core_Singularity_Bounds_Contains00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Bounds* self = (const Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Contains'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->Contains(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Contains'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SqrDistance of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds_SqrDistance00
static int tolua_Singularity_Core_Singularity_Bounds_SqrDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Bounds* self = (const Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SqrDistance'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->SqrDistance(*point);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SqrDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Singularity::Bounds */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Bounds__eq00
static int tolua_Singularity_Core_Singularity_Bounds__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Bounds",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Singularity::Bounds",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Bounds* self = (Singularity::Bounds*)  tolua_tousertype(tolua_S,1,0);
  const Singularity::Bounds* value = ((const Singularity::Bounds*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Name of class  Singularity::Components::Component */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Component_Get_Name00
static int tolua_Singularity_Core_Singularity_Components_Component_Get_Name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::Component* self = (const Singularity::Components::Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Name'", NULL);
#endif
  {
   String tolua_ret = (String)  self->Get_Name();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((String)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(String));
     tolua_pushusertype(tolua_S,tolua_obj,"String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_GameObject of class  Singularity::Components::Component */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Component_Get_GameObject00
static int tolua_Singularity_Core_Singularity_Components_Component_Get_GameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::Component* self = (const Singularity::Components::Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_GameObject'", NULL);
#endif
  {
   Singularity::Components::GameObject* tolua_ret = (Singularity::Components::GameObject*)  self->Get_GameObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_GameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Enabled of class  Singularity::Components::Component */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Component_Get_Enabled00
static int tolua_Singularity_Core_Singularity_Components_Component_Get_Enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::Component* self = (const Singularity::Components::Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Enabled'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->Get_Enabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Enabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Enabled of class  Singularity::Components::Component */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Component_Set_Enabled00
static int tolua_Singularity_Core_Singularity_Components_Component_Set_Enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Component",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Component* self = (Singularity::Components::Component*)  tolua_tousertype(tolua_S,1,0);
  const bool value = ((const bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Enabled'", NULL);
#endif
  {
   self->Set_Enabled(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Enabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Name of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Get_Name00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Get_Name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::GameObject* self = (const Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Name'", NULL);
#endif
  {
   const String tolua_ret = (const String)  self->Get_Name();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((String)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const String));
     tolua_pushusertype(tolua_S,tolua_obj,"const String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_IsActive of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Get_IsActive00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Get_IsActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::GameObject* self = (const Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_IsActive'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->Get_IsActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_IsActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_IsActive of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Set_IsActive00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Set_IsActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  const bool value = ((const bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_IsActive'", NULL);
#endif
  {
   self->Set_IsActive(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_IsActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Transform of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Get_Transform00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Get_Transform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Transform'", NULL);
#endif
  {
   Singularity::Components::Transform* tolua_ret = (Singularity::Components::Transform*)  self->Get_Transform();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::Transform");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Transform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Root of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Get_Root00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Get_Root00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Root'", NULL);
#endif
  {
   Singularity::Components::GameObject* tolua_ret = (Singularity::Components::GameObject*)  self->Get_Root();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Root'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Parent of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Get_Parent00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Get_Parent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::GameObject* self = (const Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Parent'", NULL);
#endif
  {
   Singularity::Components::GameObject* tolua_ret = (Singularity::Components::GameObject*)  self->Get_Parent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Parent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Parent of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Set_Parent00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Set_Parent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  Singularity::Components::GameObject* parent = ((Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Parent'", NULL);
#endif
  {
   self->Set_Parent(parent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Parent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_delete00
static int tolua_Singularity_Core_Singularity_Components_GameObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachChild of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_AttachChild00
static int tolua_Singularity_Core_Singularity_Components_GameObject_AttachChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  Singularity::Components::GameObject* node = ((Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AttachChild'", NULL);
#endif
  {
   self->AttachChild(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AttachChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DetachChild of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_DetachChild00
static int tolua_Singularity_Core_Singularity_Components_GameObject_DetachChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  Singularity::Components::GameObject* node = ((Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DetachChild'", NULL);
#endif
  {
   self->DetachChild(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DetachChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DetachChildren of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_DetachChildren00
static int tolua_Singularity_Core_Singularity_Components_GameObject_DetachChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DetachChildren'", NULL);
#endif
  {
   self->DetachChildren();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DetachChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_GetComponent00
static int tolua_Singularity_Core_Singularity_Components_GameObject_GetComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Singularity::ObjectType",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  const Singularity::ObjectType* type = ((const Singularity::ObjectType*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
  {
   Singularity::Components::Component* tolua_ret = (Singularity::Components::Component*)  self->GetComponent(*type);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::Component");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddComponent of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_AddComponent00
static int tolua_Singularity_Core_Singularity_Components_GameObject_AddComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Singularity::Components::Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  Singularity::Components::Component* component = ((Singularity::Components::Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddComponent'", NULL);
#endif
  {
   self->AddComponent(component);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponent of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_RemoveComponent00
static int tolua_Singularity_Core_Singularity_Components_GameObject_RemoveComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Singularity::Components::Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  Singularity::Components::Component* component = ((Singularity::Components::Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponent'", NULL);
#endif
  {
   self->RemoveComponent(component);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearComponents of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_ClearComponents00
static int tolua_Singularity_Core_Singularity_Components_GameObject_ClearComponents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearComponents'", NULL);
#endif
  {
   self->ClearComponents();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearComponents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Destroy00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroy'", NULL);
#endif
  {
   self->Destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Find of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Find00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Find00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::GameObject* self = (Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  String name = *((String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Find'", NULL);
#endif
  {
   Singularity::Components::GameObject* tolua_ret = (Singularity::Components::GameObject*)  self->Find(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Find'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsChildOf of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_IsChildOf00
static int tolua_Singularity_Core_Singularity_Components_GameObject_IsChildOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Singularity::Components::GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::GameObject* self = (const Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,1,0);
  const Singularity::Components::GameObject* parent = ((const Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsChildOf'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->IsChildOf(parent);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsChildOf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Create of class  Singularity::Components::GameObject */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_GameObject_Create00
static int tolua_Singularity_Core_Singularity_Components_GameObject_Create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Components::GameObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",1,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Singularity::Components::GameObject",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Singularity::Components::Scene",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,(void*)&(const String)NULL));
  Singularity::Components::GameObject* parent = ((Singularity::Components::GameObject*)  tolua_tousertype(tolua_S,3,NULL));
  Singularity::Components::Scene* scene = ((Singularity::Components::Scene*)  tolua_tousertype(tolua_S,4,NULL));
  {
   Singularity::Components::GameObject* tolua_ret = (Singularity::Components::GameObject*)  Singularity::Components::GameObject::Create(name,parent,scene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Position of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Get_Position00
static int tolua_Singularity_Core_Singularity_Components_Transform_Get_Position00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Position'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->Get_Position();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Position'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Position of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Set_Position00
static int tolua_Singularity_Core_Singularity_Components_Transform_Set_Position00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Position'", NULL);
#endif
  {
   self->Set_Position(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Position'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Rotation of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Get_Rotation00
static int tolua_Singularity_Core_Singularity_Components_Transform_Get_Rotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Rotation'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->Get_Rotation();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Rotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Rotation of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Set_Rotation00
static int tolua_Singularity_Core_Singularity_Components_Transform_Set_Rotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Rotation'", NULL);
#endif
  {
   self->Set_Rotation(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Rotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Scale of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Get_Scale00
static int tolua_Singularity_Core_Singularity_Components_Transform_Get_Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Scale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->Get_Scale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Scale of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Set_Scale00
static int tolua_Singularity_Core_Singularity_Components_Transform_Set_Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Scale'", NULL);
#endif
  {
   self->Set_Scale(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Scale of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Set_Scale01
static int tolua_Singularity_Core_Singularity_Components_Transform_Set_Scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Scale'", NULL);
#endif
  {
   self->Set_Scale(value);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_Set_Scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_LocalPosition of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalPosition00
static int tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_LocalPosition'", NULL);
#endif
  {
   Vector3& tolua_ret = (Vector3&)  self->Get_LocalPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_LocalPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_LocalPosition of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalPosition00
static int tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_LocalPosition'", NULL);
#endif
  {
   self->Set_LocalPosition(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_LocalPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_LocalRotation of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalRotation00
static int tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_LocalRotation'", NULL);
#endif
  {
   Quaternion& tolua_ret = (Quaternion&)  self->Get_LocalRotation();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Quaternion");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_LocalRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_LocalRotation of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalRotation00
static int tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_LocalRotation'", NULL);
#endif
  {
   self->Set_LocalRotation(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_LocalRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_LocalScale of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalScale00
static int tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_LocalScale'", NULL);
#endif
  {
   Vector3& tolua_ret = (Vector3&)  self->Get_LocalScale();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_LocalScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_LocalScale of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalScale00
static int tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_LocalScale'", NULL);
#endif
  {
   self->Set_LocalScale(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_LocalScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_LocalToWorldMatrix of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalToWorldMatrix00
static int tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalToWorldMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_LocalToWorldMatrix'", NULL);
#endif
  {
   Matrix tolua_ret = (Matrix)  self->Get_LocalToWorldMatrix();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_LocalToWorldMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_new00
static int tolua_Singularity_Core_Singularity_Components_Transform_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Singularity::Components::Transform* tolua_ret = (Singularity::Components::Transform*)  Mtolua_new((Singularity::Components::Transform)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::Transform");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_new00_local
static int tolua_Singularity_Core_Singularity_Components_Transform_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Singularity::Components::Transform* tolua_ret = (Singularity::Components::Transform*)  Mtolua_new((Singularity::Components::Transform)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Reset00
static int tolua_Singularity_Core_Singularity_Components_Transform_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reset'", NULL);
#endif
  {
   self->Reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Translate of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Translate00
static int tolua_Singularity_Core_Singularity_Components_Transform_Translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  Singularity::Components::Space space = ((Singularity::Components::Space) (int)  tolua_tonumber(tolua_S,3,Space::Self));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Translate'", NULL);
#endif
  {
   self->Translate(*value,space);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Translate of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Translate01
static int tolua_Singularity_Core_Singularity_Components_Transform_Translate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const float x = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float y = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float z = ((const float)  tolua_tonumber(tolua_S,4,0));
  Singularity::Components::Space space = ((Singularity::Components::Space) (int)  tolua_tonumber(tolua_S,5,Space::Self));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Translate'", NULL);
#endif
  {
   self->Translate(x,y,z,space);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_Translate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rotate of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Rotate00
static int tolua_Singularity_Core_Singularity_Components_Transform_Rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  Singularity::Components::Space space = ((Singularity::Components::Space) (int)  tolua_tonumber(tolua_S,3,Space::Self));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotate'", NULL);
#endif
  {
   self->Rotate(*value,space);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rotate of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Rotate01
static int tolua_Singularity_Core_Singularity_Components_Transform_Rotate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const float xAngle = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float yAngle = ((const float)  tolua_tonumber(tolua_S,3,0));
  float zAngle = ((float)  tolua_tonumber(tolua_S,4,0));
  Singularity::Components::Space space = ((Singularity::Components::Space) (int)  tolua_tonumber(tolua_S,5,Space::Self));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotate'", NULL);
#endif
  {
   self->Rotate(xAngle,yAngle,zAngle,space);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_Rotate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rotate of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_Rotate02
static int tolua_Singularity_Core_Singularity_Components_Transform_Rotate02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const float angle = ((const float)  tolua_tonumber(tolua_S,3,0));
  Singularity::Components::Space space = ((Singularity::Components::Space) (int)  tolua_tonumber(tolua_S,4,Space::Self));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotate'", NULL);
#endif
  {
   self->Rotate(*axis,angle,space);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_Rotate01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotateAround of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_RotateAround00
static int tolua_Singularity_Core_Singularity_Components_Transform_RotateAround00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const float angle = ((const float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RotateAround'", NULL);
#endif
  {
   self->RotateAround(*point,*axis,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotateAround'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotateAround of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_RotateAround01
static int tolua_Singularity_Core_Singularity_Components_Transform_RotateAround01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RotateAround'", NULL);
#endif
  {
   self->RotateAround(*point,*rotation);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_RotateAround00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_LookAt00
static int tolua_Singularity_Core_Singularity_Components_Transform_LookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
  {
   self->LookAt(*target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_LookAt01
static int tolua_Singularity_Core_Singularity_Components_Transform_LookAt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  Vector3 worldUp = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
  {
   self->LookAt(*target,worldUp);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_LookAt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_LookAt02
static int tolua_Singularity_Core_Singularity_Components_Transform_LookAt02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  Singularity::Components::Transform* target = ((Singularity::Components::Transform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
  {
   self->LookAt(target);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_LookAt01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_LookAt03
static int tolua_Singularity_Core_Singularity_Components_Transform_LookAt03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Components::Transform* self = (Singularity::Components::Transform*)  tolua_tousertype(tolua_S,1,0);
  Singularity::Components::Transform* target = ((Singularity::Components::Transform*)  tolua_tousertype(tolua_S,2,0));
  Vector3 worldUp = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
  {
   self->LookAt(target,worldUp);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Singularity_Core_Singularity_Components_Transform_LookAt02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotationToEuler of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_RotationToEuler00
static int tolua_Singularity_Core_Singularity_Components_Transform_RotationToEuler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion rotation = *((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector3 tolua_ret = (Vector3)  Singularity::Components::Transform::RotationToEuler(rotation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotationToEuler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AngleTo of class  Singularity::Components::Transform */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Transform_AngleTo00
static int tolua_Singularity_Core_Singularity_Components_Transform_AngleTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Components::Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3 from = *((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3 location = *((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector3 tolua_ret = (Vector3)  Singularity::Components::Transform::AngleTo(from,location);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AngleTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_IsActive of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Get_IsActive00
static int tolua_Singularity_Core_Singularity_Components_Scene_Get_IsActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Components::Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Components::Scene* self = (const Singularity::Components::Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_IsActive'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->Get_IsActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_IsActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_delete00
static int tolua_Singularity_Core_Singularity_Components_Scene_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Scene* self = (Singularity::Components::Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Activate of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Activate00
static int tolua_Singularity_Core_Singularity_Components_Scene_Activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Scene* self = (Singularity::Components::Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Activate'", NULL);
#endif
  {
   self->Activate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Activate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Deactivate of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Deactivate00
static int tolua_Singularity_Core_Singularity_Components_Scene_Deactivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Scene* self = (Singularity::Components::Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Deactivate'", NULL);
#endif
  {
   self->Deactivate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Deactivate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Clear00
static int tolua_Singularity_Core_Singularity_Components_Scene_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Scene* self = (Singularity::Components::Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Save of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Save00
static int tolua_Singularity_Core_Singularity_Components_Scene_Save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Scene* self = (Singularity::Components::Scene*)  tolua_tousertype(tolua_S,1,0);
  String path = *((String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Save'", NULL);
#endif
  {
   self->Save(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Open of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Open00
static int tolua_Singularity_Core_Singularity_Components_Scene_Open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Components::Scene* self = (Singularity::Components::Scene*)  tolua_tousertype(tolua_S,1,0);
  String path = *((String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Open'", NULL);
#endif
  {
   self->Open(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Open'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Create of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Create00
static int tolua_Singularity_Core_Singularity_Components_Scene_Create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int capacity = ((int)  tolua_tonumber(tolua_S,2,SINGULARITY_MAX_GAMEOBJECTS));
  bool active = ((bool)  tolua_toboolean(tolua_S,3,true));
  {
   Singularity::Components::Scene* tolua_ret = (Singularity::Components::Scene*)  Singularity::Components::Scene::Create(capacity,active);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Current of class  Singularity::Components::Scene */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Components_Scene_Get_Current00
static int tolua_Singularity_Core_Singularity_Components_Scene_Get_Current00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Components::Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Singularity::Components::Scene* tolua_ret = (Singularity::Components::Scene*)  Singularity::Components::Scene::Get_Current();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Components::Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Current'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Singularity */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Components
static int tolua_get_Singularity__Components(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Singularity,"namespace");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Singularity */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Components
static int tolua_set_Singularity__Components(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"namespace",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Singularity = *((using namespace*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Position of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__CAMERA_DESC_Position
static int tolua_get_Singularity__Graphics__CAMERA_DESC_Position(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Position,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Position of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__CAMERA_DESC_Position
static int tolua_set_Singularity__Graphics__CAMERA_DESC_Position(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Position = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Pad0 of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__CAMERA_DESC_Pad0
static int tolua_get_Singularity__Graphics__CAMERA_DESC_Pad0(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad0'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Pad0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Pad0 of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__CAMERA_DESC_Pad0
static int tolua_set_Singularity__Graphics__CAMERA_DESC_Pad0(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad0'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Pad0 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Resolution of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__CAMERA_DESC_Resolution
static int tolua_get_Singularity__Graphics__CAMERA_DESC_Resolution(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Resolution'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Resolution,"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Resolution of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__CAMERA_DESC_Resolution
static int tolua_set_Singularity__Graphics__CAMERA_DESC_Resolution(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Resolution'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Resolution = *((Vector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Pad1 of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__CAMERA_DESC_Pad1
static int tolua_get_Singularity__Graphics__CAMERA_DESC_Pad1(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Pad1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Pad1 of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__CAMERA_DESC_Pad1
static int tolua_set_Singularity__Graphics__CAMERA_DESC_Pad1(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Pad1 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Pad2 of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__CAMERA_DESC_Pad2
static int tolua_get_Singularity__Graphics__CAMERA_DESC_Pad2(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Pad2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Pad2 of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__CAMERA_DESC_Pad2
static int tolua_set_Singularity__Graphics__CAMERA_DESC_Pad2(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Pad2 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Projection of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__CAMERA_DESC_Projection
static int tolua_get_Singularity__Graphics__CAMERA_DESC_Projection(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Projection'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Projection,"Matrix");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Projection of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__CAMERA_DESC_Projection
static int tolua_set_Singularity__Graphics__CAMERA_DESC_Projection(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Projection'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Projection = *((Matrix*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: View of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__CAMERA_DESC_View
static int tolua_get_Singularity__Graphics__CAMERA_DESC_View(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'View'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->View,"Matrix");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: View of class  Singularity::Graphics::CAMERA_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__CAMERA_DESC_View
static int tolua_set_Singularity__Graphics__CAMERA_DESC_View(lua_State* tolua_S)
{
  Singularity::Graphics::CAMERA_DESC* self = (Singularity::Graphics::CAMERA_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'View'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->View = *((Matrix*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Orthographic of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Orthographic00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Orthographic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Orthographic'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->Get_Orthographic();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Orthographic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Orthographic of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Set_Orthographic00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Set_Orthographic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
  const bool value = ((const bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Orthographic'", NULL);
#endif
  {
   self->Set_Orthographic(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Orthographic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_BackgroundColor of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_BackgroundColor00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_BackgroundColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_BackgroundColor'", NULL);
#endif
  {
   const Color tolua_ret = (const Color)  self->Get_BackgroundColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const Color));
     tolua_pushusertype(tolua_S,tolua_obj,"const Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_BackgroundColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_BackgroundColor of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Set_BackgroundColor00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Set_BackgroundColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
  Color value = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_BackgroundColor'", NULL);
#endif
  {
   self->Set_BackgroundColor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_BackgroundColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_FieldOfView of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_FieldOfView00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_FieldOfView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_FieldOfView'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_FieldOfView();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_FieldOfView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_FieldOfView of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Set_FieldOfView00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Set_FieldOfView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_FieldOfView'", NULL);
#endif
  {
   self->Set_FieldOfView(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_FieldOfView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_NearClippingPlane of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_NearClippingPlane00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_NearClippingPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_NearClippingPlane'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_NearClippingPlane();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_NearClippingPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_NearClippingPlane of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Set_NearClippingPlane00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Set_NearClippingPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_NearClippingPlane'", NULL);
#endif
  {
   self->Set_NearClippingPlane(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_NearClippingPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_FarClippingPlane of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_FarClippingPlane00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_FarClippingPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_FarClippingPlane'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_FarClippingPlane();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_FarClippingPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_FarClippingPlane of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Set_FarClippingPlane00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Set_FarClippingPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_FarClippingPlane'", NULL);
#endif
  {
   self->Set_FarClippingPlane(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_FarClippingPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Aspect of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Aspect00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Aspect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Aspect'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_Aspect();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Aspect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Aspect of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Set_Aspect00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Set_Aspect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Aspect'", NULL);
#endif
  {
   self->Set_Aspect(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Aspect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Width of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Width00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Width'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_Width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Height of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Height00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Camera* self = (const Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Height'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_Height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Projection of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Projection00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Projection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Projection'", NULL);
#endif
  {
   Matrix tolua_ret = (Matrix)  self->Get_Projection();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Projection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_View of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_View00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_View00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_View'", NULL);
#endif
  {
   Matrix tolua_ret = (Matrix)  self->Get_View();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_View'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_new00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,(void*)&(const String)""));
  {
   Singularity::Graphics::Camera* tolua_ret = (Singularity::Graphics::Camera*)  Mtolua_new((Singularity::Graphics::Camera)(name));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_new00_local
static int tolua_Singularity_Core_Singularity_Graphics_Camera_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,(void*)&(const String)""));
  {
   Singularity::Graphics::Camera* tolua_ret = (Singularity::Graphics::Camera*)  Mtolua_new((Singularity::Graphics::Camera)(name));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Camera");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_delete00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Camera* self = (Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Current of class  Singularity::Graphics::Camera */
#ifndef TOLUA_DISABLE_tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Current00
static int tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Current00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Singularity::Graphics::Camera* tolua_ret = (Singularity::Graphics::Camera*)  Singularity::Graphics::Camera::Get_Current();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Current'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Singularity_Core_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Bounds","Singularity::Bounds","",tolua_collect_Singularity__Bounds);
   #else
   tolua_cclass(tolua_S,"Bounds","Singularity::Bounds","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Bounds");
    tolua_variable(tolua_S,"Empty",tolua_get_Singularity__Bounds_Empty,NULL);
    tolua_variable(tolua_S,"Center",tolua_get_Singularity__Bounds_Center,tolua_set_Singularity__Bounds_Center);
    tolua_variable(tolua_S,"Size",tolua_get_Singularity__Bounds_Size,tolua_set_Singularity__Bounds_Size);
    tolua_function(tolua_S,"Get_Min",tolua_Singularity_Core_Singularity_Bounds_Get_Min00);
    tolua_function(tolua_S,"Get_Max",tolua_Singularity_Core_Singularity_Bounds_Get_Max00);
    tolua_function(tolua_S,"new",tolua_Singularity_Core_Singularity_Bounds_new00);
    tolua_function(tolua_S,"new_local",tolua_Singularity_Core_Singularity_Bounds_new00_local);
    tolua_function(tolua_S,".call",tolua_Singularity_Core_Singularity_Bounds_new00_local);
    tolua_function(tolua_S,"new",tolua_Singularity_Core_Singularity_Bounds_new01);
    tolua_function(tolua_S,"new_local",tolua_Singularity_Core_Singularity_Bounds_new01_local);
    tolua_function(tolua_S,".call",tolua_Singularity_Core_Singularity_Bounds_new01_local);
    tolua_function(tolua_S,"delete",tolua_Singularity_Core_Singularity_Bounds_delete00);
    tolua_function(tolua_S,"SetMinMax",tolua_Singularity_Core_Singularity_Bounds_SetMinMax00);
    tolua_function(tolua_S,"Encapsulate",tolua_Singularity_Core_Singularity_Bounds_Encapsulate00);
    tolua_function(tolua_S,"Expand",tolua_Singularity_Core_Singularity_Bounds_Expand00);
    tolua_function(tolua_S,"Expand",tolua_Singularity_Core_Singularity_Bounds_Expand01);
    tolua_function(tolua_S,"Contains",tolua_Singularity_Core_Singularity_Bounds_Contains00);
    tolua_function(tolua_S,"SqrDistance",tolua_Singularity_Core_Singularity_Bounds_SqrDistance00);
    tolua_function(tolua_S,".eq",tolua_Singularity_Core_Singularity_Bounds__eq00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Components",0);
   tolua_beginmodule(tolua_S,"Components");
    tolua_cclass(tolua_S,"Component","Singularity::Components::Component","Singularity::Object",NULL);
    tolua_beginmodule(tolua_S,"Component");
     tolua_function(tolua_S,"Get_Name",tolua_Singularity_Core_Singularity_Components_Component_Get_Name00);
     tolua_function(tolua_S,"Get_GameObject",tolua_Singularity_Core_Singularity_Components_Component_Get_GameObject00);
     tolua_function(tolua_S,"Get_Enabled",tolua_Singularity_Core_Singularity_Components_Component_Get_Enabled00);
     tolua_function(tolua_S,"Set_Enabled",tolua_Singularity_Core_Singularity_Components_Component_Set_Enabled00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Components",0);
   tolua_beginmodule(tolua_S,"Components");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"GameObject","Singularity::Components::GameObject","Singularity::Object",tolua_collect_Singularity__Components__GameObject);
    #else
    tolua_cclass(tolua_S,"GameObject","Singularity::Components::GameObject","Singularity::Object",NULL);
    #endif
    tolua_beginmodule(tolua_S,"GameObject");
     tolua_function(tolua_S,"Get_Name",tolua_Singularity_Core_Singularity_Components_GameObject_Get_Name00);
     tolua_function(tolua_S,"Get_IsActive",tolua_Singularity_Core_Singularity_Components_GameObject_Get_IsActive00);
     tolua_function(tolua_S,"Set_IsActive",tolua_Singularity_Core_Singularity_Components_GameObject_Set_IsActive00);
     tolua_function(tolua_S,"Get_Transform",tolua_Singularity_Core_Singularity_Components_GameObject_Get_Transform00);
     tolua_function(tolua_S,"Get_Root",tolua_Singularity_Core_Singularity_Components_GameObject_Get_Root00);
     tolua_function(tolua_S,"Get_Parent",tolua_Singularity_Core_Singularity_Components_GameObject_Get_Parent00);
     tolua_function(tolua_S,"Set_Parent",tolua_Singularity_Core_Singularity_Components_GameObject_Set_Parent00);
     tolua_function(tolua_S,"delete",tolua_Singularity_Core_Singularity_Components_GameObject_delete00);
     tolua_function(tolua_S,"AttachChild",tolua_Singularity_Core_Singularity_Components_GameObject_AttachChild00);
     tolua_function(tolua_S,"DetachChild",tolua_Singularity_Core_Singularity_Components_GameObject_DetachChild00);
     tolua_function(tolua_S,"DetachChildren",tolua_Singularity_Core_Singularity_Components_GameObject_DetachChildren00);
     tolua_function(tolua_S,"GetComponent",tolua_Singularity_Core_Singularity_Components_GameObject_GetComponent00);
     tolua_function(tolua_S,"AddComponent",tolua_Singularity_Core_Singularity_Components_GameObject_AddComponent00);
     tolua_function(tolua_S,"RemoveComponent",tolua_Singularity_Core_Singularity_Components_GameObject_RemoveComponent00);
     tolua_function(tolua_S,"ClearComponents",tolua_Singularity_Core_Singularity_Components_GameObject_ClearComponents00);
     tolua_function(tolua_S,"Destroy",tolua_Singularity_Core_Singularity_Components_GameObject_Destroy00);
     tolua_function(tolua_S,"Find",tolua_Singularity_Core_Singularity_Components_GameObject_Find00);
     tolua_function(tolua_S,"IsChildOf",tolua_Singularity_Core_Singularity_Components_GameObject_IsChildOf00);
     tolua_function(tolua_S,"Create",tolua_Singularity_Core_Singularity_Components_GameObject_Create00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Components",0);
   tolua_beginmodule(tolua_S,"Components");
    tolua_constant(tolua_S,"Self",Singularity::Components::Self);
    tolua_constant(tolua_S,"World",Singularity::Components::World);
    tolua_cclass(tolua_S,"Transform","Singularity::Components::Transform","Singularity::Components::Component",NULL);
    tolua_beginmodule(tolua_S,"Transform");
     tolua_function(tolua_S,"Get_Position",tolua_Singularity_Core_Singularity_Components_Transform_Get_Position00);
     tolua_function(tolua_S,"Set_Position",tolua_Singularity_Core_Singularity_Components_Transform_Set_Position00);
     tolua_function(tolua_S,"Get_Rotation",tolua_Singularity_Core_Singularity_Components_Transform_Get_Rotation00);
     tolua_function(tolua_S,"Set_Rotation",tolua_Singularity_Core_Singularity_Components_Transform_Set_Rotation00);
     tolua_function(tolua_S,"Get_Scale",tolua_Singularity_Core_Singularity_Components_Transform_Get_Scale00);
     tolua_function(tolua_S,"Set_Scale",tolua_Singularity_Core_Singularity_Components_Transform_Set_Scale00);
     tolua_function(tolua_S,"Set_Scale",tolua_Singularity_Core_Singularity_Components_Transform_Set_Scale01);
     tolua_function(tolua_S,"Get_LocalPosition",tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalPosition00);
     tolua_function(tolua_S,"Set_LocalPosition",tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalPosition00);
     tolua_function(tolua_S,"Get_LocalRotation",tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalRotation00);
     tolua_function(tolua_S,"Set_LocalRotation",tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalRotation00);
     tolua_function(tolua_S,"Get_LocalScale",tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalScale00);
     tolua_function(tolua_S,"Set_LocalScale",tolua_Singularity_Core_Singularity_Components_Transform_Set_LocalScale00);
     tolua_function(tolua_S,"Get_LocalToWorldMatrix",tolua_Singularity_Core_Singularity_Components_Transform_Get_LocalToWorldMatrix00);
     tolua_function(tolua_S,"new",tolua_Singularity_Core_Singularity_Components_Transform_new00);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Core_Singularity_Components_Transform_new00_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Core_Singularity_Components_Transform_new00_local);
     tolua_function(tolua_S,"Reset",tolua_Singularity_Core_Singularity_Components_Transform_Reset00);
     tolua_function(tolua_S,"Translate",tolua_Singularity_Core_Singularity_Components_Transform_Translate00);
     tolua_function(tolua_S,"Translate",tolua_Singularity_Core_Singularity_Components_Transform_Translate01);
     tolua_function(tolua_S,"Rotate",tolua_Singularity_Core_Singularity_Components_Transform_Rotate00);
     tolua_function(tolua_S,"Rotate",tolua_Singularity_Core_Singularity_Components_Transform_Rotate01);
     tolua_function(tolua_S,"Rotate",tolua_Singularity_Core_Singularity_Components_Transform_Rotate02);
     tolua_function(tolua_S,"RotateAround",tolua_Singularity_Core_Singularity_Components_Transform_RotateAround00);
     tolua_function(tolua_S,"RotateAround",tolua_Singularity_Core_Singularity_Components_Transform_RotateAround01);
     tolua_function(tolua_S,"LookAt",tolua_Singularity_Core_Singularity_Components_Transform_LookAt00);
     tolua_function(tolua_S,"LookAt",tolua_Singularity_Core_Singularity_Components_Transform_LookAt01);
     tolua_function(tolua_S,"LookAt",tolua_Singularity_Core_Singularity_Components_Transform_LookAt02);
     tolua_function(tolua_S,"LookAt",tolua_Singularity_Core_Singularity_Components_Transform_LookAt03);
     tolua_function(tolua_S,"RotationToEuler",tolua_Singularity_Core_Singularity_Components_Transform_RotationToEuler00);
     tolua_function(tolua_S,"AngleTo",tolua_Singularity_Core_Singularity_Components_Transform_AngleTo00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Components",0);
   tolua_beginmodule(tolua_S,"Components");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"Scene","Singularity::Components::Scene","Singularity::Object",tolua_collect_Singularity__Components__Scene);
    #else
    tolua_cclass(tolua_S,"Scene","Singularity::Components::Scene","Singularity::Object",NULL);
    #endif
    tolua_beginmodule(tolua_S,"Scene");
     tolua_function(tolua_S,"Get_IsActive",tolua_Singularity_Core_Singularity_Components_Scene_Get_IsActive00);
     tolua_function(tolua_S,"delete",tolua_Singularity_Core_Singularity_Components_Scene_delete00);
     tolua_function(tolua_S,"Activate",tolua_Singularity_Core_Singularity_Components_Scene_Activate00);
     tolua_function(tolua_S,"Deactivate",tolua_Singularity_Core_Singularity_Components_Scene_Deactivate00);
     tolua_function(tolua_S,"Clear",tolua_Singularity_Core_Singularity_Components_Scene_Clear00);
     tolua_function(tolua_S,"Save",tolua_Singularity_Core_Singularity_Components_Scene_Save00);
     tolua_function(tolua_S,"Open",tolua_Singularity_Core_Singularity_Components_Scene_Open00);
     tolua_function(tolua_S,"Create",tolua_Singularity_Core_Singularity_Components_Scene_Create00);
     tolua_function(tolua_S,"Get_Current",tolua_Singularity_Core_Singularity_Components_Scene_Get_Current00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_variable(tolua_S,"Singularity__Components",tolua_get_Singularity__Components,tolua_set_Singularity__Components);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Graphics",0);
   tolua_beginmodule(tolua_S,"Graphics");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CAMERA_DESC","Singularity::Graphics::CAMERA_DESC","",tolua_collect_Singularity__Graphics__CAMERA_DESC);
    #else
    tolua_cclass(tolua_S,"CAMERA_DESC","Singularity::Graphics::CAMERA_DESC","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CAMERA_DESC");
     tolua_variable(tolua_S,"Position",tolua_get_Singularity__Graphics__CAMERA_DESC_Position,tolua_set_Singularity__Graphics__CAMERA_DESC_Position);
     tolua_variable(tolua_S,"Pad0",tolua_get_Singularity__Graphics__CAMERA_DESC_Pad0,tolua_set_Singularity__Graphics__CAMERA_DESC_Pad0);
     tolua_variable(tolua_S,"Resolution",tolua_get_Singularity__Graphics__CAMERA_DESC_Resolution,tolua_set_Singularity__Graphics__CAMERA_DESC_Resolution);
     tolua_variable(tolua_S,"Pad1",tolua_get_Singularity__Graphics__CAMERA_DESC_Pad1,tolua_set_Singularity__Graphics__CAMERA_DESC_Pad1);
     tolua_variable(tolua_S,"Pad2",tolua_get_Singularity__Graphics__CAMERA_DESC_Pad2,tolua_set_Singularity__Graphics__CAMERA_DESC_Pad2);
     tolua_variable(tolua_S,"Projection",tolua_get_Singularity__Graphics__CAMERA_DESC_Projection,tolua_set_Singularity__Graphics__CAMERA_DESC_Projection);
     tolua_variable(tolua_S,"View",tolua_get_Singularity__Graphics__CAMERA_DESC_View,tolua_set_Singularity__Graphics__CAMERA_DESC_View);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"Camera","Singularity::Graphics::Camera","Singularity::Components::Component",tolua_collect_Singularity__Graphics__Camera);
    #else
    tolua_cclass(tolua_S,"Camera","Singularity::Graphics::Camera","Singularity::Components::Component",NULL);
    #endif
    tolua_beginmodule(tolua_S,"Camera");
     tolua_function(tolua_S,"Get_Orthographic",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Orthographic00);
     tolua_function(tolua_S,"Set_Orthographic",tolua_Singularity_Core_Singularity_Graphics_Camera_Set_Orthographic00);
     tolua_function(tolua_S,"Get_BackgroundColor",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_BackgroundColor00);
     tolua_function(tolua_S,"Set_BackgroundColor",tolua_Singularity_Core_Singularity_Graphics_Camera_Set_BackgroundColor00);
     tolua_function(tolua_S,"Get_FieldOfView",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_FieldOfView00);
     tolua_function(tolua_S,"Set_FieldOfView",tolua_Singularity_Core_Singularity_Graphics_Camera_Set_FieldOfView00);
     tolua_function(tolua_S,"Get_NearClippingPlane",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_NearClippingPlane00);
     tolua_function(tolua_S,"Set_NearClippingPlane",tolua_Singularity_Core_Singularity_Graphics_Camera_Set_NearClippingPlane00);
     tolua_function(tolua_S,"Get_FarClippingPlane",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_FarClippingPlane00);
     tolua_function(tolua_S,"Set_FarClippingPlane",tolua_Singularity_Core_Singularity_Graphics_Camera_Set_FarClippingPlane00);
     tolua_function(tolua_S,"Get_Aspect",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Aspect00);
     tolua_function(tolua_S,"Set_Aspect",tolua_Singularity_Core_Singularity_Graphics_Camera_Set_Aspect00);
     tolua_function(tolua_S,"Get_Width",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Width00);
     tolua_function(tolua_S,"Get_Height",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Height00);
     tolua_function(tolua_S,"Get_Projection",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Projection00);
     tolua_function(tolua_S,"Get_View",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_View00);
     tolua_function(tolua_S,"new",tolua_Singularity_Core_Singularity_Graphics_Camera_new00);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Core_Singularity_Graphics_Camera_new00_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Core_Singularity_Graphics_Camera_new00_local);
     tolua_function(tolua_S,"delete",tolua_Singularity_Core_Singularity_Graphics_Camera_delete00);
     tolua_function(tolua_S,"Get_Current",tolua_Singularity_Core_Singularity_Graphics_Camera_Get_Current00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Singularity_Core (lua_State* tolua_S) {
 return tolua_Singularity_Core_open(tolua_S);
};
#endif

