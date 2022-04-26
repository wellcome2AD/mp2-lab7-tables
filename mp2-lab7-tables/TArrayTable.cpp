#include "TArrayTable.h"
TArrayTable::TArrayTable(int _size) : mas(new TRecord[_size]), size(_size), curr(0) {}
TArrayTable::~TArrayTable() { delete[] mas; }
TRecord TArrayTable::GetCurrentRecord() const 
{ 
	if (!IsEnd() && !IsEmpty())
		return mas[curr];
	else
		return TRecord(curr);
}
int TArrayTable::GetSize() const { return size; }
bool TArrayTable::IsFull() const { return dataCount == size; }
void TArrayTable::Reset() const { curr = 0; }
void TArrayTable::GoNext() const { ++curr; }
bool TArrayTable::IsEnd()  const { return curr == dataCount; }