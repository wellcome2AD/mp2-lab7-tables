#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include "TTreeTable.h"

class AVLTreeTable : public TTreeTable
{
	static int height(TNode* p);
	static int bfactor(TNode* p);
	static void fixheight(TNode* p);
	static TNode* rotateRight(TNode* p);
	static TNode* rotateleft(TNode* q);
	static TNode* balance(TNode* p);
	TNode* insert(TNode* p, TRecord rec);
	TNode* findMin(TNode* p);
	TNode* removeMin(TNode* p);
	TNode* remove(TNode* p, TKey k);

	bool operationResult = false;
public:
	bool Insert(TRecord rec);
	bool Delete(TKey key);
};
