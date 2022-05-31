#include "TScanTable.h"
#include "TSortTable.h"
#include "TArrayHash.h"
#include "TListHash.h"
#include "TTreeTable.h"
#include "TBalTree.h"
#include <cassert>
#include <iostream>

int main()
{
	int tree_size = -1;
	TBalTree ah;
	TTable& table = ah;
	assert(table.GetDataCount() == 0);
	TRecord empty_rec;
	try
	{
		empty_rec = table.GetCurrentRecord();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
	assert(table.GetEffectiveness() == 0);
	assert(table.GetSize() == tree_size);
	assert(table.IsEmpty() == true);
	assert(table.IsFull() == false);
	TRecord rec_array[10];
	std::vector<int> keys = { 6, 4, 10, 8, 12, 11 };
	int size = keys.size();
	for (int i = 0; i < size; ++i)
	{
		rec_array[i] = TRecord(keys[i], std::string());
		if (i == 5)
			bool is_here = true;
		table.Insert(rec_array[i]);
	}
	std::cout << dynamic_cast<TBalTree&>(table);
	return 0;
}
