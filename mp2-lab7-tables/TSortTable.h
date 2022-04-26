#pragma once
#include "TArrayTable.h"
#include "TScanTable.h"
class TSortTable :
    public TArrayTable
{
private:
    void QSort(int, int);
    void Sort();
public:
    TSortTable(int = 100);
    TSortTable(const TScanTable&);
    bool Find(TKey) const override;
    bool Insert(TRecord) override;
    bool Delete(TKey) override;
};
