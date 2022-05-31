#pragma once
#include <vector>
#include <list>
#include <iterator>
#include "THashTable.h"
class TListHash : public THashTable
{
	std::vector<std::list<TRecord>> mas; // ?
	int size;
	mutable int currList = 0; // номер списка
	mutable std::list<TRecord>::const_iterator pCurr; // указатель на звено
public:
	TListHash(int _size = 100);
	int GetSize() const override;
	bool IsFull() const override;
	bool Find(TKey) const override;
	bool Insert(TRecord) override;
	bool Delete(TKey) override;
	void Reset() const override;
	void GoNext() const override;
	bool IsEnd() const override;
	const TRecord& GetCurrentRecord() const override;
};

