#include <iostream>
#include <string>
#include "database.h"
#include "column.h"
#include "query.h"
#include "datatype.h"

int main() {
    Database db("MyDatabase");

    // temporary data
    db.addTable("Users", {Column("id", DataType::INT), Column("name", DataType::VARCHAR), Column("email", DataType::VARCHAR)});
    db.addTable("Orders", {Column("id", DataType::INT), Column("user_id", DataType::INT), Column("amount", DataType::FLOAT)});

    std::string input;

    while (true) {
        std::cout << "Enter SQL query (or type 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "quit" || input == "q") {
            break;
        }

        try {
            break;
            Query query(input);
            query.parse();
            query.execute();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}