#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			class BufferedDrawingContext : public DrawingContext
			{
				private:
					#pragma region Nested Classes
					struct BLENDSTATE
					{
						D3D10_BLEND_DESC	Description;
						float				BlendFactors[4];
						unsigned			SampleMask;
					};

					struct VERTEXBUFFERSTATE
					{
						ID3D10Buffer*	Buffer;
						unsigned		Stride;
						unsigned		Offset;
					};

					struct INDEXBUFFERSTATE
					{
						ID3D10Buffer*	Buffer;
						DXGI_FORMAT 	Format;
						unsigned		Offset;
					};

					struct DRAWSTATE
					{
						bool		Indexed;
						unsigned	Length;
						unsigned	Start;
						unsigned	BaseVertex;
					};

					union CommandData
					{
						unsigned					Layer;
						D3D10_PRIMITIVE_TOPOLOGY	Topology;
						BLENDSTATE					BlendState;
						D3D10_RASTERIZER_DESC		RasterizerState;
						ID3D10InputLayout*			InputLayout;
						VERTEXBUFFERSTATE			Vertices;
						INDEXBUFFERSTATE			Indices;
						Material*					PassParameters;
						ID3D10EffectPass*			Pass;
						DRAWSTATE					Draw;

						CommandData() { memset(this, 0, sizeof(CommandData)); }
					};

					enum CommandType{ 
						NullCommand = 0, 
						SetLayerCommand = 1, 
						SetTopologyCommand = 2, 
						SetBlendStateCommand = 3, 
						SetRasterizerStateCommand = 4, 
						SetInputLayoutCommand = 5, 
						SetVertexBufferCommand = 6, 
						SetIndexBufferCommand = 7, 
						SetEffectParametersCommand = 8, 
						SetPassCommand = 9, 
						DrawCommand = 10 };

					struct CommandNode
					{
							#pragma region Variables
							CommandNode*		Parent;
							CommandNode*		Child;
							CommandNode*		Sibling;
							CommandNode*		Next;

							CommandType			Type;
							CommandData			Command;
							#pragma endregion
					};
					#pragma endregion

					#pragma region Variables
					unsigned			m_iCapacity;
					unsigned			m_iSize;

					CommandNode*		m_pStart;
					CommandNode*		m_pEnd;
					CommandNode*		m_pCurrent;

					CommandData			m_kSetup[9];
					#pragma endregion

					#pragma region Methods
					CommandNode* FindNode(CommandNode* start, CommandType type);
					CommandNode* InsertNode(CommandNode* start, CommandType type, CommandData command);
					void ExecuteCommand(CommandType type, CommandData data);

					void FlushLayer(CommandNode* node);
					#pragma endregion

				protected:
					#pragma region Overriden Methods
					void SetInputLayout(ID3D10InputLayout* inputlayout);

					void SetVertexBuffer(ID3D10Buffer* buffer, unsigned stride, unsigned start, unsigned length);

					void SetIndexBuffer(ID3D10Buffer* buffer, DXGI_FORMAT format, unsigned start, unsigned length);

					void SetMaterial(Material* material);

					void SetPass(ID3D10EffectPass* pass);

					void Draw(unsigned length, unsigned start);

					void DrawIndexed(unsigned length, unsigned start, unsigned vertexOffset);
					#pragma endregion

				public:
					#pragma region Constructors and Finalizers
					BufferedDrawingContext(unsigned capacity = SINGULARITY_RENDERER_DEFAULT_BUFFERED_CAPACITY);
					~BufferedDrawingContext();
					#pragma endregion

					#pragma region Methods
					void Combine(BufferedDrawingContext* context);
					#pragma endregion

					#pragma region Overriden Methods
					DrawingContext* Clone();

					void Clear(const Color color);
					
					void Flush();

					void SetLayer(unsigned layer);

					void SetRenderState(RenderState& renderstate);
					#pragma endregion
			};
		}
	}
}