#pragma once
#include "TTreeTable.h"
class TBalTree :
    public TTreeTable
{
    int LeftTreeBalIns(TNode*& p); // return increased (1)/decreased (0) height
    int RightTreeBalIns(TNode*& p); // return increased (1)/decreased (0) height
    int LeftTreeBalDel(TNode*& p);
    int RightTreeBalDel(TNode*& p);   
    int InsBalTree(TNode*& p, TRecord rec);
    int DelBalTree(TNode*& p, TKey key);
    TNode* FindMax(TNode* p) const;
public:
    bool Insert(TRecord rec);
    bool Delete(TKey key);
};

