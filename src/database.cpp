#include <iostream>
#include <iomanip> 
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

// Credits to ChatGPT for the formatting
void Database::printTables() {
    std::cout << "Database: " << name << std::endl;
    for (const auto& table : tables) {
        std::cout << "\nTable: " << table.first << std::endl;

        std::cout << std::left; 
        for (const auto& column : table.second.getColumns()) {
            std::cout << std::setw(15) << column.getName(); 
        }
        std::cout << std::endl;

        for (size_t i = 0; i < table.second.getColumns().size(); ++i) {
            std::cout << std::setw(15) << "---------------"; 
        }
        std::cout << std::endl;

        for (const auto& record : table.second.getRecords()) {
            for (const auto& value : record.values) {
                if (value.getType() == DataType::VARCHAR) {
                    std::cout << std::setw(15) << static_cast<char*>(value.getData());
                } else if (value.getType() == DataType::INT) {
                    std::cout << std::setw(15) << *static_cast<int*>(value.getData());
                } else if (value.getType() == DataType::FLOAT) {
                    std::cout << std::setw(15) << *static_cast<float*>(value.getData());
                }
            }
            std::cout << std::endl;
        }
    }
}
Table& Database::getTable(const std::string& name){
    return tables.at(name);
}

void Database::insertTable(const std::string& name, const Record& record) {
    Table& table = getTable(name);
    table.addRecord(record);
}