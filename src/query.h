#include <string>

class Query {
    public:
        Query(const std::string& query);

        void parse();
        void execute();

    private:
        std::string query;
};

