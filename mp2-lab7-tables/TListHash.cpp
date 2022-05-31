#include "TListHash.h"
TListHash::TListHash(int _size) : mas(_size), size(_size) {}
int TListHash::GetSize() const { return size; }
bool TListHash::IsFull() const { return dataCount == size; }
bool TListHash::Find(TKey key) const
{
	int pos = HashFunc(key) % size;
	bool res = false;
	currList = pos;
	if (mas[pos].empty())
	{
		pCurr = mas[pos].cbegin();
	}
	else
	{
		for (pCurr = mas[pos].cbegin(); pCurr != mas[pos].cend(); ++pCurr)
		{
			if (pCurr->key == key)
			{
				++eff;
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
	pCurr = mas[currList].insert(pCurr, rec);
	++dataCount;
	++eff;
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
	pCurr = mas[currList].cbegin();
}
void TListHash::GoNext() const 
{
	if (pCurr != mas[currList].cend())
	{
		++pCurr;
	}
	else
	{
		++currList;
		if(currList < size)
			pCurr = mas[currList].cbegin();
	}
}
bool TListHash::IsEnd() const
{
	return currList == size;
}
TRecord TListHash::GetCurrentRecord() const 
{
	if (IsEmpty() || IsEnd())
		return TRecord();
	else
		return *pCurr; 
}