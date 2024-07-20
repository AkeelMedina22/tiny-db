#include <string>
#include <datatype.h>

class Column {
    public:
        Column(const std::string& name, const DataType& type);
    private:
        std::string name;
        DataType type;
};
