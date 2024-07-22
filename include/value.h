#pragma once

#include <string>
#include "datatype.h"

class Value {
public:
    static const int MAX_STR_SIZE = 256;

    Value(int intValue);
    Value(float floatValue);
    Value(double doubleValue);
    Value(const char* strValue);
    Value(const Value& other); 
    Value& operator=(const Value& other); 

    DataType getType() const;
    void* getData() const;
    void printValue() const;

    void setIntValue(int intValue);
    void setFloatValue(float floatValue);
    void setStringValue(const char* strValue);

private:
    DataType type;
    union {
        int intValue;
        float floatValue;
        char strValue[MAX_STR_SIZE];
    } data;

    void copyFrom(const Value& other);
};
