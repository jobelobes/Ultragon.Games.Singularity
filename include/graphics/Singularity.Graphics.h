#pragma once

#pragma comment(lib, "Dbghelp.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "DXGI.lib")
#pragma comment(lib, "dxerr.lib")

// directX libraries
#include <d3d10.h>
#include <d3dx10.h>
#include <Dbghelp.h>
#include <dxgi.h>

// dependencies
#include "common\Singularity.Common.h"
#include "core\Singularity.Core.h"

// just to make the compiling go down easier
namespace Singularity 
{	
	namespace Graphics
	{
		namespace Devices
		{
			class HardwareDevice;

			class DrawingContext;
			class BufferedDrawingContext;
			class DeferredDrawingContext;
		}

		class VertexDeclaration;
		
		class Screen;
		class GraphicsDevice;
		
		class RenderState;

		class InternalVertexBuffer;
		class InternalIndexBuffer;
		class InternalMaterial;

		class VertexBuffer;
		class IndexBuffer;
		class Texture2D;
		class RenderTexture;
		class Material;
		class ModelBone;
		class ModelSkeleton;
		class Mesh;

		class Layer;
		class Frame;
		class RenderState;
		
		class Renderer;
		class RenderTask;
		class RenderSubTask;

		class IRenderGraph;
		class IRenderIterator;

		class LinearRenderGraph;
		class LinearRenderIterator;

		class OctTreeRenderGraph;
		class OctTreeRenderIterator;

		class Camera;
		class Light;
		class MeshRenderer;
		class Axis;

		struct CAMERA_DESC
		{
			Vector3		Position;
			float		Pad0;
			Vector2		Resolution;
			float		Pad1, Pad2;
			Matrix		Projection;
			Matrix		View;
		};

		struct LIGHT_DESC
		{
			Vector3		Position;
			float		Pad0;
			Vector3		Direction;
			float		Pad1;
			Color		Color;
			unsigned	Type;
			float		Falloff;
			float		Range;
			float		Intensity;
		};

		typedef  void (__fastcall *RenderCallback)(Renderer* sender, Singularity::Graphics::Devices::DrawingContext* context, Camera* camera);
	}
}

#include "graphics\Singularity.Graphics.Defines.h"
#include "..\resources\Singularity.Graphics.Resources.h"

#include "graphics\VertexDeclaration.h"

#include "graphics\VertexPositionColor.h"
#include "graphics\VertexPositionColorTexture.h"
#include "graphics\VertexPositionNormalTexture.h"
#include "graphics\VertexPositionTexture.h"
#include "graphics\VertexPositionNormalTextureBone.h"

#include "graphics\devices\RenderState.h"
#include "graphics\devices\Screen.h"
#include "graphics\devices\HardwareDevice.h"
#include "graphics\devices\GraphicsDevice.h"

#include "graphics\devices\DrawingContext.h"
#include "graphics\devices\BufferedDrawingContext.h"
#include "graphics\devices\DeferredDrawingContext.h"

#include "graphics\InternalVertexBuffer.h"
#include "graphics\InternalIndexBuffer.h"
#include "graphics\InternalMaterial.h"

#include "graphics\VertexBuffer.h"
#include "graphics\IndexBuffer.h"
#include "graphics\Texture2D.h"
#include "graphics\RenderTexture.h"
#include "graphics\Material.h"
#include "graphics\Mesh.h"

// tasks
#include "graphics\RenderTask.h"
#include "graphics\RenderSubTask.h"

// components
#include "graphics\components\Renderer.h"
#include "graphics\components\Camera.h"
#include "graphics\components\Light.h"
#include "graphics\components\MeshRenderer.h"
#include "graphics\components\Axis.h"