#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Graphics::Devices;

namespace Singularity
{
	namespace Graphics
	{
		enum Blend { 
			Zero = 1, 
			One = 2, 
			SourceColor = 3,
			InverseSourceColor = 4,
			SourceAlpha = 5,
			InverseSourceAlpha = 6,
			DestinationAlpha = 7,
			InverseDestinationAlpha = 8,
			DestinationColor = 9,
			InverseDestinationColor = 10,
			SourceAlphaSaturation = 11,
			BlendFactor = 14,
			InverseBlendFactor = 15 };

		enum PrimitiveTopology {
			PointList = 1,
			LineList = 2,
			LineStrip = 3,
			TriangleList = 4,
			TriangleStrip = 5 };

		enum BlendFunction { 
			Add = 1, 
			Subtract = 2, 
			ReverseSubtract	= 3, 
			Min = 4, 
			Max = 5 };

		enum CullMode { 
			None = 1, 
			Front = 2, 
			Back = 3 };

		enum FillMode { 
			Wireframe = 2, 
			Solid = 3 };

		enum WriteEnable {
			Red = 1,
			Green = 2,
			Blue = 4,
			Alpha = 8,
			All = 0xF };

		class RenderState
		{
			public:
				#pragma region Static Variables
				static const RenderState Default;
				#pragma endregion

				#pragma region Variables
				PrimitiveTopology			PrimitiveType;
				D3D10_RASTERIZER_DESC		RasterizerDesc;
				D3D10_BLEND_DESC			BlendDesc;
				Color						BlendFactors;
				unsigned					SampleMask;
				#pragma endregion

				#pragma region Properties
				// D3D10_BLEND_DESC
				IMPLEMENT_PROPERTY(PrimitiveTopology, PrimitiveType, PrimitiveType);
				IMPLEMENT_CAST_PROPERTY(bool, EnableAlphaToCoverage, BOOL, BlendDesc.AlphaToCoverageEnable);
				IMPLEMENT_CAST_PROPERTY(Blend, SourceBlend, D3D10_BLEND, BlendDesc.SrcBlend);
				IMPLEMENT_CAST_PROPERTY(Blend, DestinationBlend, D3D10_BLEND, BlendDesc.DestBlend);
				IMPLEMENT_CAST_PROPERTY(BlendFunction, BlendFunction, D3D10_BLEND_OP, BlendDesc.BlendOp);
				IMPLEMENT_CAST_PROPERTY(Blend, AlphaSourceBlend, D3D10_BLEND, BlendDesc.SrcBlendAlpha);
				IMPLEMENT_CAST_PROPERTY(Blend, AlphaDestinationBlend, D3D10_BLEND, BlendDesc.DestBlendAlpha);
				IMPLEMENT_CAST_PROPERTY(BlendFunction, AlphaBlendOperation, D3D10_BLEND_OP, BlendDesc.BlendOpAlpha);
				IMPLEMENT_PROPERTY(Color, BlendFactor, BlendFactors);

				// D3D10_RASTERIZER_DESC
				IMPLEMENT_CAST_PROPERTY(FillMode, FillMode, D3D10_FILL_MODE, RasterizerDesc.FillMode);
				IMPLEMENT_CAST_PROPERTY(CullMode, CullMode, D3D10_CULL_MODE, RasterizerDesc.CullMode);
				IMPLEMENT_CAST_PROPERTY(bool, EnableDepthBuffer, BOOL, RasterizerDesc.DepthClipEnable);
				IMPLEMENT_CAST_PROPERTY(bool, EnableScissorTest, BOOL, RasterizerDesc.ScissorEnable);
				IMPLEMENT_CAST_PROPERTY(bool, EnableMultisample, BOOL, RasterizerDesc.MultisampleEnable);
				IMPLEMENT_CAST_PROPERTY(bool, EnableAntialiasedLine, BOOL, RasterizerDesc.AntialiasedLineEnable);

				// BOOL FrontCounterClockwise;
				// INT DepthBias;
				// FLOAT DepthBiasClamp;
				// FLOAT SlopeScaledDepthBias;
				#pragma endregion

				#pragma region Constructors and Finalizers
				RenderState();
				#pragma endregion

				#pragma region Methods
				inline void EnableBlend(const unsigned renderTarget) { this->BlendDesc.BlendEnable[renderTarget] = true; }
				inline void DisableBlend(const unsigned renderTarget) { this->BlendDesc.BlendEnable[renderTarget] = false; }
				inline void SetWriteMask(const unsigned renderTarget, WriteEnable value) { this->BlendDesc.RenderTargetWriteMask[renderTarget] = value; }

				bool Equals(RenderState& state);
				#pragma endregion
		};
	}
}