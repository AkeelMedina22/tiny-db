#pragma once

#include <unordered_map>
#include "table.h"

class Database {
    public:
        Database(const std::string& name);
        void addTable(const std::string& name, const Schema& schema);
        void printTables();

    private:
        std::string name;
        std::unordered_map<std::string, Table> tables;
};

