#pragma once

#include <vector>
#include <string>
#include "datatype.h"
#include "column.h"

class Schema {
    public:
        Schema();
        Schema(const std::vector<Column>& columns);

        std::vector<Column>::const_iterator begin() const;
        std::vector<Column>::const_iterator end() const;

        const Column& operator[](size_t index) const; // Access column by index
        size_t size() const; // Get the number of columns
        
    private:
        std::vector<Column> columns;
};
