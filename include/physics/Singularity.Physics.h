#pragma once

#pragma comment(lib, "LinearMath.lib")
#pragma comment(lib, "BulletCollision.lib")
#pragma comment(lib, "BulletDynamics.lib")

#include <math.h>

#include "physics\Singularity.Physics.Defines.h"

//dependencies
#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"
#include "graphics\Singularity.Graphics.h"
//#include "btBulletCollisionCommon.h"
#include "bulletphysics\btBulletDynamicsCommon.h"
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
#include "BulletDynamics\Character\btKinematicCharacterController.h"

namespace Singularity
{
	namespace Physics
	{
		class Collider;
		class BoxCollider;
		class SphereCollider;
		class CapsuleCollider;
		class CharacterController;

		class PhysicsMotionState;
		class RigidBody;

		class PhysicsTask;
		class PhysicsSubTask;
	}
}

#include "physics\CollisionDelegate.h"
#include "physics\Collider.h"
#include "physics\BoxCollider.h"
#include "physics\SphereCollider.h"
#include "physics\CapsuleCollider.h"
#include "physics\CharacterController.h"

#include "physics\PhysicsMotionState.h"
#include "physics\CollisionDispatcher.h"

#include "physics\RigidBody.h"

#include "physics\PhysicsTask.h"
#include "physics\PhysicsSubTask.h"