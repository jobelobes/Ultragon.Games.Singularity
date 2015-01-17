#pragma once

//just to make the compiling go down easier
namespace Singularity
{
	namespace Particles
	{
		class ParticleVertex;
		class ParticleEmitter;
		class EmitterManager;
	}
}

#include "particles\Singularity.Particles.Defines.h"
#include "..\resources\Singularity.Particles.Resources.h"

// dependencies
#include "common\Singularity.Common.h"
#include "graphics\Singularity.Graphics.h"

//Main components
#include "particles\ParticleVertex.h"
#include "particles\ParticleEmitter.h"
#include "particles\EmitterManager.h"

