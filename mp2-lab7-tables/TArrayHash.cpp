#include "TArrayHash.h"
TArrayHash::TArrayHash(int _size, int _step) : mas(new TRecord[_size]), size(_size), step(_step)
{
	free.key = -1;
	del.key = -2;
	for (int i = 0; i < size; ++i)
	{
		mas[i] = free;
	}
}
TArrayHash::~TArrayHash() {	delete[] mas; }
int TArrayHash::GetSize() const { return size; }
const TRecord& TArrayHash::GetCurrentRecord() const
{
	/*if (!IsEnd() && !IsEmpty())
	{
		return mas[curr];
	}
	else
	{
//		throw std::exception();
		return TRecord();
	}*/
	return mas[curr];
}
bool TArrayHash::Find(TKey key) const
{
	int pos = HashFunc(key) % size, delpos = -1;
	bool res = false;
	for (int i = 0; i < size; ++i, ++eff)
	{
		if (mas[pos] == free)
		{
			curr = pos;
			break;
		}
		else if (mas[pos].key == key)
		{
			curr = pos;
			res = true;
			break;
		}
		else if (mas[pos] == del && delpos == -1)
		{
			delpos = pos;
			curr = pos;
		}
		pos = (pos + step) % size;
	}
	if (delpos != -1 && res == false)
	{
		curr = delpos;
	}
	return res;
}
bool TArrayHash::Insert(TRecord rec)
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
bool TArrayHash::Delete(TKey key)
{
	if (IsEmpty() || !Find(key))
		return false;
	mas[curr] = del;
	--dataCount;
	++eff;
	return true;
}
void TArrayHash::Reset() const
{
	curr = 0;
	while (curr < dataCount && (mas[curr].key == -1 || mas[curr].key == -2))
	{
		++curr;
	}
}
void TArrayHash::GoNext() const
{
	if (!(mas[curr] == del) && !(mas[curr] == free))
	{
		++curr;
	}

	while (mas[curr] == del || mas[curr] == free)
	{
		++curr;
	}
	/*while (!IsEnd() && mas[curr].key == -1)
	{
		++curr;
	}*/
}
bool TArrayHash::IsFull() const
{
	return dataCount == size;
}
bool TArrayHash::IsEnd() const
{
	return curr == dataCount;
}
