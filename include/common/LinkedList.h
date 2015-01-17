#include "common\Singularity.Common.h"

namespace Singularity
{
	template<class T>
	class LinkedList
	{
		private:
			#pragma Nested Classes
			struct Node { ListNode* Previous; ListNode* Next; T Value; };
			#pragma endregion

			#pragma region Variables
			unsigned		m_iCapacity;
			unsigned		m_iCount;
			Node*			m_pValues;
			Node*			m_pStart;
			Node*			m_pEnd;
			#pragma endregion

			#pragma region Methods
			Node* _FindNode(T value);
			Node* _InternalPush(T value);
			void _InternalRemove(Node*);
			#pragma endregion

		public:
			#pragma region Properties
			inline const unsigned Get_Size() const{ return this->m_iCount; };
			#pragma endregion

			#pragma region Constructors and Finalizers
			LinkedList(unsigned capacity = 1024);
			~LinkedList();
			#pragma endregion

			#pragma region Methods
			void Push(T value);
			T Pop();

			void Insert(T value, unsigned index);
			T Remove(unsigned index);
			#pragma endregion

			friend class Octree;
	};

	#pragma region Constructors and Finalizers
	LinkedList<T>::LinkedList(unsigned capacity = 1024);
	LinkedList<T>::~LinkedList();
	#pragma endregion

	#pragma region Methods
	Node* LinkedList<T>::_FindNode(T value)
	{
		Node* node = &this->m_pStart;
		while(node != NULL)
		{
			if(node->Value == value)
				return node;

			node = node->Next;
		}

		return NULL;
	}

	Node* LinkedList<T>::_InternalPush(T value)
	{
		unsigned = index;
		Node* node;

		if(this->m_iCount == this->m_iCapacity)
			throw SingularityException("");

		index = ::InterlockedIncrement((LONG*)&this->m_iCount) - 1;
		node = &this->m_pValues[index];
		node->Previous = this->m_pEnd;
		node->Next = NULL;
		node->Value = value;

		this->m_pEnd = node;

		return node;
	}

	void LinkedList<T>::_InternalRemove(Node* node)
	{
		
	}

	inline void LinkedList<T>::Push(T value)
	{
		this->_InternalPush(value);
	}

	inline T LinkedList<T>::Pop()
	{

	}

	void LinkedList<T>::Insert(T value, unsigned index)
	{

	}

	T LinkedList<T>::RemoveAt(unsigned index)
	{

	}
	#pragma endregion
}