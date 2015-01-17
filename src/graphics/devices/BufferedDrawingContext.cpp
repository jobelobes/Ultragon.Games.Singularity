#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			#pragma region Constructors and Finalizers
			BufferedDrawingContext::BufferedDrawingContext(unsigned capacity)
				: m_iCapacity(capacity), m_pStart(NULL), m_pCurrent(NULL)
			{
				this->m_pStart = (BufferedDrawingContext::CommandNode*)malloc(sizeof(BufferedDrawingContext::CommandNode) * this->m_iCapacity);
				this->m_pCurrent = this->m_pStart;
			}

			BufferedDrawingContext::~BufferedDrawingContext()
			{
				if(this->m_pStart != NULL)
					delete [] this->m_pStart;
			}
			#pragma endregion
				
			#pragma region Methods
			BufferedDrawingContext::CommandNode* BufferedDrawingContext::FindNode(BufferedDrawingContext::CommandNode* start, CommandType type)
			{
				BufferedDrawingContext::CommandNode* node;

				if((int)type > (start->Type + 1))
					throw SingularityException("Command buffer tree is corrupted.");

				node = start;
				do
				{
					if(node->Type == type)
						return node;
					else if(node->Type > type)
						node = node->Parent;
				}
				while(node != NULL);

				return NULL;
			}

			BufferedDrawingContext::CommandNode* BufferedDrawingContext::InsertNode(BufferedDrawingContext::CommandNode* start, CommandType type, CommandData command)
			{
				BufferedDrawingContext::CommandNode* parent;
				BufferedDrawingContext::CommandNode* node;

				if(this->m_iSize >= this->m_iCapacity)
					throw SingularityException("Unable to add new node, the capacity has been reached.");

				if((int)type > (start->Type + 1))
					throw SingularityException("Command buffer tree is corrupted.");

				parent = this->FindNode(start, (CommandType)(type - 1));
				node = NULL;
				if(type != CommandType::DrawCommand)
				{
					node = parent->Child;
					while(node != NULL)
					{
						if(!memcmp(&node->Command, &command, sizeof(CommandData)))
							break;

						node = node->Sibling;
					}
				}

				if(node == NULL)
				{
					node = &this->m_pStart[this->m_iSize++];
					node->Parent = parent;
					node->Sibling = parent->Child;
					node->Next = (node->Sibling == NULL) ? parent->Next : node->Sibling;
					node->Type = type;
					memcpy(&node->Command, &command, sizeof(CommandData));

					parent->Next = node;
					parent->Child = node;
				}
				return node;
			}

			void BufferedDrawingContext::ExecuteCommand(CommandType type, CommandData data)
			{
				HRESULT hr;
				ID3D10BlendState* blendstate;
				ID3D10RasterizerState* rasterizerstate;

				switch(type)
				{
					case CommandType::NullCommand:
						break;
					case CommandType::SetLayerCommand:
						break;
					case CommandType::SetTopologyCommand:
						this->Get_InternalDevice()->IASetPrimitiveTopology(data.Topology);
						break;
					case CommandType::SetBlendStateCommand:
						hr = this->Get_InternalDevice()->CreateBlendState(&data.BlendState.Description, &blendstate);
						if(FAILED(hr))
							throw SingularityException("Unable to create blend state.", hr);

						this->Get_InternalDevice()->OMSetBlendState(blendstate, &data.BlendState.BlendFactors[0], data.BlendState.SampleMask);
						break;
					case CommandType::SetRasterizerStateCommand:
						hr = this->Get_InternalDevice()->CreateRasterizerState(&data.RasterizerState, &rasterizerstate);
						if(FAILED(hr))
							throw SingularityException("Unable to create rasterizer state.", hr);

						this->Get_InternalDevice()->RSSetState(rasterizerstate);
						break;
					case CommandType::SetInputLayoutCommand:
						this->Get_InternalDevice()->IASetInputLayout(data.InputLayout);		
						break;
					case CommandType::SetVertexBufferCommand:
						this->Get_InternalDevice()->IASetVertexBuffers(0, 1, &data.Vertices.Buffer, &data.Vertices.Stride, &data.Vertices.Offset);
						break;
					case CommandType::SetIndexBufferCommand:
						if(data.Indices.Buffer != NULL)
							this->Get_InternalDevice()->IASetIndexBuffer(data.Indices.Buffer, data.Indices.Format, data.Indices.Offset);
						break;
					case CommandType::SetEffectParametersCommand:
						data.PassParameters->Apply();
						break;
					case CommandType::SetPassCommand:
						if(FAILED(data.Pass->Apply(0)))
							throw SingularityException("Unable to apply effect pass.");
						break;
					case CommandType::DrawCommand:
						if(data.Draw.Indexed)
							this->Get_InternalDevice()->DrawIndexed(data.Draw.Length, data.Draw.Start, data.Draw.BaseVertex);	
						else
							this->Get_InternalDevice()->Draw(data.Draw.Length, data.Draw.Start);
						break;
					default:
						break;
				}
			}

			void BufferedDrawingContext::Combine(BufferedDrawingContext* context)
			{


			}
			#pragma endregion

			#pragma region Methods
			void BufferedDrawingContext::SetLayer(unsigned layer)
			{
				m_kSetup[0].Layer = layer;
			}

			void BufferedDrawingContext::SetRenderState(RenderState& renderstate)
			{
				m_kSetup[1].Topology = (D3D10_PRIMITIVE_TOPOLOGY)renderstate.PrimitiveType;

				m_kSetup[2].BlendState.Description = renderstate.BlendDesc;
				memcpy(&m_kSetup[2].BlendState.BlendFactors, (float*)renderstate.BlendFactors, sizeof(float) * 4);
				m_kSetup[2].BlendState.SampleMask = renderstate.SampleMask;

				m_kSetup[3].RasterizerState = renderstate.RasterizerDesc;
			}

			void BufferedDrawingContext::SetInputLayout(ID3D10InputLayout* inputlayout)
			{
				m_kSetup[4].InputLayout = inputlayout;
			}

			void BufferedDrawingContext::SetVertexBuffer(ID3D10Buffer* buffer, unsigned stride, unsigned start, unsigned length)
			{
				m_kSetup[5].Vertices.Buffer = buffer;
				m_kSetup[5].Vertices.Stride = stride;
				m_kSetup[5].Vertices.Offset = 0;
			}

			void BufferedDrawingContext::SetIndexBuffer(ID3D10Buffer* buffer, DXGI_FORMAT format, unsigned start, unsigned length)
			{
				m_kSetup[6].Indices.Buffer = buffer;
				m_kSetup[6].Indices.Format = format;
				m_kSetup[6].Indices.Offset = 0;
			}

			void BufferedDrawingContext::SetMaterial(Material* material)
			{
				m_kSetup[7].PassParameters = material;
			}

			void BufferedDrawingContext::SetPass(ID3D10EffectPass* pass)
			{
				m_kSetup[8].Pass = pass;
			}

			void BufferedDrawingContext::Draw(unsigned length, unsigned  start)
			{
				CommandData data;
				data.Draw.Indexed = false;
				data.Draw.Length = length;
				data.Draw.Start = start;
				data.Draw.BaseVertex = 0;

				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetLayerCommand, m_kSetup[0]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetTopologyCommand, m_kSetup[1]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetBlendStateCommand, m_kSetup[2]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetRasterizerStateCommand, m_kSetup[3]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetInputLayoutCommand, m_kSetup[4]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetVertexBufferCommand, m_kSetup[5]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetIndexBufferCommand, m_kSetup[6]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetEffectParametersCommand, m_kSetup[7]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetPassCommand, m_kSetup[8]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::DrawCommand, data);
			}

			void BufferedDrawingContext::DrawIndexed(unsigned length, unsigned start, unsigned vertexOffset)
			{
				CommandData data;
				data.Draw.Indexed = true;
				data.Draw.Length = length;
				data.Draw.Start = start;
				data.Draw.BaseVertex = vertexOffset;

				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetLayerCommand, m_kSetup[0]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetTopologyCommand, m_kSetup[1]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetBlendStateCommand, m_kSetup[2]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetRasterizerStateCommand, m_kSetup[3]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetInputLayoutCommand, m_kSetup[4]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetVertexBufferCommand, m_kSetup[5]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetIndexBufferCommand, m_kSetup[6]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetEffectParametersCommand, m_kSetup[7]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::SetPassCommand, m_kSetup[8]);
				this->m_pCurrent = this->InsertNode(this->m_pCurrent, CommandType::DrawCommand, data);
			}

			DrawingContext* BufferedDrawingContext::Clone()
			{
				return NULL;
			}

			void BufferedDrawingContext::Clear(const Color color)
			{
				memset(this->m_pStart, 0, sizeof(BufferedDrawingContext::CommandNode) * this->m_iCapacity); 

				this->m_iSize = 0; 

				this->m_pCurrent = &this->m_pStart[this->m_iSize++];
				this->m_pCurrent->Parent = NULL;
				this->m_pCurrent->Sibling = NULL;
				this->m_pCurrent->Next = NULL;
				this->m_pCurrent->Type = CommandType::NullCommand;
			}

			void BufferedDrawingContext::FlushLayer(CommandNode* node)
			{
				//printf("%d\n", node->Command.Layer);
				//bool printlayer = false;
				//if (node->Command.Layer == 98)
				//{
				//	printlayer = true;
				//}
				do
				{
					//printf("%p\n", node);
					
					//if (printlayer)
					//{
					//	printf("%d\n", node->Command.Layer);
					//	//if (node->Command.Layer > 10000) // arbitrary  number
					//		//break; // nasty hack
					//}

					// ISSUE: Is the layer supposed to give random results like 1, 3, 222620064, 222619784, etc?

					this->ExecuteCommand(node->Type, node->Command);
				}
				while((node = node->Next) != NULL && node->Type != CommandType::SetLayerCommand);
			}

					
			void BufferedDrawingContext::Flush()
			{
				DrawingContext::Clear(Camera::Get_Current()->Get_BackgroundColor());
				//{
					int pLayer = -1, cLayer = INT_MAX;
					BufferedDrawingContext::CommandNode* layerNode = NULL;
					BufferedDrawingContext::CommandNode* node = NULL;
					while(true)
					{
						cLayer = INT_MAX;
						layerNode = NULL;
						node = this->m_pStart->Child;
						while(node != NULL)
						{
							if((int)node->Command.Layer > pLayer && (int)node->Command.Layer < cLayer)
							{
								layerNode = node;
								cLayer = layerNode->Command.Layer;
							}

							node = node->Sibling;
						}

						if(layerNode == NULL)
							break;

						this->FlushLayer(layerNode);
						pLayer = layerNode->Command.Layer;
					}
				//}
				DrawingContext::Flush();
			}
			#pragma endregion
		}
	}
}