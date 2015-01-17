#pragma once

namespace Singularity
{
	namespace Animations
	{
		struct Keyframe;
		struct Frame;
		struct Joint;
	}

	namespace Graphics
	{
		class AnimationVertex;
		class ModelBone;
		class ModelSkeleton;
		class SkinnedMesh;
		class SkinnedMeshRenderer;
	}

	namespace Animations
	{
		class AnimationClip;
		class Animation;
		struct AnimationState;

		class AnimationTask;
		class AnimationSubTask;
		class SkinningData;
	}
}

#include "animations\Singularity.Animations.Defines.h"
#include "..\resources\Singularity.Animations.Resources.h"

// dependencies
#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "graphics\Singularity.Graphics.h"

#include "animations\Frame.h"
#include "animations\Keyframe.h"
#include "animations\Joint.h"

#include "animations\AnimationVertex.h"
#include "animations\ModelBone.h"
#include "animations\ModelSkeleton.h"
#include "animations\SkinnedMesh.h"
#include "animations\SkinnedMeshRenderer.h"

#include "animations\AnimationClip.h"
#include "animations\Animation.h"

#include "animations\AnimationState.h"
#include "animations\AnimationTask.h"
#include "animations\AnimationSubTask.h"