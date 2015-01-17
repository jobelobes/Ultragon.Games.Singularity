#include "common\Singularity.Common.h"

namespace Singularity
{
	template<class T>
	class OctreeIterator
	{
		private:
			#pragma region Variables
			Bounds			m_kBounds;
			Octree<T>*		m_pTree;
			OctNode<T>*		m_pCurrentNode;
			ListItem<T>*	m_pCurrentItem;
			#pragma endregion

			#pragma region Methods
			bool _Intersects(OctNode<T>* node, const Bounds& bounds);
			#pragma endregion

		public:
			#pragma region Methods
			OctNode<T>* Get_CurrentNode() const { return this->m_pCurrentNode; };
			#pragma endregion

			#pragma region Constructors and Finalizers
			OctreeIterator(Octree<T>* octree);
			~OctreeIterator();
			#pragma endregion

			#pragma region Methods
			void ResetBounds(const Bounds& bounds);
			void Reset();
			bool Next(T& value);
			#pragma endregion
	};

	#pragma region Constructors and Finalizers
	template<class T>
	OctreeIterator<T>::OctreeIterator(Octree<T>* octree)
		: m_pTree(octree), m_kBounds(octree->m_pNodes[0].Bounds), m_pCurrentNode(NULL), m_pCurrentItem(NULL)
	{
		this->m_pCurrentNode = &this->m_pTree->m_pNodes[0];
		this->m_pCurrentItem = this->m_pCurrentNode->Values;
	}
	
	template<class T>
	OctreeIterator<T>::~OctreeIterator() { }
	#pragma endregion

	#pragma region Methods
	template<class T>
	bool OctreeIterator<T>::_Intersects(OctNode<T>* node, const Bounds& bounds)
	{
		Vector3 min, max;
		
		min = node->Bounds.Get_Min();
		max = bounds.Get_Max();
		if(min.x > max.x || min.y > max.y || min.z > max.z) return false;

		min = bounds.Get_Min();
		max = node->Bounds.Get_Max();
		if(min.x > max.x || min.y > max.y || min.z > max.z) return false;
		return true;
	}

	template<class T>
	void OctreeIterator<T>::ResetBounds(const Bounds& bounds)
	{
		Vector3 min, max, tVal;
		tVal = this->m_pTree->m_pNodes[0].Bounds.Get_Min();
		min = bounds.Get_Min();
		min.x = tVal.x > min.x ? tVal.x : min.x;
		min.y = tVal.y > min.y ? tVal.y : min.y;
		min.z = tVal.z > min.z ? tVal.z : min.z;

		tVal = this->m_pTree->m_pNodes[0].Bounds.Get_Max();
		max = bounds.Get_Max();
		max.x = tVal.x < max.x ? tVal.x : max.x;
		max.y = tVal.y < max.y ? tVal.y : max.y;
		max.z = tVal.z < max.z ? tVal.z : max.z;

		this->m_kBounds.SetMinMax(min, max);
		this->m_pCurrentNode = this->m_pTree->_FindContains(&this->m_pTree->m_pNodes[0], this->m_kBounds);
		this->m_pCurrentItem = this->m_pCurrentNode->Values;
	}

	template<class T>
	void OctreeIterator<T>::Reset()
	{
		this->m_pCurrentNode = &this->m_pTree->m_pNodes[0];
		this->m_pCurrentItem = this->m_pCurrentNode->Values;
	}

	template<class T>
	bool OctreeIterator<T>::Next(T& value)
	{
		while(this->m_pCurrentItem == NULL && this->m_pCurrentNode != NULL)
		{
			this->m_pCurrentNode = this->m_pCurrentNode->Next;
			if(this->m_pCurrentNode != NULL && this->_Intersects(this->m_pCurrentNode, this->m_kBounds))
				this->m_pCurrentItem = this->m_pCurrentNode->Values;
		}

		if(this->m_pCurrentItem == NULL)
			return false;

		value = this->m_pCurrentItem->Value;
		this->m_pCurrentItem = this->m_pCurrentItem->Next;
		return true;
	}
	#pragma endregion
}