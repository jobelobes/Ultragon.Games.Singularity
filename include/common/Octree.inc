#pragma region Constructors and Finalizers
template<class T>
Octree<T>::Octree(const Bounds& bounds, unsigned maxDepth, unsigned nodeLimit, unsigned capacity)
	: m_iNodeCapacity(0), m_iMaxDepth(maxDepth), m_iLimit(nodeLimit), m_iNodeCount(1), m_iCapacity(capacity), m_iCount(0), m_pValues(NULL)
{
	while(maxDepth-- > 0) this->m_iNodeCapacity += (unsigned)ceil((double)pow(8.0, (int)(maxDepth - 1)));
	this->m_pValues = (ListItem<T>*)calloc(this->m_iCapacity, sizeof(ListItem<T>));
	this->m_pNodes = (OctNode<T>*)calloc(this->m_iNodeCapacity, sizeof(OctNode<T>));
	this->m_pNodes[0].Depth = 0;
	this->m_pNodes[0].Bounds = Bounds(bounds);
	this->m_pNodes[0].Next = NULL;
}

template<class T>
Octree<T>::~Octree()
{
	if(this->m_pNodes){}
		//free(this->m_pNodes);
}
#pragma endregion

#pragma region Methods
template<class T>
void Octree<T>::_update(OctNode<T>* node)
{
	ListItem<T>* nextItem, *currItem;

	if(node->Children == NULL)
		return;

	nextItem = node->Values;
	currItem = node->Values;
	node->Values = NULL;
	node->Count = 0;

	while(nextItem != NULL)
	{
		currItem = nextItem;
		nextItem = nextItem->Next;

		this->_insert(currItem);
	}
}

template<class T>
void Octree<T>::_split(OctNode<T>* node)
{
	unsigned index, depth;
	OctNode<T>* child;
	Vector3 hSize, qSize, center;

	if(node->Depth == this->m_iMaxDepth)
		return;

	index = (int)::InterlockedExchangeAdd((LONG*)&this->m_iNodeCount, 8L);
	depth = node->Depth + 1;
	center = node->Bounds.Center;
	hSize = node->Bounds.Size * 0.5f;
	qSize = hSize * 0.5f;

	memset(&this->m_pNodes[index], 0, sizeof(OctNode<T>) * 8);

	node->Children = &this->m_pNodes[index];

	child = &node->Children[0];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x + qSize.x, center.y + qSize.y, center.z + qSize.z), hSize);
	child->Next = &node->Children[1];

	child = &node->Children[1];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x + qSize.x, center.y + qSize.y, center.z - qSize.z), hSize);
	child->Next = &node->Children[2];

	child = &node->Children[2];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x + qSize.x, center.y - qSize.y, center.z + qSize.z), hSize);
	child->Next = &node->Children[3];

	child = &node->Children[3];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x + qSize.x, center.y - qSize.y, center.z - qSize.z), hSize);
	child->Next = &node->Children[4];

	child = &node->Children[4];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x - qSize.x, center.y + qSize.y, center.z + qSize.z), hSize);
	child->Next = &node->Children[5];

	child = &node->Children[5];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x - qSize.x, center.y + qSize.y, center.z - qSize.z), hSize);
	child->Next = &node->Children[6];

	child = &node->Children[6];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x - qSize.x, center.y - qSize.y, center.z + qSize.z), hSize);
	child->Next = &node->Children[7];

	child = &node->Children[7];
	child->Parent = node;
	child->Depth = depth;
	child->Bounds = Bounds(Vector3(center.x - qSize.x, center.y - qSize.y, center.z - qSize.z), hSize);
	child->Next = node->Next;

	node->Next = &node->Children[0];

	this->_update(node);
}

template<class T>
OctNode<T>* Octree<T>::_find(OctNode<T>* node, const Bounds& bounds)
{
	unsigned minIndex, maxIndex;
	Vector3 min, max, diffMin, diffMax;

	min = bounds.Get_Min();
	max = bounds.Get_Max();

	while(node != NULL)
	{	
		if(!node->Bounds.Contains(min) || !node->Bounds.Contains(max))
			node = node->Parent;
		else if(node->Children == NULL)
			return node;
		else
		{
			diffMin = min - node->Bounds.Center;
			diffMax = max - node->Bounds.Center;

			minIndex = (diffMin.x < 0) << 2 | (diffMin.y < 0) << 1 | (diffMin.z < 0);
			maxIndex = (diffMax.x < 0) << 2 | (diffMax.y < 0) << 1 | (diffMax.z < 0);
			if(minIndex != maxIndex)
				return node;

			node = &node->Children[minIndex];
		}			
	}
	return node;
}

template<class T>
void Octree<T>::_insert(ListItem<T>* item)
{
	OctNode<T>* node = this->_find(&this->m_pNodes[0], item->Bounds);
	if(node == NULL)
		throw SingularityException("No node found that contains the provided bounds.");

	while(node->Count >= this->m_iLimit && node->Children == NULL && node->Depth < this->m_iMaxDepth)
	{
		this->_split(node);
		node = this->_find(node, item->Bounds);
	}

	item->Next = node->Values;
	item->Parent = node;

	node->Values = item;
	node->Count++;
}

template<class T>
void Octree<T>::insert(const Bounds& bounds, T value)
{
	unsigned index;
	ListItem<T>* item;

	if(this->m_iCount == this->m_iCapacity)
		throw SingularityException("The octree capacity has been reached.");

	index = (int)::InterlockedExchangeAdd((LONG*)&this->m_iCount, 1L);
	item = &this->m_pValues[index];
	item->Value = value;
	item->Next = NULL;
	item->Parent = NULL;
	item->Bounds = Bounds(bounds);

	this->_insert(item);
}

template<class T>
void Octree<T>::erase(T value)
{
	ListItem<T>* item;
	unsigned i;

	for(i = 0; i < this->m_iCount; ++i)
	{
		item = &this->m_pValues[i];
		if(item == NULL || item->Value != value)
			continue;

		::InterlockedDecrement((LONG*)&this->m_iCount);
		::InterlockedDecrement((LONG*)&item->Parent->Count);
		do
		{
			item->Value = item->Next->Value;
		}
		while((item = item->Next) != NULL);

		return;
	}
}
#pragma endregion