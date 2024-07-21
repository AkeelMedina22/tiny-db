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
        
    private:
        std::vector<Column> columns;
};
