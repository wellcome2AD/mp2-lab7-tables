#pragma once
#include "THashTable.h"
class TArrayHash :
    public THashTable
{
    TRecord* mas;
    int size, step;
    mutable int curr;
    TRecord free, del;
public:
    TArrayHash(int = 100, int = 7);
    ~TArrayHash();
    int GetSize() const override;
    const TRecord& GetCurrentRecord() const override;
    bool Find(TKey) const override;
    bool Insert(TRecord rec) override;
    bool Delete(TKey key) override;
    void Reset() const override;
    void GoNext() const override;
    bool IsFull() const override;
    bool IsEnd() const override;
};

