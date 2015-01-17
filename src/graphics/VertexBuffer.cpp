#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Graphics, VertexBuffer, Singularity::Object);

		#pragma region Constructors and Finalizers
		VertexBuffer::VertexBuffer(VertexDeclaration* vertexDeclaration, unsigned length)
		{
			this->m_pInternal = InternalVertexBuffer::GetInstance(vertexDeclaration);
			if(this->m_pInternal == NULL)
				throw SingularityException("Unable to create vertex buffer.");

			this->m_iLength = length;
			this->m_iStart = this->m_pInternal->AllocateData(this->m_iLength);
			this->m_pBuffer = calloc(this->m_iLength, this->m_pInternal->m_pDeclaration->Get_SizeInBytes());
		}

		VertexBuffer::~VertexBuffer(){}
		#pragma endregion

		#pragma region Methods
		void VertexBuffer::SetData(void* data)
		{
			memcpy(this->m_pBuffer, data, this->m_iLength * this->m_pInternal->m_pDeclaration->Get_SizeInBytes());
			this->m_pInternal->SetData(data, this->m_iStart, this->m_iLength);
		}

		void* VertexBuffer::GetData(bool force)
		{
			return this->m_pBuffer;
		}
		#pragma endregion
	}
}