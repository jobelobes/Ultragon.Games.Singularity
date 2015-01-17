#pragma once

#pragma comment(lib, "x3daudio.lib")

#include <Xact3.h>
#include <Xact3d3.h>
#include <X3daudio.h>
#include <vector>
#include <string>

#include "common\Singularity.Common.h"

using namespace std;

// just to make the compiling go down easier
namespace Singularity 
{	
	namespace Audio
	{
		// Public Access
		class AdaptiveMusicManager;
		class AudioManager;

		// XACT Wrappers
		class AudioEngine;
		class Cue;
		class SoundBank;
		class WaveBank;

		// Components
		class AdaptiveMusicUpdater;
		class AudioEmitter;
		class AudioListener;

		// Extensions
		class AudioExtension;
		class AdaptiveAudioTask;

		// Adaptive
		class AdaptiveProperty;
		class AdaptiveSlice;
		class AdaptiveParameter;
		class AdaptiveEnvironment;

		//struct AdaptivePropertyPoint { Vector2 position; AdaptivePropertyCurve curve; };
	}
}



#include "core\Singularity.Core.h"

#include "audio\Singularity.Audio.Defines.h" // For when we have some defines...

#include "audio\AdaptiveMusicManager.h"
#include "audio\AudioManager.h"

#include "audio\AudioEngine.h"
#include "audio\Cue.h"
#include "audio\SoundBank.h"
#include "audio\WaveBank.h"

#include "audio\AdaptiveMusicUpdater.h"
#include "audio\AudioEmitter.h"
#include "audio\AudioListener.h"

#include "audio\AudioExtension.h"
#include "audio\AdaptiveAudioTask.h"

#include "audio\AdaptiveParameter.h"
#include "audio\AdaptiveSlice.h"
#include "audio\AdaptiveProperty.h"
#include "audio\AdaptiveEnvironment.h"

