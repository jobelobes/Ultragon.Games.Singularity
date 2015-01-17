/*
** Lua binding: Singularity_Graphics
** Generated automatically by tolua++-1.0.92 on 04/19/10 13:03:06.
*/

#include "Graphics.Scripting\Singularity.Graphics.Scripting.h"


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Singularity__Graphics__MeshRenderer (lua_State* tolua_S)
{
 Singularity::Graphics::MeshRenderer* self = (Singularity::Graphics::MeshRenderer*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_Singularity__Graphics__Renderer (lua_State* tolua_S)
{
 Singularity::Graphics::Renderer* self = (Singularity::Graphics::Renderer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Bounds (lua_State* tolua_S)
{
 Bounds* self = (Bounds*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Singularity__Graphics__Light (lua_State* tolua_S)
{
 Singularity::Graphics::Light* self = (Singularity::Graphics::Light*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Matrix (lua_State* tolua_S)
{
 Matrix* self = (Matrix*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"String");
 tolua_usertype(tolua_S,"RenderCallback");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Singularity::Graphics::MeshRenderer");
 tolua_usertype(tolua_S,"Singularity::Graphics::LIGHT_DESC");
 tolua_usertype(tolua_S,"Material");
 tolua_usertype(tolua_S,"namespace");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"DrawingContext");
 tolua_usertype(tolua_S,"Matrix");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"Mesh");
 tolua_usertype(tolua_S,"Singularity::Graphics::Light");
 tolua_usertype(tolua_S,"Singularity::Graphics::Mesh");
 tolua_usertype(tolua_S,"Bounds");
 tolua_usertype(tolua_S,"Singularity::Graphics::CAMERA_DESC");
 tolua_usertype(tolua_S,"Singularity::Graphics::Camera");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Singularity::Components::Component");
 tolua_usertype(tolua_S,"DECLARE_OBJECT_TYPE");
 tolua_usertype(tolua_S,"Singularity::Graphics::Renderer");
 tolua_usertype(tolua_S,"GameObject");
}

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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Orthographic00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Orthographic00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_Orthographic00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_Orthographic00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_BackgroundColor00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_BackgroundColor00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_BackgroundColor00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_BackgroundColor00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_FieldOfView00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_FieldOfView00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_FieldOfView00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_FieldOfView00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_NearClippingPlane00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_NearClippingPlane00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_NearClippingPlane00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_NearClippingPlane00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_FarClippingPlane00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_FarClippingPlane00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_FarClippingPlane00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_FarClippingPlane00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Aspect00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Aspect00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_Aspect00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_Aspect00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Width00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Width00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Height00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Height00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Projection00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Projection00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_View00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_View00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_new00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_new00_local
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_delete00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_delete00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Current00
static int tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Current00(lua_State* tolua_S)
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

/* get function: Position of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Position
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Position(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Position,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Position of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Position
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Position(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Pad0 of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Pad0
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Pad0(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad0'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Pad0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Pad0 of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Pad0
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Pad0(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Direction of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Direction
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Direction(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Direction'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Direction,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Direction of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Direction
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Direction(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Direction'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Direction = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Pad1 of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Pad1
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Pad1(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pad1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Pad1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Pad1 of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Pad1
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Pad1(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Color of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Color
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Color(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Color,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Color of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Color
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Color(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Color = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Type of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Type
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Type(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Type of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Type
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Type(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Falloff of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Falloff
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Falloff(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Falloff'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Falloff);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Falloff of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Falloff
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Falloff(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Falloff'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Falloff = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Range of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Range
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Range(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Range'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Range);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Range of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Range
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Range(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Range'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Range = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Intensity of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_get_Singularity__Graphics__LIGHT_DESC_Intensity
static int tolua_get_Singularity__Graphics__LIGHT_DESC_Intensity(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Intensity'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Intensity);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Intensity of class  Singularity::Graphics::LIGHT_DESC */
#ifndef TOLUA_DISABLE_tolua_set_Singularity__Graphics__LIGHT_DESC_Intensity
static int tolua_set_Singularity__Graphics__LIGHT_DESC_Intensity(lua_State* tolua_S)
{
  Singularity::Graphics::LIGHT_DESC* self = (Singularity::Graphics::LIGHT_DESC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Intensity'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Intensity = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Type of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Type00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Type00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Light* self = (const Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Type'", NULL);
#endif
  {
   const Singularity::Graphics::LightType tolua_ret = (const Singularity::Graphics::LightType)  self->Get_Type();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Type'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Orthographic of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Orthographic00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Orthographic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Light* self = (Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
  const Singularity::Graphics::LightType value = ((const Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,2,0));
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

/* method: Get_Color of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Color00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Light* self = (const Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Color'", NULL);
#endif
  {
   const Color tolua_ret = (const Color)  self->Get_Color();
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
 tolua_error(tolua_S,"#ferror in function 'Get_Color'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Color of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Color00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Light* self = (Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
  Color value = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Color'", NULL);
#endif
  {
   self->Set_Color(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Color'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Falloff of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Falloff00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Falloff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Light* self = (const Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Falloff'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_Falloff();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Falloff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Falloff of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Falloff00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Falloff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Light* self = (Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Falloff'", NULL);
#endif
  {
   self->Set_Falloff(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Falloff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Range of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Range00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Range00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Light* self = (const Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Range'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_Range();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Range'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Range of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Range00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Range00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Light* self = (Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Range'", NULL);
#endif
  {
   self->Set_Range(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Range'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Intensity of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Intensity00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Intensity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Light* self = (const Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Intensity'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->Get_Intensity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Intensity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Intensity of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Intensity00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Intensity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Light* self = (Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
  const float value = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Intensity'", NULL);
#endif
  {
   self->Set_Intensity(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Intensity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,2,LightType::Point));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
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

/* method: new_local of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new00_local
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,2,LightType::Point));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
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

/* method: new of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new01
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,2,0));
  Color color = *((Color*)  tolua_tousertype(tolua_S,3,0));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(type,color));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_Light_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new01_local
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,2,0));
  Color color = *((Color*)  tolua_tousertype(tolua_S,3,0));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(type,color));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_Light_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new02
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,0));
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,3,LightType::Point));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(name,type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_Light_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new02_local
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,0));
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,3,LightType::Point));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(name,type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_Light_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new03
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,0));
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,3,0));
  Color color = *((Color*)  tolua_tousertype(tolua_S,4,0));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(name,type,color));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_Light_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_new03_local
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,0));
  Singularity::Graphics::LightType type = ((Singularity::Graphics::LightType) (int)  tolua_tonumber(tolua_S,3,0));
  Color color = *((Color*)  tolua_tousertype(tolua_S,4,0));
  {
   Singularity::Graphics::Light* tolua_ret = (Singularity::Graphics::Light*)  Mtolua_new((Singularity::Graphics::Light)(name,type,color));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::Light");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_Light_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Singularity::Graphics::Light */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Light_delete00
static int tolua_Singularity_Graphics_Singularity_Graphics_Light_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Light* self = (Singularity::Graphics::Light*)  tolua_tousertype(tolua_S,1,0);
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

/* function: Singularity::Graphics::(__fastcall *RenderCallback) */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_(__fastcall__RenderCallback)00
static int tolua_Singularity_Graphics_Singularity_Graphics_(__fastcall__RenderCallback)00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"DrawingContext",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Singularity::Graphics::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Renderer* sender = ((Singularity::Graphics::Renderer*)  tolua_tousertype(tolua_S,1,0));
  DrawingContext* context = ((DrawingContext*)  tolua_tousertype(tolua_S,2,0));
  Singularity::Graphics::Camera* camera = ((Singularity::Graphics::Camera*)  tolua_tousertype(tolua_S,3,0));
  {
   Singularity::Graphics::(__fastcall *RenderCallback)(sender,context,camera);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '(__fastcall__RenderCallback)'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_IsVisible of class  Singularity::Graphics::Renderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_IsVisible00
static int tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_IsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Renderer* self = (const Singularity::Graphics::Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_IsVisible'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->Get_IsVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_IsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Material of class  Singularity::Graphics::Renderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_Material00
static int tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_Material00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Renderer* self = (const Singularity::Graphics::Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Material'", NULL);
#endif
  {
   Material* tolua_ret = (Material*)  self->Get_Material();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Material");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Material'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Material of class  Singularity::Graphics::Renderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Set_Material00
static int tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Set_Material00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Renderer* self = (Singularity::Graphics::Renderer*)  tolua_tousertype(tolua_S,1,0);
  Material* value = ((Material*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Material'", NULL);
#endif
  {
   self->Set_Material(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Material'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Bounds of class  Singularity::Graphics::Renderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_Bounds00
static int tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_Bounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::Renderer* self = (const Singularity::Graphics::Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Bounds'", NULL);
#endif
  {
   const Bounds tolua_ret = (const Bounds)  self->Get_Bounds();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Bounds)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const Bounds");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const Bounds));
     tolua_pushusertype(tolua_S,tolua_obj,"const Bounds");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Bounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterCallback of class  Singularity::Graphics::Renderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_Renderer_RegisterCallback00
static int tolua_Singularity_Graphics_Singularity_Graphics_Renderer_RegisterCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::Renderer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"RenderCallback",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::Renderer* self = (Singularity::Graphics::Renderer*)  tolua_tousertype(tolua_S,1,0);
  RenderCallback value = *((RenderCallback*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterCallback'", NULL);
#endif
  {
   self->RegisterCallback(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Mesh",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Material",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mesh* mesh = ((Mesh*)  tolua_tousertype(tolua_S,2,NULL));
  Material* material = ((Material*)  tolua_tousertype(tolua_S,3,NULL));
  {
   Singularity::Graphics::MeshRenderer* tolua_ret = (Singularity::Graphics::MeshRenderer*)  Mtolua_new((Singularity::Graphics::MeshRenderer)(mesh,material));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::MeshRenderer");
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

/* method: new_local of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00_local
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Mesh",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Material",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mesh* mesh = ((Mesh*)  tolua_tousertype(tolua_S,2,NULL));
  Material* material = ((Material*)  tolua_tousertype(tolua_S,3,NULL));
  {
   Singularity::Graphics::MeshRenderer* tolua_ret = (Singularity::Graphics::MeshRenderer*)  Mtolua_new((Singularity::Graphics::MeshRenderer)(mesh,material));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::MeshRenderer");
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

/* method: new of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new01
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Mesh",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Material",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,0));
  Mesh* mesh = ((Mesh*)  tolua_tousertype(tolua_S,3,NULL));
  Material* material = ((Material*)  tolua_tousertype(tolua_S,4,NULL));
  {
   Singularity::Graphics::MeshRenderer* tolua_ret = (Singularity::Graphics::MeshRenderer*)  Mtolua_new((Singularity::Graphics::MeshRenderer)(name,mesh,material));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::MeshRenderer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new01_local
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Mesh",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Material",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  String name = *((String*)  tolua_tousertype(tolua_S,2,0));
  Mesh* mesh = ((Mesh*)  tolua_tousertype(tolua_S,3,NULL));
  Material* material = ((Material*)  tolua_tousertype(tolua_S,4,NULL));
  {
   Singularity::Graphics::MeshRenderer* tolua_ret = (Singularity::Graphics::MeshRenderer*)  Mtolua_new((Singularity::Graphics::MeshRenderer)(name,mesh,material));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Singularity::Graphics::MeshRenderer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_delete00
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::MeshRenderer* self = (Singularity::Graphics::MeshRenderer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Get_Mesh of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Get_Mesh00
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Get_Mesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::MeshRenderer* self = (const Singularity::Graphics::MeshRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Mesh'", NULL);
#endif
  {
   Mesh* tolua_ret = (Mesh*)  self->Get_Mesh();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mesh");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Mesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Mesh of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Set_Mesh00
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Set_Mesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Mesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::MeshRenderer* self = (Singularity::Graphics::MeshRenderer*)  tolua_tousertype(tolua_S,1,0);
  Mesh* value = ((Mesh*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Mesh'", NULL);
#endif
  {
   self->Set_Mesh(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Mesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get_Layer of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Get_Layer00
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Get_Layer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Singularity::Graphics::MeshRenderer* self = (const Singularity::Graphics::MeshRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get_Layer'", NULL);
#endif
  {
   unsigned tolua_ret = (unsigned)  self->Get_Layer();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get_Layer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set_Layer of class  Singularity::Graphics::MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Set_Layer00
static int tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Set_Layer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Singularity::Graphics::MeshRenderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Singularity::Graphics::MeshRenderer* self = (Singularity::Graphics::MeshRenderer*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set_Layer'", NULL);
#endif
  {
   self->Set_Layer(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set_Layer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Singularity_Graphics_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
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
     tolua_function(tolua_S,"Get_Orthographic",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Orthographic00);
     tolua_function(tolua_S,"Set_Orthographic",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_Orthographic00);
     tolua_function(tolua_S,"Get_BackgroundColor",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_BackgroundColor00);
     tolua_function(tolua_S,"Set_BackgroundColor",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_BackgroundColor00);
     tolua_function(tolua_S,"Get_FieldOfView",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_FieldOfView00);
     tolua_function(tolua_S,"Set_FieldOfView",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_FieldOfView00);
     tolua_function(tolua_S,"Get_NearClippingPlane",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_NearClippingPlane00);
     tolua_function(tolua_S,"Set_NearClippingPlane",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_NearClippingPlane00);
     tolua_function(tolua_S,"Get_FarClippingPlane",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_FarClippingPlane00);
     tolua_function(tolua_S,"Set_FarClippingPlane",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_FarClippingPlane00);
     tolua_function(tolua_S,"Get_Aspect",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Aspect00);
     tolua_function(tolua_S,"Set_Aspect",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Set_Aspect00);
     tolua_function(tolua_S,"Get_Width",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Width00);
     tolua_function(tolua_S,"Get_Height",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Height00);
     tolua_function(tolua_S,"Get_Projection",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Projection00);
     tolua_function(tolua_S,"Get_View",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_View00);
     tolua_function(tolua_S,"new",tolua_Singularity_Graphics_Singularity_Graphics_Camera_new00);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Graphics_Singularity_Graphics_Camera_new00_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Graphics_Singularity_Graphics_Camera_new00_local);
     tolua_function(tolua_S,"delete",tolua_Singularity_Graphics_Singularity_Graphics_Camera_delete00);
     tolua_function(tolua_S,"Get_Current",tolua_Singularity_Graphics_Singularity_Graphics_Camera_Get_Current00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_variable(tolua_S,"Singularity__Components",tolua_get_Singularity__Components,tolua_set_Singularity__Components);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Graphics",0);
   tolua_beginmodule(tolua_S,"Graphics");
    tolua_constant(tolua_S,"Point",Singularity::Graphics::Point);
    tolua_constant(tolua_S,"Spot",Singularity::Graphics::Spot);
    tolua_constant(tolua_S,"Directional",Singularity::Graphics::Directional);
    tolua_cclass(tolua_S,"LIGHT_DESC","Singularity::Graphics::LIGHT_DESC","",NULL);
    tolua_beginmodule(tolua_S,"LIGHT_DESC");
     tolua_variable(tolua_S,"Position",tolua_get_Singularity__Graphics__LIGHT_DESC_Position,tolua_set_Singularity__Graphics__LIGHT_DESC_Position);
     tolua_variable(tolua_S,"Pad0",tolua_get_Singularity__Graphics__LIGHT_DESC_Pad0,tolua_set_Singularity__Graphics__LIGHT_DESC_Pad0);
     tolua_variable(tolua_S,"Direction",tolua_get_Singularity__Graphics__LIGHT_DESC_Direction,tolua_set_Singularity__Graphics__LIGHT_DESC_Direction);
     tolua_variable(tolua_S,"Pad1",tolua_get_Singularity__Graphics__LIGHT_DESC_Pad1,tolua_set_Singularity__Graphics__LIGHT_DESC_Pad1);
     tolua_variable(tolua_S,"Color",tolua_get_Singularity__Graphics__LIGHT_DESC_Color,tolua_set_Singularity__Graphics__LIGHT_DESC_Color);
     tolua_variable(tolua_S,"Type",tolua_get_Singularity__Graphics__LIGHT_DESC_Type,tolua_set_Singularity__Graphics__LIGHT_DESC_Type);
     tolua_variable(tolua_S,"Falloff",tolua_get_Singularity__Graphics__LIGHT_DESC_Falloff,tolua_set_Singularity__Graphics__LIGHT_DESC_Falloff);
     tolua_variable(tolua_S,"Range",tolua_get_Singularity__Graphics__LIGHT_DESC_Range,tolua_set_Singularity__Graphics__LIGHT_DESC_Range);
     tolua_variable(tolua_S,"Intensity",tolua_get_Singularity__Graphics__LIGHT_DESC_Intensity,tolua_set_Singularity__Graphics__LIGHT_DESC_Intensity);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"Light","Singularity::Graphics::Light","Singularity::Components::Component",tolua_collect_Singularity__Graphics__Light);
    #else
    tolua_cclass(tolua_S,"Light","Singularity::Graphics::Light","Singularity::Components::Component",NULL);
    #endif
    tolua_beginmodule(tolua_S,"Light");
     tolua_function(tolua_S,"Get_Type",tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Type00);
     tolua_function(tolua_S,"Set_Orthographic",tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Orthographic00);
     tolua_function(tolua_S,"Get_Color",tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Color00);
     tolua_function(tolua_S,"Set_Color",tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Color00);
     tolua_function(tolua_S,"Get_Falloff",tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Falloff00);
     tolua_function(tolua_S,"Set_Falloff",tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Falloff00);
     tolua_function(tolua_S,"Get_Range",tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Range00);
     tolua_function(tolua_S,"Set_Range",tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Range00);
     tolua_function(tolua_S,"Get_Intensity",tolua_Singularity_Graphics_Singularity_Graphics_Light_Get_Intensity00);
     tolua_function(tolua_S,"Set_Intensity",tolua_Singularity_Graphics_Singularity_Graphics_Light_Set_Intensity00);
     tolua_function(tolua_S,"new",tolua_Singularity_Graphics_Singularity_Graphics_Light_new00);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Graphics_Singularity_Graphics_Light_new00_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Graphics_Singularity_Graphics_Light_new00_local);
     tolua_function(tolua_S,"new",tolua_Singularity_Graphics_Singularity_Graphics_Light_new01);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Graphics_Singularity_Graphics_Light_new01_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Graphics_Singularity_Graphics_Light_new01_local);
     tolua_function(tolua_S,"new",tolua_Singularity_Graphics_Singularity_Graphics_Light_new02);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Graphics_Singularity_Graphics_Light_new02_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Graphics_Singularity_Graphics_Light_new02_local);
     tolua_function(tolua_S,"new",tolua_Singularity_Graphics_Singularity_Graphics_Light_new03);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Graphics_Singularity_Graphics_Light_new03_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Graphics_Singularity_Graphics_Light_new03_local);
     tolua_function(tolua_S,"delete",tolua_Singularity_Graphics_Singularity_Graphics_Light_delete00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_variable(tolua_S,"Singularity__Components",tolua_get_Singularity__Components,tolua_set_Singularity__Components);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Graphics",0);
   tolua_beginmodule(tolua_S,"Graphics");
    tolua_function(tolua_S,"(__fastcall__RenderCallback)",tolua_Singularity_Graphics_Singularity_Graphics_(__fastcall__RenderCallback)00);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"Renderer","Singularity::Graphics::Renderer","Singularity::Components::Component",tolua_collect_Singularity__Graphics__Renderer);
    #else
    tolua_cclass(tolua_S,"Renderer","Singularity::Graphics::Renderer","Singularity::Components::Component",NULL);
    #endif
    tolua_beginmodule(tolua_S,"Renderer");
     tolua_function(tolua_S,"Get_IsVisible",tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_IsVisible00);
     tolua_function(tolua_S,"Get_Material",tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_Material00);
     tolua_function(tolua_S,"Set_Material",tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Set_Material00);
     tolua_function(tolua_S,"Get_Bounds",tolua_Singularity_Graphics_Singularity_Graphics_Renderer_Get_Bounds00);
     tolua_function(tolua_S,"RegisterCallback",tolua_Singularity_Graphics_Singularity_Graphics_Renderer_RegisterCallback00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Singularity",0);
  tolua_beginmodule(tolua_S,"Singularity");
   tolua_module(tolua_S,"Graphics",0);
   tolua_beginmodule(tolua_S,"Graphics");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"MeshRenderer","Singularity::Graphics::MeshRenderer","Singularity::Graphics::Renderer",tolua_collect_Singularity__Graphics__MeshRenderer);
    #else
    tolua_cclass(tolua_S,"MeshRenderer","Singularity::Graphics::MeshRenderer","Singularity::Graphics::Renderer",NULL);
    #endif
    tolua_beginmodule(tolua_S,"MeshRenderer");
     tolua_function(tolua_S,"new",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new00_local);
     tolua_function(tolua_S,"new",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new01);
     tolua_function(tolua_S,"new_local",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new01_local);
     tolua_function(tolua_S,".call",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_new01_local);
     tolua_function(tolua_S,"delete",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_delete00);
     tolua_function(tolua_S,"Get_Mesh",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Get_Mesh00);
     tolua_function(tolua_S,"Set_Mesh",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Set_Mesh00);
     tolua_function(tolua_S,"Get_Layer",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Get_Layer00);
     tolua_function(tolua_S,"Set_Layer",tolua_Singularity_Graphics_Singularity_Graphics_MeshRenderer_Set_Layer00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Singularity_Graphics (lua_State* tolua_S) {
 return tolua_Singularity_Graphics_open(tolua_S);
};
#endif

