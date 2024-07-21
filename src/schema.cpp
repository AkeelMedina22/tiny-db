#include <string>
#include <vector>
#include "schema.h"
#include "column.h"
#include "datatype.h"

Schema::Schema() = default;
Schema::Schema(const std::vector<Column>& columns) : columns(columns) {}

// Iterate through schema to iterate through all columns
std::vector<Column>::const_iterator Schema::begin() const {
    return columns.begin();
}

std::vector<Column>::const_iterator Schema::end() const {
    return columns.end();
}