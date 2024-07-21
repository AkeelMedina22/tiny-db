#include <iostream>
#include <unordered_map>
#include "record.h"
#include "table.h"
#include "column.h"
#include "datatype.h"

Column::Column(const std::string& name, const DataType& type) : name(name), type(type) {}

const std::string& Column::getName() const {
    return name;
}

DataType Column::getType() const {
    return type;
}