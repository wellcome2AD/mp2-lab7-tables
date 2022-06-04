#include "TBalTree.h"
#include <cassert>

int TBalTree::LeftTreeBalIns(TNode*& p)
{
    int res = 0; // did height change
    ++eff;
    if (p->balance == 1)
    {
        p->balance = 0;
        res = 0;

    }
    else if (p->balance == 0)
    {
        p->balance = -1;
        res = 1;
    }
    else
    {
        TNode* left = p->pL;
        if (left->balance == -1) // перевес в левом поддереве слева
        {
            p->pL = left->pR;
            left->pR = p;
            p->balance = left->balance = 0;
            p = left;
        }
        else if (left->balance == 1) // перевес в левом поддереве справа
        {
            TNode* right = left->pR;
            left->pR = right->pL;
            p->pL = right->pR;
            right->pL = left;
            right->pR = p;
            if (right->balance == -1)
            {
                right->balance = 0;
                left->balance = 1;// 0;
                p->balance = 1;
            }
            else
            {
                right->balance = 1;// 0;
                left->balance = 0;//-1;
                p->balance = 0;
            }
            res = 0;
            p = right;
        }
    }
    return res;
}
int TBalTree::RightTreeBalIns(TNode*& p)
{
    int res = 0; // did height change
    ++eff;
    if (p->balance == 0)
    {
        p->balance = 1;
        res = 1;
    }
    else if (p->balance == -1)
    {
        p->balance = 0;
        res = 0;
    }
    else
    {
        TNode* right = p->pR;
        if (right->balance == 1) // перевес в правом поддереве справа
        {
            p->pR = right->pL;
            right->pL = p;
            p->balance = right->balance = 0;
            p = right;
        }
        else if (right->balance == -1) // перевес в правом поддереве слева
        {
            TNode* left = right->pL;
            right->pL = left->pR;
            p->pR = left->pL;
            left->pR = right;
            left->pL = p;
            if (left->balance == -1)
            {
                left->balance = -1;// 0;
                right->balance = 0;
                p->balance = 0;// 1;
            }
            else
            {
                left->balance = 0;
                right->balance = -1;
                p->balance = -1;// 0;
            }
            res = 0;
            p = left;
        }
    }
    return res;
}
int TBalTree::LeftTreeBalDel(TNode*& p)
{
    int result = 0;

    if (p->balance == 1) 
    {
        p->balance = 0;
        result = -1;
    }
    else if (p->balance == 0) 
    {
        p->balance = -1;
        result = 0;
    }
    else {
        TNode* pl = p->pL;

        if (pl->balance == -1) 
        {
            p->pL = pl->pR;
            pl->pR = p;

            pl->balance = 0;
            p->balance = 0;

            p = pl;
            result = -1;
        }
        else if (pl->balance == 1) 
        {
            TNode* plpr = pl->pR;

            pl->pR = plpr->pL;
            plpr->pL = pl;
            p->pL = plpr->pR;
            plpr->pR = p;
            if (plpr->balance == -1) 
            {
                p->balance = 1;
            }
            else 
            {
                p->balance = 0;
            }
            if (plpr->balance == 1) 
            {
                pl->balance = -1;
            }
            else 
            {
                pl->balance = 0;
            }
            p = plpr;
            p->balance = 0;
            result = -1;
        }
        else 
        {
            TNode* pp = p;
            TNode* plpl = pl->pL;
            TNode* plpr = pl->pR;

            p = pl;
            p->pL = plpl;
            p->pR = pp;
            pp->pL = plpr;
            pl->balance = 1;
            return 0;
        }
    }
    return result;
}
int TBalTree::RightTreeBalDel(TNode*& p)
{
   int result = 0;
	if (p->balance == -1) 
    {
		p->balance = 0;
		result = -1;
	}
	else if (p->balance == 0) 
    {
		p->balance = 1;
		result = 0;
	}
	else 
    {
		TNode* pr = p->pR;
		if (pr->balance == 1) 
        {
			p->pR = pr->pL;
			pr->pL = p;

			pr->balance = 0;
			p->balance = 0;

			p = pr;
			result = -1;
		}
		else if (pr->balance == -1) 
        {
			TNode* prpl = pr->pL;

			pr->pL = prpl->pR;
			prpl->pR = pr;
			p->pR = prpl->pL;
			prpl->pL = p;
			if (prpl->balance == 1) 
            {
				p->balance = -1;
			}
			else 
            {
				p->balance = 0;
			}
			if (prpl->balance == -1) 
            {
				pr->balance = 1;
			}
			else 
            {
				pr->balance = 0;
			}
			p = prpl;
			p->balance = 0;
			result = -1;
		}
		else 
        {
			TNode* pp = p;
			TNode* prpl = pr->pL;
			TNode* prpr = pr->pR;

			p = pr;
			p->pL = pp;
			p->pR = prpr;
			pp->pR = prpl;
			pr->balance = -1;
			return 0;
		}
	}
	return result;
}
int TBalTree::InsBalTree(TNode*& p, TRecord rec)
{
    int res = 0;
    if (p == nullptr)
    {
        p = new TNode(rec);
        res = 1;
        ++dataCount;
    }
    else if (p->rec.key > rec.key)
    {
        int tmp = InsBalTree(p->pL, rec);
        if (tmp == 1)
        {
            res = LeftTreeBalIns(p);
        }
    }
    else
    {
        int tmp = InsBalTree(p->pR, rec);
        if (tmp == 1)
        {
            res = RightTreeBalIns(p);
        }
    }
    return res;
}
int TBalTree::DelBalTree(TNode*& p, TKey key)
{
    int res = 0;
    ++eff;
    if (p == nullptr)
    {
        return res;
    }
    if (key > p->rec.key)
    {
        int tmp = DelBalTree(p->pR, key);
        if (tmp != 0)
        {
            res = LeftTreeBalDel(p);
        }
    }
    else if (key < p->rec.key)
    {
        int tmp = DelBalTree(p->pL, key);
        if (tmp != 0)
        {
            res = RightTreeBalDel(p);
        }
    }
    else
    {
        --dataCount;
        if (p->pL == nullptr && p->pR == nullptr) // удаление листа дерева
        {
            delete p;
            p = nullptr;
            res = -1;
        }
        else if (p->pL != nullptr && p->pR == nullptr) // удаление вершины с одним потомком слева
        {
            p->rec = p->pL->rec;
            delete p->pL;
            p->pL = nullptr;
            p->balance = 0;
            res = -1;
        }
        else if (p->pL == nullptr && p->pR != nullptr) // удаление вершины с одним потомком справа
        {
            p->rec = p->pR->rec;
            delete p->pR;
            p->pR = nullptr;
            p->balance = 0;
            res = 1;
        }
        else  // удаление вершины с двумя потомками
        {
            TNode* pl = p->pL, * pr = p->pR;
            TNode* pmax = FindMax(pl);
            p->rec = pmax->rec;
            int tmp = DelBalTree(p->pL, pmax->rec.key);
            if (tmp != 0)
            {
                res = RightTreeBalDel(p->pR);
            }
        }
        return res;
    }
}
TNode* TBalTree::FindMax(TNode* p) const
{
    assert(p != nullptr);
    while (p->pR)
    {
        p = p->pR;
    }
    return p;
}
bool TBalTree::Insert(TRecord rec)
{
    if (Find(rec.key))
    {
        return false;
    }
    InsBalTree(pRoot, rec);
    return true;
}

bool TBalTree::Delete(TKey key)
{
    if (!Find(key) || IsEmpty())
    {
        return false;
    }
    DelBalTree(pRoot, key);
    return true;
}
