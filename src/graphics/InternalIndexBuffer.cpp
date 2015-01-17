#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Static Variables
		DynamicList<InternalIndexBuffer*> InternalIndexBuffer::g_pBuffers;
		#pragma endregion

		#pragma region Constructors and Finalizers
		InternalIndexBuffer::InternalIndexBuffer(ID3D10Device* device, unsigned capacity)
			: m_pDevice(device), m_iBuffer(NULL), m_iLength(0), m_iCapacity(capacity), m_iStride(sizeof(unsigned))
		{
			HRESULT hr;
			D3D10_BUFFER_DESC bd;

			bd.Usage = D3D10_USAGE_DYNAMIC;
			bd.ByteWidth = this->m_iCapacity * this->m_iStride;
			bd.BindFlags = D3D10_BIND_INDEX_BUFFER;
			bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
			bd.MiscFlags = 0;

			// create a new buffer
			hr = this->m_pDevice->CreateBuffer(&bd, NULL, &this->m_iBuffer);
			if(FAILED(hr))
				throw SingularityException("Unable to create index buffer.", hr);
		}

		InternalIndexBuffer::~InternalIndexBuffer()
		{
			if(this->m_iBuffer != NULL)
				this->m_iBuffer->Release();
		}
		#pragma endregion

		#pragma region Methods
		unsigned InternalIndexBuffer::AllocateData(unsigned length)
		{
			unsigned startIndex;
			char* newBufferData;
			char* oldBufferData;
			ID3D10Buffer* buffer;
			D3D10_BUFFER_DESC bd;
			
			if((length + this->m_iLength) > this->m_iCapacity)
			{
				// allocate a new device buffer
				bd.Usage = D3D10_USAGE_DYNAMIC;
				bd.ByteWidth = (this->m_iLength + length) * this->m_iStride;
				bd.BindFlags = D3D10_BIND_INDEX_BUFFER;
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
				memcpy(newBufferData, oldBufferData, this->m_iLength * this->m_iStride);

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

		void InternalIndexBuffer::SetData(void* data, unsigned start, unsigned length)
		{
			char* bufferData;

			if(this->m_iBuffer == NULL)
				throw SingularityException("Unable to map the data to core memory space.");
			if(FAILED(this->m_iBuffer->Map(D3D10_MAP_WRITE_NO_OVERWRITE, 0, (void**)&bufferData)))
				throw SingularityException("Unable to write to the core memory buffer space.");

			memcpy(bufferData + start * this->m_iStride, data, length * this->m_iStride);
			this->m_iBuffer->Unmap();
		}
		#pragma endregion

		#pragma region Static Methods
		InternalIndexBuffer* InternalIndexBuffer::GetInstance(int capacity)
		{
			InternalIndexBuffer* buffer;
			if(!InternalIndexBuffer::g_pBuffers.size())
			{
				buffer = new InternalIndexBuffer(Singularity::Graphics::Devices::HardwareDevice::Instance->m_pDevice, capacity);
				InternalIndexBuffer::g_pBuffers.push_back(buffer);
				return buffer;
			}

			return InternalIndexBuffer::g_pBuffers[0];
		}
		#pragma endregion
	}
}