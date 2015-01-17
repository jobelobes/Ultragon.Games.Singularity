#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class VertexBuffer;

		class InternalVertexBuffer
		{
			private:
				#pragma region Static Variables
				static DynamicList<InternalVertexBuffer*> g_pBuffers;
				#pragma endregion

				#pragma region Variables
				unsigned					m_iLength;
				unsigned					m_iCapacity;
				VertexDeclaration*			m_pDeclaration;

				ID3D10Buffer*				m_iBuffer;
				ID3D10Device*				m_pDevice;
				#pragma endregion

				#pragma region Methods
				unsigned AllocateData(unsigned count);
				void SetData(void* data, unsigned start, unsigned length);
				#pragma endregion

				#pragma region Constructors and Finalizers
				InternalVertexBuffer(ID3D10Device* device, VertexDeclaration* vertexDeclaration, unsigned capacity);
				~InternalVertexBuffer();
				#pragma endregion

				#pragma region Static Methods
				static InternalVertexBuffer* GetInstance(VertexDeclaration* vertexDeclaration, int capacity = 256);
				#pragma endregion

				friend class VertexBuffer;
				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
		};
	}
}