#pragma once

#include <unordered_map>
#include "table.h"

class Database {
    public:
        Database(const std::string& name);
        void addTable(const std::string& name, const Schema& schema);
        void insertTable(const std::string& name, const Record& record);
        
        // void dropTable(const std::string& name);

        void printTables();

    private:
        std::string name;
        std::unordered_map<std::string, Table> tables;
        Table& getTable(const std::string& name);
};

