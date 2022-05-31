#pragma once
#include "TTreeTable.h"
class TBalTree :
    public TTreeTable
{
    int LeftTreeBal(TNode*& p); // return increased (1)/decreased (0) height
    int RightTreeBal(TNode*& p); // return increased (1)/decreased (0) height
    int InsBalTree(TNode*& p, TRecord rec);
    int DelBalTree(TNode*& p, TKey key);
public:
    bool Insert(TRecord rec);
    bool Delete(TRecord rec);
};

