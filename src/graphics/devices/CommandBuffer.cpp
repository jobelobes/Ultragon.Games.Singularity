#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			#pragma region Constructors and Finalizers
			CommandBuffer::CommandBuffer(unsigned capacity)
				: m_iCapacity(capacity), m_iSize(0), m_pStart(NULL), m_pEnd(NULL)
			{
				this->m_pStart = (CommandNode*)malloc(sizeof(CommandNode) * this->m_iCapacity);
				this->Reset();
			}

			CommandBuffer::~CommandBuffer()
			{
				if(this->m_pStart != NULL)
					delete [] this->m_pStart;
			}
			#pragma endregion
				
			#pragma region Methods	
			CommandNode* CommandBuffer::FindNode(CommandNode* start, CommandType type)
			{
				CommandNode* node;

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

			CommandNode* CommandBuffer::InsertNode(CommandNode* start, CommandType type, CommandData command)
			{
				CommandNode* parent;
				CommandNode* node;

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
					if(this->m_iSize >= this->m_iCapacity)
						throw SingularityException("Unable to add new node, the capacity has been reached.");

					node = &this->m_pStart[this->m_iSize++];
					node->Parent = parent;
					node->Sibling = parent->Child;
					node->Next = (node->Sibling == NULL) ? parent->Next : node->Sibling;
					node->Type = type;
					node->Command = command;

					parent->Next = node;
					parent->Child = node;
				}
				return node;
			}

			void CommandBuffer::Reset() 
			{ 
				memset(this->m_pStart, 0, sizeof(CommandNode) * this->m_iCapacity); 

				this->m_iSize = 0; 

				this->m_pStart = &this->m_pStart[this->m_iSize++];
				this->m_pStart->Parent = NULL;
				this->m_pStart->Sibling = NULL;
				this->m_pStart->Next = NULL;
				this->m_pStart->Type = CommandType::NullCommand;
				this->m_pEnd = this->m_pStart;
			}

			void CommandBuffer::Combine(CommandBuffer* buffer)
			{


			}
			#pragma endregion
		}
	}
}