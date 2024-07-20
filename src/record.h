#include <string>
#include <datatype.h>

class Record {
    public:
        Record(const std::string& name, const DataType& type);
    private:
        std::string name;
        DataType type;
};
