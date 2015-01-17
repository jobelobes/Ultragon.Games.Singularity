#pragma once

#if _DEBUG
//#pragma comment(lib, "fbxsdk_mt2008d.lib")
#else
//#pragma comment(lib, "fbxsdk_mt2008.lib")
#endif


namespace Singularity
{
	namespace Content
	{
		class IContentImporter;
		class IModelImporter;

		class MeshLoader;

		//class FbxModelImporter;
		class ObjModelImporter;
	}
}

//#include "3rdparty\fbx\fbxsdk.h"

#include "content\Singularity.Content.Defines.h"

// extensions
#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "graphics\Singularity.Graphics.h"
#include "animations\Singularity.Animations.h"
#include "physics\Singularity.Physics.h"

#include "content\IContentImporter.h"
#include "content\IModelImporter.h"

#include "content\ModelLoader.h"

//#include "content\FbxModelImporter.h"
#include "content\ObjModelImporter.h"
#include "content\SmurfModelImporter.h"