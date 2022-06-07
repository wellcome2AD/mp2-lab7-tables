#include "AVLTreeTable.h"
#include <iostream>
#include <cassert>
#include <stack>
#include <string>
int AVLTreeTable::height(TNode* p)
{
	return p != nullptr ? p->_height : 0;
}
int AVLTreeTable::bfactor(TNode* p)
{
	assert(p != nullptr);
	return height(p->pR) - height(p->pL);
}
void  AVLTreeTable::fixheight(TNode* p)
{
	int hl = height(p->pL);
	int hr = height(p->pR);
	p->_height = (hl > hr ? hl : hr) + 1;
}
TNode* AVLTreeTable::rotateRight(TNode* p)
{
	TNode* q = p->pL;
	p->pL = q->pR;
	q->pR = p;
	fixheight(p);
	fixheight(q);
	return q;
}
TNode* AVLTreeTable::rotateleft(TNode* q)
{
	TNode* p = q->pR;
	q->pR = p->pL;
	p->pL = q;
	fixheight(q);
	fixheight(p);
	return p;
}
TNode* AVLTreeTable::balance(TNode* p)
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->pR) < 0)
			p->pR = rotateRight(p->pR);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->pL) > 0)
			p->pL = rotateleft(p->pL);
		return rotateRight(p);
	}
	return p;
}
TNode* AVLTreeTable::insert(TNode* p, TRecord rec)
{
	++eff;
	if (p == nullptr)
	{
		operationResult = true;
		return new TNode(rec);
	}
	if (rec.key < p->rec.key)
		p->pL = insert(p->pL, rec);
	else
		p->pR = insert(p->pR, rec);
	return balance(p);
}
TNode* AVLTreeTable::findMin(TNode* p)
{
	++eff;
	return p->pL ? findMin(p->pL) : p;
}
TNode* AVLTreeTable::removeMin(TNode* p)
{
	++eff;
	if (p->pL == 0)
		return p->pR;
	p->pL = removeMin(p->pL);
	return balance(p);
}
TNode* AVLTreeTable::remove(TNode* p, TKey k)
{
	++eff;
	if (p == nullptr) return 0;
	if (k < p->rec.key)
		p->pL = remove(p->pL, k);
	else if (k > p->rec.key)
		p->pR = remove(p->pR, k);
	else //  k == p->rec.key 
	{
		TNode* q = p->pL;
		TNode* r = p->pR;
		delete p;
		operationResult = true;
		if (!r)
			return q;
		TNode* min = findMin(r);
		min->pR = removeMin(r);
		min->pL = q;
		return balance(min);
	}
	return balance(p);
}
bool  AVLTreeTable::Insert(TRecord rec)
{
	operationResult = false;
	pRoot = insert(pRoot, rec);
	if (operationResult)
		++dataCount;
	return operationResult;
}
bool  AVLTreeTable::Delete(TKey key)
{
	operationResult = false;
	pRoot = remove(pRoot, key);
	if (operationResult)
		--dataCount;
	return operationResult;
}
