#pragma once

#include <string>
#include "datatype.h"

class Value {
public:
    Value(DataType type);
    Value(int intValue);
    Value(float floatValue);
    Value(const std::string& strValue);
    ~Value();

    void setIntValue(int intValue);
    void setFloatValue(float floatValue);
    void setStringValue(const std::string& strValue);
    
    DataType getType() const;
    void* getData() const;
    void printValue() const;

private:
    DataType type;
    union {
        int intValue;
        float floatValue;
        std::string* strValue; 
    } data;

    void clearString();
};