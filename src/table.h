#include "schema.h"
#include "record.h"
#include <vector>

class Table {
    public:
        Table(const Schema& schema);
        // void addRecord(const Record& record);
        // void removeRecord(const Record& record);
        // void updateRecord(const Record& record);
        // void selectRecord(const Record& record);
    private:
        Schema schema;
        std::vector<Record> records;
};