#include "TScanTable.h"
#include "TSortTable.h"
#include "TArrayHash.h"
#include <cassert>
#include <iostream>

int main()
{
	int size = 10;
	TArrayHash ah(size);
	TTable& table = ah;
	assert(table.GetDataCount() == 0);
	TRecord empty_rec = table.GetCurrentRecord();
	assert(empty_rec.key == 0);
	assert(table.GetEffectiveness() == 0);
	assert(table.GetSize() == size);
	assert(table.IsEmpty() == true);
	assert(table.IsFull() == false);
	TRecord rec_array[10];
	for (int i = 0; i < size; i++)
	{
		rec_array[i] = TRecord(i, std::string());
		table.Insert(rec_array[i]);
	}
	assert(table.IsEmpty() == false);
	assert(table.IsFull() == true);
	assert(table.Find(TKey(11)) == false);
	table.Find(TKey(5));
	assert(table.GetCurrentRecord().key == rec_array[5].key && table.GetCurrentRecord().value == rec_array[5].value);
	assert(table.Insert(rec_array[2]) == false);
	assert(table.Delete(TKey(11)) == false);
	table.Delete(TKey(2));
	assert(table.Insert(rec_array[2]) == true);
	return true;
}
