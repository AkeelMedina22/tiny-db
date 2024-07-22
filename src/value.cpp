#include "value.h"
#include <iostream>
#include <stdexcept>
#include <cstring> 

Value::Value(int intValue) : type(DataType::INT) {
    data.intValue = intValue;
}

Value::Value(float floatValue) : type(DataType::FLOAT) {
    data.floatValue = floatValue;
}

Value::Value(double doubleValue) : Value(static_cast<float>(doubleValue)) {}

Value::Value(const char* strValue) : type(DataType::VARCHAR) {
    if (strlen(strValue) >= MAX_STR_SIZE) {
        throw std::runtime_error("String value is too long");
    }
    strcpy(data.strValue, strValue);
}

Value::Value(const Value& other) {
    copyFrom(other);
}

Value& Value::operator=(const Value& other) {
    if (this != &other) {
        copyFrom(other);
    }
    return *this;
}

void Value::copyFrom(const Value& other) {
    type = other.type;
    if (type == DataType::VARCHAR) {
        strcpy(data.strValue, other.data.strValue);
    } else {
        data = other.data;
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
            return const_cast<char*>(data.strValue);
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
            std::cout << data.strValue;
            break;
    }
}

void Value::setIntValue(int intValue) {
    type = DataType::INT;
    data.intValue = intValue;
}

void Value::setFloatValue(float floatValue) {
    type = DataType::FLOAT;
    data.floatValue = floatValue;
}

void Value::setStringValue(const char* strValue) {
    if (strlen(strValue) >= MAX_STR_SIZE) {
        throw std::runtime_error("String value is too long");
    }
    type = DataType::VARCHAR;
    strcpy(data.strValue, strValue);
}
