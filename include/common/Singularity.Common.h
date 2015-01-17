#pragma once

#define _WINSOCKAPI_
#pragma warning( disable: 4482 ) // nonstandard extension used: enum 'enum' used in qualified name
#pragma warning( disable: 4251 ) // class '{class}' needs to have dll-interface to be used by clients of class '{class}'
#pragma warning( disable: 4800 ) // 'const BOOL' : forcing value to bool 'true' or 'false' (performance warning)

#include <iostream>
#include <limits>
#include <exception>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>

// windows libraries
#include <tchar.h>
#include <windows.h>
#include <winbase.h>
#include <direct.h>
#include <intrin.h>

#include "common\Singularity.Common.Defines.h"
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/exception/all.hpp>
#include <boost/make_shared.hpp>

// directX libraries
#if SINGULARITY_USE_DIRECTX_10

#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "d3d10.lib")

#include <d3dx10.h>
#include <d3d10.h>
#endif

#if SINGULARITY_USE_STL

#include <vector>
#define DynamicList std::vector // since templates cannot be typedef-ed

#include <map>
#define DynamicMap std::map // since templates cannot be typedef-ed

#include <set>
#define DynamicSet std::set // since templates cannot be typedef-ed

#endif

typedef std::string String;

#if SINGULARITY_USE_DIRECTX_STRUCTS

//typedef D3DXCOLOR Color;
//
//typedef D3DXQUATERNION Quaternion;
//
//typedef D3DXMATRIX Matrix;
//
//typedef D3DXVECTOR2 Vector2;
//typedef D3DXVECTOR3 Vector3;
//typedef D3DXVECTOR4 Vector4;

#endif

namespace Singularity
{
	class ObjectType;
	class Object;

	class IDelegate;
	class DelegateHandler;

	struct SingularityException;
}

#include "common\Math.h"

#include "common\SingularityException.h"
#include "common\CriticalSection.h"
#include "common\Lock.h"

#include "common\ObjectType.h"
#include "common\Object.h"

#include "common\Timer.h"
#include "common\TimeSpan.h"

#include "common\Bounds.h"

#include "common\Octree.h"
#include "common\OctreeIterator.h"

#include "common\IDelegate.h"
#include "common\CallbackDelegate.h"
#include "common\DelegateHandler.h"