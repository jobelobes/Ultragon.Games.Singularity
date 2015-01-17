#define IMPLEMENT_GETTER(type, name, variable) \
    inline type Get_##name() const { return variable; }

#define IMPLEMENT_SETTER(type, name, variable); \
	inline void Set_##name(type value) { variable = value; }

#define IMPLEMENT_PROPERTY(type, name, variable) \
    inline type Get_##name() const { return variable; }; \
	inline void Set_##name(type value) { variable = value; }

#define IMPLEMENT_CAST_PROPERTY(type1, name, type2, variable) \
    inline type1 Get_##name() const { return (type1)variable; }; \
	inline void Set_##name(type1 value) { variable = (type2)value; }

#define Autolock(x) for (Singularity::Threading::_AutoLock __lock(x);__lock;__lock._Release())

#define DECLARE_OBJECT_TYPE \
public: \
	static const ObjectType Type; \
    virtual const ObjectType& GetType() const { return Type; }

#define IMPLEMENT_OBJECT_TYPE(nsname, classname, baseclassname) \
    const ObjectType classname::Type(#nsname"."#classname, &baseclassname::Type)

#define D3DX_PIOVER2	(D3DX_PI / 2.0f)
#define D3DX_PIOVER4	(D3DX_PI / 4.0f)
#define D3DX_TWOPI		(D3DX_PI * 2.0f)

#ifndef SINGULARITY_USE_DIRECTX_10
#define SINGULARITY_USE_DIRECTX_10 1
#endif

#ifndef SINGULARITY_USE_STL
#define SINGULARITY_USE_STL 1
#endif

#ifndef SINGULARITY_USE_DIRECTX_STRUCTS
#define SINGULARITY_USE_DIRECTX_STRUCTS 1
#endif

#define WIN32_LEAN_AND_MEAN
#define _USE_MATH_DEFINES