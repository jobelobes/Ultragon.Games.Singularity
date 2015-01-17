#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		DynamicList<InternalVertexBuffer*> InternalVertexBuffer::g_pBuffers;
		#pragma endregion

		#pragma region Constructors and Finalizers
		InternalVertexBuffer::InternalVertexBuffer(ID3D10Device* device, VertexDeclaration* vertexDeclaration, unsigned capacity)
			: m_pDevice(device), m_iBuffer(NULL), m_iLength(0), m_iCapacity(capacity), m_pDeclaration(vertexDeclaration)
		{
			D3D10_BUFFER_DESC bd;
			bd.Usage = D3D10_USAGE_DYNAMIC;
			bd.ByteWidth = this->m_iCapacity * this->m_pDeclaration->Get_SizeInBytes();
			bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
			bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
			bd.MiscFlags = 0;

			// create a new buffer
			this->m_pDevice->CreateBuffer(&bd, NULL, &this->m_iBuffer);
		}

		InternalVertexBuffer::~InternalVertexBuffer()
		{
			if(this->m_iBuffer)
				this->m_iBuffer->Release();
		}
		#pragma endregion

		#pragma region Methods
		unsigned InternalVertexBuffer::AllocateData(unsigned length)
		{
			unsigned startIndex;
			unsigned stride;
			char* newBufferData;
			char* oldBufferData;
			ID3D10Buffer* buffer;
			D3D10_BUFFER_DESC bd;

			stride = this->m_pDeclaration->Get_SizeInBytes();

			if((length + this->m_iLength) > this->m_iCapacity)
			{
				// allocate a new device buffer
				bd.Usage = D3D10_USAGE_DYNAMIC;
				bd.ByteWidth = (this->m_iLength + length) * stride;
				bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
				bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
				bd.MiscFlags = 0;

				// create a new buffer
				this->m_pDevice->CreateBuffer(&bd, NULL, &buffer);

				// attempt to open up the buffers for reading("mapping")
				if(FAILED(this->m_iBuffer->Map(D3D10_MAP_WRITE_NO_OVERWRITE, 0, (void**)&oldBufferData)))
					throw SingularityException("Unable to write to the core memory buffer space.");
				if(FAILED(buffer->Map(D3D10_MAP_WRITE_DISCARD, 0, (void**)&newBufferData)))
					throw SingularityException("Unable to write to the core memory buffer space.");

				//copy all of the old data into the new buffer
				memcpy(newBufferData, oldBufferData, this->m_iLength * stride);

				// unmap the buffers
				this->m_iBuffer->Unmap();
				buffer->Unmap();

				// release the old buffer
				this->m_iBuffer->Release();

				// set the variables to the new buffer;
				this->m_iBuffer = buffer;
				this->m_iCapacity = this->m_iLength + length;
			}

			// return the start index and increment the used count
			startIndex = this->m_iLength;
			this->m_iLength += length;

			return startIndex;
		}

		void InternalVertexBuffer::SetData(void* data, unsigned start, unsigned length)
		{
			char* bufferData;
			unsigned stride;

			if(this->m_iBuffer == NULL)
				throw SingularityException("Unable to map the data to core memory space.");
			if(FAILED(this->m_iBuffer->Map(D3D10_MAP_WRITE_NO_OVERWRITE, 0, (void**)&bufferData)))
				throw SingularityException("Unable to write to the core memory buffer space.");

			stride = this->m_pDeclaration->Get_SizeInBytes();
			memcpy(bufferData + start * stride, data, length * stride);
			this->m_iBuffer->Unmap();
		}
		#pragma endregion

		#pragma region Static Methods
		InternalVertexBuffer* InternalVertexBuffer::GetInstance(VertexDeclaration* vertexDeclaration, int capacity)
		{
			unsigned size;
			unsigned index;
			InternalVertexBuffer* buffer;

			size = InternalVertexBuffer::g_pBuffers.size();
			for(index = 0; index < size; index++)
			{
				if(InternalVertexBuffer::g_pBuffers[index]->m_pDeclaration->Equals(vertexDeclaration))
					return InternalVertexBuffer::g_pBuffers[index];
			}

			buffer = new InternalVertexBuffer(Singularity::Graphics::Devices::HardwareDevice::Instance->m_pDevice, vertexDeclaration, capacity);
			InternalVertexBuffer::g_pBuffers.push_back(buffer);
			return buffer;
		}
		#pragma endregion
	}
}