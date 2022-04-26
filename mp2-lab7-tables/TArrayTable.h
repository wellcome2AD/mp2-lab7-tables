#pragma once
#include "TTable.h"
class TArrayTable :
    public TTable
{
protected:
    TRecord* mas;
    int size;
    mutable int curr;
public:
    TArrayTable(int = 100);
    ~TArrayTable();
    int GetSize() const override;
    TRecord GetCurrentRecord() const override;
    bool IsFull() const override;
    void Reset() const override;
    void GoNext() const override;
    bool IsEnd()  const override;
};

