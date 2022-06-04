#pragma once
#include <string>
#include <iostream>

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

class TTable
{
protected:
	int dataCount = 0;
	mutable int eff = 0;
	virtual void PrintRec(std::ostream& os) const;
public:
	TTable();
	virtual ~TTable() = default;
	virtual int GetSize() const = 0;
	int GetDataCount() const;
	int GetEffectiveness() const;
	void ClearDataCount();
	void ClearEffectiveness();
	bool IsEmpty() const;
	virtual bool IsFull() const = 0;
	virtual bool Find(TKey) const = 0;
	virtual bool Insert(TRecord) = 0;
	virtual bool Delete(TKey) = 0;
	virtual void Reset() const = 0;
	virtual void GoNext() const = 0;
	virtual bool IsEnd() const = 0;
	virtual const TRecord& GetCurrentRecord() const = 0;
	friend std::ostream& operator<<(std::ostream& os, TTable& t)
	{
		t.PrintRec(os);
		return os;
	}
};

