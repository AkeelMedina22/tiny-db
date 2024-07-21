#include <string>
#include "schema.h"
#include "record.h"
#include "column.h"
#include "table.h"

Table::Table() : name(""), schema() {}
Table::Table(const std::string& name, const Schema& schema) : name(name), schema(schema) {}

const std::string& Table::getName() const {
    return name;
}

const Schema& Table::getColumns() const {
    return schema;
}