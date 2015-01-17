#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, IndexBuffer, Singularity::Object);

		#pragma region Constructors and Finalizers
		IndexBuffer::IndexBuffer(unsigned length)
		{
			this->m_pInternal = InternalIndexBuffer::GetInstance();
			if(this->m_pInternal == NULL)
				throw SingularityException("Unable to create index buffer.");

			this->m_iLength = length;
			this->m_iStart = this->m_pInternal->AllocateData(this->m_iLength);
			this->m_pBuffer = calloc(this->m_iLength, sizeof(unsigned));
		}

		IndexBuffer::~IndexBuffer(){}
		#pragma endregion

		#pragma region Methods
		void IndexBuffer::SetData(void* data)
		{
			this->m_pInternal->SetData(data, this->m_iStart, this->m_iLength);
			memcpy(this->m_pBuffer, data, this->m_iLength * sizeof(unsigned));
		}

		void* IndexBuffer::GetData(bool force)
		{
			return this->m_pBuffer;
		}
		#pragma endregion
	}
}