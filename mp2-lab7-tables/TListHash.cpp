#include "TListHash.h"
TListHash::TListHash(int _size) : mas(_size), size(_size) {}
int TListHash::GetSize() const { return size; }
bool TListHash::IsFull() const { return dataCount == size; }
bool TListHash::Find(TKey key) const
{
	int pos = HashFunc(key) % size;
	bool res = false;
	currList = pos;
	++eff;
	if (mas[pos].empty())
	{
		pCurr = mas[pos].cbegin();
	}
	else
	{
		for (pCurr = mas[pos].cbegin(); pCurr != mas[pos].cend(); ++pCurr, ++eff) 
		{
			if (pCurr->key == key)
			{
				res = true;
				break;
			}
		}
	}
	return res;
}
bool TListHash::Insert(TRecord rec) 
{
	if (Find(rec.key) || IsFull())
		return false;
	eff += mas[currList].size() + 1;
	pCurr = mas[currList].insert(pCurr, rec);
	++dataCount;
	return true;
}
bool TListHash::Delete(TKey key) 
{
	if (!Find(key) || IsEmpty())
		return false;
	pCurr = mas[currList].erase(pCurr);
	--dataCount;
	++eff;
	return true;
}
void TListHash::Reset() const 
{
	currList = 0;
	pCurr = decltype(pCurr){};
	while (currList < size && mas[currList].empty())
	{
		++currList;
	}
	if (currList < size)
	{
		pCurr = mas[currList].cbegin();
	}
}
void TListHash::GoNext() const 
{
	++pCurr;
	if (pCurr == mas[currList].cend())
	{
		++currList;
		while (currList < size && mas[currList].empty())
		{
			++currList;
		}
		if (currList < size)
		{
			pCurr = mas[currList].cbegin();
		}
	}
}
bool TListHash::IsEnd() const
{
	return currList == size;
}
const TRecord& TListHash::GetCurrentRecord() const
{
	if (IsEmpty() || IsEnd())
	{
		throw std::exception("Table is empty\n");
	}
	else
	{
		return *pCurr;
	}
}