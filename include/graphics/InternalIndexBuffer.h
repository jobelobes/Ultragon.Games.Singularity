#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class IndexBuffer;

		class InternalIndexBuffer
		{
			private:
				#pragma region Static Variables
				static DynamicList<InternalIndexBuffer*> g_pBuffers;
				#pragma endregion

				#pragma region Variables
				unsigned			m_iLength;
				unsigned			m_iCapacity;
				unsigned			m_iStride;

				ID3D10Buffer*		m_iBuffer;
				ID3D10Device*		m_pDevice;
				#pragma endregion

				#pragma region Methods
				unsigned AllocateData(unsigned count);
				void SetData(void* data, unsigned start, unsigned length);
				#pragma endregion

				#pragma region Constructors and Finalizers
				InternalIndexBuffer(ID3D10Device* device, unsigned capacity);
				~InternalIndexBuffer();
				#pragma endregion

				#pragma region Static Methods
				static InternalIndexBuffer* GetInstance(int capacity = 256);
				#pragma endregion

				friend class IndexBuffer;
				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
		};
	}
}