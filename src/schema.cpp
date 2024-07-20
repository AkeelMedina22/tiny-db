#include <string>
#include <vector>
#include "schema.h"
#include "column.h"
#include "datatype.h"

Schema::Schema(const std::vector<Column>& columns) : columns(columns) {}
