#include "TTable.h"
TTable::TTable() : dataCount(0), eff(0) {}
int TTable::GetDataCount() const { return dataCount; }
int TTable::GetEffectiveness() const { return eff; }
void TTable::ClearDataCount() { dataCount = 0; }
void TTable::ClearEffectiveness() { eff = 0; }
bool TTable::IsEmpty() const { return dataCount == 0; }