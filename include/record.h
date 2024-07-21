#pragma once

#include <string>
#include <vector>
#include "value.h"
#include "column.h"

class Record {
    public:
        std::vector<Value> values;
        Record(const std::vector<Column>& schema, const std::vector<Value>& values);
};
