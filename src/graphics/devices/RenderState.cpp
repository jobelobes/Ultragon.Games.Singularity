#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		const RenderState RenderState::Default;
		#pragma endregion

		#pragma region Constructors and Finalizers
		RenderState::RenderState()
		{
			this->PrimitiveType = PrimitiveTopology::TriangleList;

			ZeroMemory(&this->RasterizerDesc, sizeof(D3D10_RASTERIZER_DESC));
			this->RasterizerDesc.FillMode = (D3D10_FILL_MODE)FillMode::Solid;
			this->RasterizerDesc.CullMode = (D3D10_CULL_MODE)CullMode::Front;
			//this->RasterizerDesc.FrontCounterClockwise = FALSE;
			//this->RasterizerDesc.DepthBias;
			//this->RasterizerDesc.DepthBiasClamp;
			//this->RasterizerDesc.SlopeScaledDepthBias;
			this->RasterizerDesc.DepthClipEnable = true;
			this->RasterizerDesc.ScissorEnable = false;
			this->RasterizerDesc.MultisampleEnable = true;
			this->RasterizerDesc.AntialiasedLineEnable = false;

			ZeroMemory(&this->BlendDesc, sizeof(D3D10_BLEND_DESC));
			this->BlendDesc.AlphaToCoverageEnable = false;
			this->BlendDesc.BlendEnable[0] = false;
			this->BlendDesc.BlendEnable[1] = false;
			this->BlendDesc.BlendEnable[2] = false;
			this->BlendDesc.BlendEnable[3] = false;
			this->BlendDesc.BlendEnable[4] = false;
			this->BlendDesc.BlendEnable[5] = false;
			this->BlendDesc.BlendEnable[6] = false;
			this->BlendDesc.BlendEnable[7] = false;
			this->BlendDesc.SrcBlend = (D3D10_BLEND)Blend::One;
			this->BlendDesc.DestBlend = (D3D10_BLEND)Blend::Zero;
			this->BlendDesc.BlendOp = (D3D10_BLEND_OP)BlendFunction::Add;
			this->BlendDesc.SrcBlendAlpha = (D3D10_BLEND)Blend::One;
			this->BlendDesc.DestBlendAlpha = (D3D10_BLEND)Blend::Zero;
			this->BlendDesc.BlendOpAlpha = (D3D10_BLEND_OP)BlendFunction::Add;
			this->BlendDesc.RenderTargetWriteMask[0] = WriteEnable::All;
			this->BlendDesc.RenderTargetWriteMask[1] = WriteEnable::All;
			this->BlendDesc.RenderTargetWriteMask[2] = WriteEnable::All;
			this->BlendDesc.RenderTargetWriteMask[3] = WriteEnable::All;
			this->BlendDesc.RenderTargetWriteMask[4] = WriteEnable::All;
			this->BlendDesc.RenderTargetWriteMask[5] = WriteEnable::All;
			this->BlendDesc.RenderTargetWriteMask[6] = WriteEnable::All;
			this->BlendDesc.RenderTargetWriteMask[7] = WriteEnable::All;

			this->BlendFactors = Color(0.0f, 0.0f, 0.0f, 0.0f);
			this->SampleMask = 0xffffffff;
		}
		#pragma endregion

		#pragma region Methods
		bool RenderState::Equals(RenderState& state)
		{

			return false;
		}
		#pragma endregion
	}
}