#pragma once
#include <iostream>
#include "NetVarStructs.h"


uintptr_t getOffset(RecvTable* table, std::string tableName, std::string netVarName);
