#include <iostream>
#include <unordered_map>
#include "database.h"
#include "column.h"
#include "schema.h"

Database::Database(const std::string& name) : name(name) {}

void Database::addTable(const std::string& name, const Schema& schema) {
    if (tables.find(name) == tables.end()) {
        tables[name] = Table(name, schema);
    } else {
        throw std::runtime_error("Table already exists: " + name);
    }
}

void Database::printTables() {
    std::cout << "Database: " << name << std::endl;
    for (const auto& table : tables) {
        std::cout << "Table: " << table.first << std::endl;
        for (const auto& column : table.second.getColumns()) {
            std::cout << "Column: " << column.getName() << std::endl;
        }
    }
}