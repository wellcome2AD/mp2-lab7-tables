#include "TScanTable.h"
TScanTable::TScanTable(int _size) : TArrayTable(_size) {}
bool TScanTable::Find(TKey key) const
{
	for (int i = 0; i < dataCount; ++i, ++eff)
	{
		if (mas[i].key == key)
		{
			curr = i;
			return true;
		}
	}
	curr = dataCount;
	return false;
}
bool TScanTable::Insert(TRecord rec)
{
	if (IsFull() || Find(rec.key))
	{
		return false;
	}
	mas[curr] = rec;
	++dataCount;
	++eff;
	return true;
}
bool TScanTable::Delete(TKey key)
{
	if (IsEmpty() || !Find(key))
		return false;
	mas[curr] = mas[dataCount - 1];
	--dataCount;
	++eff;
	return true;
}