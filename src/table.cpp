#include <iostream>
#include <unordered_map>
#include "record.h"
#include "column.h"
#include "table.h"

Table::Table(const std::vector<Column>& columns) : columns(columns) {}
