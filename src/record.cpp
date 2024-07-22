#include <iostream>
#include <unordered_map>
#include "record.h"
#include "table.h"
#include "record.h"
#include "schema.h"
#include "datatype.h"

Record::Record(const Schema& schema, const std::vector<Value>& values) {
    if (schema.size() != values.size()) {
        throw std::runtime_error("Schema and values size mismatch");
    }
    for (size_t i = 0; i < schema.size(); ++i) {
        if (schema[i].getType() != values[i].getType()) {
            throw std::runtime_error("Value type does not match schema type");
        }
    }
    this->values = values;
}