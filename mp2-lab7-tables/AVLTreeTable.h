#pragma once
#include <iostream>
#include <cassert>
#include <stack>
#include <string>
typedef int TKey;
typedef std::string TValue;

struct TRecord
{
	TKey key = -1;
	TValue value;
	bool operator==(const TRecord& rec) const
	{
		return (key == rec.key) && (value == rec.value);
	}
	friend std::ostream& operator<<(std::ostream& os, TRecord rec)
	{
		os << rec.key << ":\t" << rec.value;
		return os;
	}
	TRecord(TKey _key = -1, TValue _value = "") : key(_key), value(_value) {}
};

struct TNode
{
	TRecord rec;
	TNode* pRight, * pLeft;
	int mHeight;
	TNode(TRecord rec) : rec(rec), pLeft(nullptr), pRight(nullptr) {}
};

class AVLTreeTable
{
	static int height(TNode* p)
	{
		return p != nullptr ? p->mHeight : 0;
	}
	static int bfactor(TNode* p)
	{
		assert(p != nullptr);
		return height(p->pRight) - height(p->pLeft);
	}
	static void fixheight(TNode* p)
	{
		int hl = height(p->pLeft);
		int hr = height(p->pRight);
		p->mHeight = (hl > hr ? hl : hr) + 1;
	}
	static TNode* rotateRight(TNode* p)
	{
		TNode* q = p->pLeft;
		p->pLeft = q->pRight;
		q->pRight = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	static TNode* rotateleft(TNode* q)
	{
		TNode* p = q->pRight;
		q->pRight = p->pLeft;
		p->pLeft = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	TNode* balance(TNode* p)
	{
		++eff;
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->pRight) < 0)
				p->pRight = rotateRight(p->pRight);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->pLeft) > 0)
				p->pLeft = rotateleft(p->pLeft);
			return rotateRight(p);
		}
		return p;
	}
	TNode* insert(TNode* p, TRecord rec)
	{
		++eff;
		if (p == nullptr)
		{
			operationResult = true;
			return new TNode(rec);
		}
		if (rec.key < p->rec.key)
			p->pLeft = insert(p->pLeft, rec);
		else
			p->pRight = insert(p->pRight, rec);
		return balance(p);
	}
	TNode* findMin(TNode* p)
	{
		++eff;
		return p->pLeft ? findMin(p->pLeft) : p;
	}
	TNode* removeMin(TNode* p)
	{
		++eff;
		if (p->pLeft == 0)
			return p->pRight;
		p->pLeft = removeMin(p->pLeft);
		return balance(p);
	}
	TNode* remove(TNode* p, TKey k)
	{
		++eff;
		if (p == nullptr) return 0;
		if (k < p->rec.key)
			p->pLeft = remove(p->pLeft, k);
		else if (k > p->rec.key)
			p->pRight = remove(p->pRight, k);
		else //  k == p->rec.key 
		{
			TNode* q = p->pLeft;
			TNode* r = p->pRight;
			delete p;
			operationResult = true;
			if (!r)
				return q;
			TNode* min = findMin(r);
			min->pRight = removeMin(r);
			min->pLeft = q;
			return balance(min);
		}
		return balance(p);
	}

	bool operationResult = false;
	int dataCount = 0;
	mutable int eff = 0;
	mutable int currPos = 0;

	mutable TNode* pRoot = nullptr, * pCurr = nullptr, * pPrev = nullptr;
	mutable std::stack<TNode*> st;
	
	static void PrintNode(std::ostream& os, const TNode* p, int level)
	{
		if (p)
		{
			for (int i = 0; i < level; ++i)
			{
				os << ' ';
			}
			os << p->rec.key << std::endl;
			PrintNode(os, p->pLeft, level + 1);
			PrintNode(os, p->pRight, level + 1);
		}
	}
	void DelTree(TNode* p)
	{
		if (p)
		{
			DelTree(p->pLeft);
			DelTree(p->pRight);
			delete p;
		}
	}
	void PrintRec(std::ostream& os) const
	{
		PrintNode(os, pRoot, 0);
	}
public:
	~AVLTreeTable() { DelTree(pRoot); }
	bool Insert(TRecord rec)
	{
		operationResult = false;
		pRoot = insert(pRoot, rec);
		if (operationResult)
			++dataCount;
		return operationResult;
	}
	bool Delete(TKey key)
	{
		operationResult = false;
		pRoot = remove(pRoot, key);
		if (operationResult)
			--dataCount;
		return operationResult;
	}
	bool Find(TKey key) const
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
				pCurr = pCurr->pLeft;
			}
			else
			{
				pCurr = pCurr->pRight;
			}
		}
		pCurr = pPrev;
		return false;
	}
	void Reset() const
	{
		currPos = 0;
		pCurr = pRoot;
		st = std::stack<TNode*>();
		if (pCurr)
		{
			while (pCurr->pLeft)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
		}
		st.push(pCurr);
	}
	void GoNext() const
	{
		pCurr = st.top();
		st.pop();
		if (pCurr)
		{
			if (pCurr->pRight)
			{
				pCurr = pCurr->pRight;
				while (pCurr->pLeft)
				{
					st.push(pCurr);
					pCurr = pCurr->pLeft;
				}
				st.push(pCurr);
			}
			else
			{
				if (!st.empty())
				{
					pCurr = st.top();
				}
			}
			currPos++;
		}
	}
	bool IsEnd() const { return currPos == dataCount; }
	friend std::ostream& operator<<(std::ostream& os, AVLTreeTable& t)
	{
		t.PrintRec(os);
		return os;
	}
};
