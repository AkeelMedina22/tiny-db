#pragma once

#include "schema.h"
#include "record.h"
#include <string>
#include <vector>

class Table {
    public:
        Table();
        Table(const std::string& name, const Schema& schema);
        // void addRecord(const Record& record);
        // void removeRecord(const Record& record);
        // void updateRecord(const Record& record);
        // void selectRecord(const Record& record);

        const std::string& getName() const;
        const Schema& getColumns() const;

    private:
        Schema schema;
        std::string name;
        std::vector<Record> records;
};