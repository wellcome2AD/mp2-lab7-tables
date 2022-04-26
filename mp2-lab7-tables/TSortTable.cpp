#include "TSortTable.h"
#include <algorithm>
void TSortTable::QSort(int s, int f)
{
	int s1 = s, f1 = f;
	int k = (s + f) / 2;
	TKey mid = mas[k].key;
	while (s1 < f1)
	{
		while (mas[s1].key < mid)
		{
			++s;
			++eff;
		}
		while (mas[f1].key > mid)
		{
			--f1;
			++eff;
		}
		if (s1 <= f1)
		{
			std::swap(mas[s1], mas[f1]);
			++s1;
			--f1;
		}
	}
	if (s < f1)
	{
		QSort(s, f1);
	}
	if (s1 < f)
	{
		QSort(s1, f);
	}
;}
void TSortTable::Sort()
{
	QSort(0, dataCount);
}
TSortTable::TSortTable(int _size) : TArrayTable(_size) {}
TSortTable::TSortTable(const TScanTable& st) : TArrayTable(st.GetSize())
{
	st.Reset();
	for (int i = 0; i < st.GetDataCount(); ++i, st.GoNext())
	{
		mas[i] = st.GetCurrentRecord();
	}
	Sort();
}
bool TSortTable::Find(TKey key) const
{
	int left = 0, right = dataCount - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mas[mid].key > key)
		{
			right = mid - 1;
		}
		else if (mas[mid].key < key)
		{
			left = mid + 1;
		}
		else 
		{
			curr = mid;
			++eff;
			return true;
		}
	}
	curr = left;
	return false;
}
bool TSortTable::Insert(TRecord rec)
{
	if (IsFull() || Find(rec.key))
	{
		return false;
	}
	for (int i = dataCount; i > curr; i--)
	{
		mas[i] = mas[i - 1];
	}
	++dataCount;
	mas[curr] = rec;
	++eff;
	return true;
}
bool TSortTable::Delete(TKey key)
{
	if (!Find(key))
	{
		return false;
	}
	for (int i = curr; i < dataCount - 1; ++i, ++eff)
	{
		mas[i] = mas[i + 1];
	}
	--dataCount;
	return true;
}