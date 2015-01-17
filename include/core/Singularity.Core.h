#pragma once

#include <algorithm>
#include <windows.h>
#include <assert.h>

#include "common\Singularity.Common.h"

namespace Singularity
{
	class Game;
	class GameTask;
	class BehaviorTask;

	namespace Threading
	{
		class Task;
		class WorkerThread;
		class TaskScheduler;
		class TaskQueue;
	}

	namespace Components 
	{ 
		class GameObject;
		class Component; 
		class Behavior;

		class Scene;
		class Transform;
		class TransformDelegate;
	} 
}

#include "core\Singularity.Core.Defines.h"

#include "core\threading\TaskScheduler.h"
#include "core\threading\Task.h"
#include "core\threading\TaskQueue.h"
#include "core\threading\WorkerThread.h"

#include "core\components\GameObject.h"
#include "core\components\Component.h"

#include "core\components\BehaviorDelegate.h"
#include "core\components\Behavior.h"

#include "core\components\Scene.h"
#include "core\components\TransformDelegate.h"
#include "core\components\Transform.h"

#include "core\Game.h"
#include "core\GameTask.h"
#include "core\BehaviorTask.h"
