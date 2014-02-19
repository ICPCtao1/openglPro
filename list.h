
template<class T> class listManager;

template<class T>
class listItem
{
public:
	listItem()
	{
		Reset();
	}

	friend class listManager<T>;
protected:
	void Reset()
	{
		m_pNextItem = NULL;
		m_pPreItem = NULL;
	}
private:
	typedef T* ListItemP;
	ListItemP m_pNextItem;
	ListItemP m_pPreItem;
};


template<class T>
class listManager
{
public:
	typedef T* ListItemP;
	typedef T ListItem;
	listManager()
	{
		Reset();
	}

	~listManager()
	{

	}

	void AddTailItem(ListItem* pItem)
	{
		if(NULL == pItem)
			return;
		if (NULL == m_pTailItem)
		{
			m_pTailItem = pItem;
			m_pHeadItem = pItem;
		}
		else
		{
			m_pTailItem->m_pNextItem = pItem;
			pItem->m_pPreItem = m_pTailItem;
			m_pTailItem = pItem;
		}
		m_nItemNum += 1;
	}
	ListItemP GetHead()
	{
		return m_pHeadItem;
	}
	ListItemP GetNextItem(ListItem* pItem)
	{
		if (NULL != pItem)
		{
			return pItem->m_pNextItem;
		}
		return NULL;
	}
	bool IsTailItem(ListItem* pItem)
	{
		if (NULL == pItem || NULL == pItem->m_pNextItem)
		{
			return true;
		}
		return false;
	}

protected:
	void Reset()
	{
		m_pTailItem = NULL;
		m_pHeadItem = NULL;
		m_nItemNum = 0;
	}

protected:
	ListItem* m_pTailItem;
	ListItem* m_pHeadItem;
	unsigned int m_nItemNum;

};
