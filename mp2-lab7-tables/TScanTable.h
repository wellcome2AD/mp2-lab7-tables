#pragma once
#include "TArrayTable.h"
class TScanTable :
    public TArrayTable
{
public:
    TScanTable(int = 100);
    bool Find(TKey) const override;
    bool Insert(TRecord) override;
    bool Delete(TKey) override;
};

