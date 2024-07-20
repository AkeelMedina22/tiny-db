#include <iostream>
#include <unordered_map>
#include "database.h"
#include "column.h"
#include "schema.h"

Database::Database(const std::string& name) : name(name) {}

void Database::addTable(const std::string& name, const std::vector<Column>& columns) {
    if (tables.find(name) == tables.end()) {
        tables[name] = Schema(columns);
    } else {
        throw std::runtime_error("Table already exists: " + name);
    }
}

