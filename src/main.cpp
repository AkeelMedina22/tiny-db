#include <iostream>
#include <string>
#include "database.h"
#include "record.h"
#include "column.h"
#include "value.h"
#include "query.h"
#include "schema.h"
#include "datatype.h"

int main() {
    Database db("MyDatabase");

    // Data input until Query parsing is implemented
    Schema schema({Column("id", DataType::INT), Column("height", DataType::FLOAT), Column("name", DataType::VARCHAR), Column("email", DataType::VARCHAR)});

    db.addTable("Users", schema);

    db.insertTable("Users", Record(schema, {Value(1), Value(12.25), Value("Akeel"), Value("akeelmedina22@gmail.com")}));
    db.insertTable("Users", Record(schema, {Value(2), Value(17.75), Value("Hamza"), Value("ramenguy21@gmail.com")}));

    db.printTables();

    // std::string input;

    // while (true) {
    //     std::cout << "Enter SQL query (or type 'exit' to quit): ";
    //     std::getline(std::cin, input);

    //     if (input == "quit" || input == "q") {
    //         break;
    //     }

    //     try {
    //         Query query(input);
    //         query.parse();
    //         query.execute();
    //     } catch (const std::exception& e) {
    //         std::cerr << "Error: " << e.what() << std::endl;
    //     }
    // }

    return 0;
}