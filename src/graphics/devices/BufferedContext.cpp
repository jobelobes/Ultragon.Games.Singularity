#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			#pragma region Constructors and Finalizers
			BufferedContext::BufferedContext(unsigned capacity)
				: m_pBuffer(NULL), m_pCurrent(NULL)
			{
				this->m_pBuffer = new CommandBuffer(capacity);
				this->m_pCurrent = this->m_pBuffer->Get_Root();
			}

			BufferedContext::~BufferedContext()
			{
				if(this->m_pBuffer)
					delete this->m_pBuffer;
			}
			#pragma endregion
				
			#pragma region Methods	
			void BufferedContext::Reset()
			{
				this->m_pBuffer->Reset();
				this->m_pCurrent = this->m_pBuffer->Get_Root();
			}
			#pragma endregion

			#pragma region Methods
			void BufferedContext::SetView(Matrix& projection, Matrix& view)
			{
				CommandData data;
				memcpy(&data.View.View[0], (float*)view, sizeof(Matrix));
				memcpy(&data.View.Projection[0], (float*)projection, sizeof(Matrix));

				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetView, data);
			}

			void BufferedContext::SetLayer(unsigned layer)
			{
				CommandData data;
				data.Layer = layer;

				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetLayer, data);
			}

			void BufferedContext::SetRenderState(RenderState& renderstate)
			{
				CommandData topology, blend, rasterizer;

				topology.Topology = (D3D10_PRIMITIVE_TOPOLOGY)renderstate.PrimitiveType;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetTopology, topology);

				blend.BlendState.Description = renderstate.BlendDesc;
				memcpy(&blend.BlendState.BlendFactors, renderstate.BlendFactors, sizeof(float) * 4);
				blend.BlendState.SampleMask = renderstate.SampleMask;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetBlendState, blend);

				rasterizer.RasterizerState = renderstate.RasterizerDesc;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetRasterizerState, rasterizer);
			}

			void BufferedContext::Draw(Material* material, Matrix& world, VertexBuffer* vertices, int start, int length, int pass)
			{
				CommandNode* view;
				CommandData materialData, vbuffer, ibuffer, passData, parameters, draw;

				view = this->m_pBuffer->FindNode(this->m_pCurrent, CommandType::SetView);
				material->SetVariable("View", Matrix(view->Command.View.View));
				material->SetVariable("Projection", Matrix(view->Command.View.Projection));

				materialData.Materials.Material = material->m_pInternal;
				materialData.Materials.Declaration = vertices->m_pInternal->m_pDeclaration;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetMaterial, materialData);

				vbuffer.Vertices.Buffer = vertices->m_pInternal->m_iBuffer;
				vbuffer.Vertices.Stride = vertices->m_pInternal->m_pDeclaration->Get_SizeInBytes();
				vbuffer.Vertices.Offset = 0;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetVertexBuffer, vbuffer);

				ibuffer.Indices.Buffer = NULL;
				ibuffer.Indices.Format = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
				ibuffer.Indices.Offset = 0;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetIndexBuffer, ibuffer);

				parameters.PassParameters = material;
				parameters.PassParameters->SetVariable("world", world);
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetMaterialParameters, parameters);

				passData.Pass.Material = material;
				passData.Pass.Index = 0;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetPass, passData);

				draw.Draw.Indexed = false;
				draw.Draw.Count = vertices->m_iLength + (length == -1) ? 0 : length;
				draw.Draw.Start = vertices->m_iStart + (start == -1) ? 0 : start;
				draw.Draw.BaseVertex = 0;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::DrawCommand, draw);
			}

			void BufferedContext::DrawIndexed(Material* material, Matrix& world, VertexBuffer* vertices, IndexBuffer* indices, int start, int length, int vertexOffset, int pass)
			{
				CommandNode* view;
				CommandData materialData, vbuffer, ibuffer, passData, parameters, drawData;

				view = this->m_pBuffer->FindNode(this->m_pCurrent, CommandType::SetView);
				material->SetVariable("view", Matrix(view->Command.View.View));
				material->SetVariable("projection", Matrix(view->Command.View.Projection));

				materialData.Materials.Material = material->m_pInternal;
				materialData.Materials.Declaration = vertices->m_pInternal->m_pDeclaration;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetMaterial, materialData);

				vbuffer.Vertices.Buffer = vertices->m_pInternal->m_iBuffer;
				vbuffer.Vertices.Stride = vertices->m_pInternal->m_pDeclaration->Get_SizeInBytes();
				vbuffer.Vertices.Offset = 0;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetVertexBuffer, vbuffer);

				ibuffer.Indices.Buffer = indices->m_pInternal->m_iBuffer;
				ibuffer.Indices.Format = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
				ibuffer.Indices.Offset = 0;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetIndexBuffer, ibuffer);

				parameters.PassParameters = material;
				parameters.PassParameters->SetVariable("world", world);
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetMaterialParameters, parameters);

				passData.Pass.Material = material;
				passData.Pass.Index = 0;
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::SetPass, passData);

				drawData.Draw.Indexed = true;
				drawData.Draw.Count = indices->m_iLength + ((length == -1) ? 0 : length);
				drawData.Draw.Start = indices->m_iStart + ((start == -1) ? 0 : start);
				drawData.Draw.BaseVertex = vertices->m_iStart + ((vertexOffset == -1) ? 0 : vertexOffset);
				this->m_pCurrent = this->m_pBuffer->InsertNode(this->m_pCurrent, CommandType::DrawCommand, drawData);
			}
			#pragma endregion
		}
	}
}