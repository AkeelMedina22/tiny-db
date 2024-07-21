#include "value.h"
#include <iostream>
#include <stdexcept>

Value::Value(DataType type) : type(type) {
    if (type == DataType::VARCHAR) {
        data.strValue = new std::string();
    }
}

Value::Value(int intValue) : type(DataType::INT) {
    data.intValue = intValue;
}

Value::Value(float floatValue) : type(DataType::FLOAT) {
    data.floatValue = floatValue;
}

Value::Value(const std::string& strValue) : type(DataType::VARCHAR) {
    data.strValue = new std::string(strValue);
}

Value::~Value() {
    if (type == DataType::VARCHAR) {
        clearString();
    }
}

void Value::setIntValue(int intValue) {
    if (type == DataType::VARCHAR) {
        clearString();
    }
    type = DataType::INT;
    data.intValue = intValue;
}

void Value::setFloatValue(float floatValue) {
    if (type == DataType::VARCHAR) {
        clearString();
    }
    type = DataType::FLOAT;
    data.floatValue = floatValue;
}

void Value::setStringValue(const std::string& strValue) {
    if (type != DataType::VARCHAR) {
        clearString();
        type = DataType::VARCHAR;
        data.strValue = new std::string(strValue);
    } else {
        *data.strValue = strValue;
    }
}

DataType Value::getType() const {
    return type;
}

void* Value::getData() const {
    switch (type) {
        case DataType::INT:
            return const_cast<int*>(&data.intValue);
        case DataType::FLOAT:
            return const_cast<float*>(&data.floatValue);
        case DataType::VARCHAR:
            return data.strValue;
        default:
            return nullptr;
    }
}

void Value::printValue() const {
    switch (type) {
        case DataType::INT:
            std::cout << data.intValue;
            break;
        case DataType::FLOAT:
            std::cout << data.floatValue;
            break;
        case DataType::VARCHAR:
            std::cout << *data.strValue;
            break;
    }
}

void Value::clearString() {
    if (type == DataType::VARCHAR && data.strValue) {
        delete data.strValue;
        data.strValue = nullptr;
    }
}