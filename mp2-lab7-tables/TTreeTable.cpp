#include "TTreeTable.h"
#include <iostream>
TTreeTable::TTreeTable() = default;
TTreeTable::~TTreeTable() { DelTree(pRoot); }
void TTreeTable::DelTree(TNode* p)
{
	if (p)
	{
		DelTree(p->pL);
		DelTree(p->pR);
		delete p;
	}
}
bool TTreeTable::Find(TKey key) const
{
	pCurr = pRoot;
	pPrev = nullptr;
	while (pCurr != nullptr)
	{
		++eff;
		if (pCurr->rec.key == key)
		{
			return true;
		}
		pPrev = pCurr;
		if (pCurr->rec.key > key)
		{
			pCurr = pCurr->pL;
		}
		else
		{
			pCurr = pCurr->pR;
		}
	}
	pCurr = pPrev;
	return false;
}
bool TTreeTable::Insert(TRecord rec)
{
	if (Find(rec.key))
		return false;
	TNode* tmp = new TNode(rec);
	if (pCurr == nullptr)
	{
		pRoot = tmp;
	}
	else
	{
		if (rec.key > pCurr->rec.key)
			pCurr->pR = tmp;
		else
			pCurr->pL = tmp;
		++dataCount;
		++eff;
		return true;
	}
}
bool TTreeTable::Delete(TKey key)
{
	if (IsEmpty() || !Find(key))
		return false;
	TNode* tmp = pCurr;
	if (pCurr->pR == nullptr)
	{
		if (pPrev == nullptr)
			pRoot = pCurr->pL;
		if (pCurr->rec.key > pPrev->rec.key)
			pPrev->pR = pCurr->pL;
		else
			pPrev->pL = pCurr->pL;
	}
	else if (pCurr->pL == nullptr)
	{
		if (pPrev == nullptr)
			pRoot = pCurr->pR;
		if (pCurr->rec.key > pPrev->rec.key)
			pPrev->pR = pCurr->pR;
		else
			pPrev->pL = pCurr->pR;
	}
	else
	{
		tmp = tmp->pL;
		pPrev = pCurr;
		while (tmp->pR != nullptr)
		{
			pPrev = tmp;
			tmp = tmp->pR;
		}
		pCurr->rec = tmp->rec;
		if (pCurr->pL == tmp)
			pPrev->pL = tmp->pL;
		else
			pPrev->pR = tmp->pL;
		delete tmp;
	}
	--dataCount;
	++eff;
	return true;
}
void TTreeTable::Reset() const 
{
	currPos = 0;
	pCurr = pRoot;
	st = std::stack<TNode*>();
	if (pCurr)
	{
		while (pCurr->pL)
		{
			st.push(pCurr);
			pCurr = pCurr->pL;
		}
	}
	st.push(pCurr);
}
void TTreeTable::GoNext() const 
{
	pCurr = st.top();
	st.pop();
	if (pCurr)
	{
		if (pCurr->pR)
		{
			pCurr = pCurr->pR;
			while (pCurr->pL)
			{
				st.push(pCurr);
				pCurr = pCurr->pL;
			}
			st.push(pCurr);
		}
		else
		{
			pCurr = st.top();
		}
		currPos++;
	}
}
bool TTreeTable::IsEnd() const { return currPos == dataCount; }
const TRecord& TTreeTable::GetCurrentRecord() const
{ 
	if (pCurr)
	{
		return pCurr->rec;
	}
	else
	{
		throw std::exception("Table is empty\n");
	}
}
void TTreeTable::PrintRec(std::ostream& os, const TNode* p, int level)
{
	if (p)
	{
		for (int i = 0; i < level; ++i)
		{
			os << ' ';
		}
		os << p->rec.key << std::endl;
		PrintRec(os, p->pL, level + 1);
		PrintRec(os, p->pR, level + 1);
	}
}
std::ostream& operator<<(std::ostream& os, const TTreeTable& table)
{
	TTreeTable::PrintRec(os, table.pRoot, 0);
	return os;
}
