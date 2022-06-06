/*#include "TScanTable.h"
#include "TSortTable.h"
#include "TArrayHash.h"
#include "TListHash.h"
#include "TTreeTable.h"
*/
//#include "TBalTree.h"
#include <cassert>
#include <iostream>
#include <vector>
#include "AVLTreeTable.h"

int main()
{
	AVLTreeTable table;
	//TBalTree table;
	std::vector<int> keys = { 6, 3, 9, 12, 43, 0, 8, 2, 5, 1, 7, 23, 52, 30, 14, 17 };
	for (int i = 0; i < keys.size(); ++i)
	{
		TRecord rec(keys[i], std::string("Record#") + std::to_string(keys[i]));
		table.Insert(rec);
	}
	std::cout << table;
	return 0;
}
