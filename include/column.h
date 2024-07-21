#pragma once

#include <string>
#include "datatype.h"

class Column {
    public:
        Column(const std::string& name, const DataType& type);
        
        const std::string& getName() const;
        DataType getType() const;

    private:
        DataType type;
        std::string name;
};
