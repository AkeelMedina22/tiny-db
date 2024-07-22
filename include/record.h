#pragma once

#include <string>
#include <vector>
#include "value.h"
#include "schema.h"

class Record {
    public:
        std::vector<Value> values;
        Record(const Schema& schema, const std::vector<Value>& values);
};
