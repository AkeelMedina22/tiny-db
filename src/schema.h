#include <vector>
#include <string>
#include <datatype.h>
#include "column.h"

class Schema {
    public:
        Schema(const std::vector<Column>& columns);
    private:
        std::vector<Column> columns;
};
