#include "headers.h"

#define LIMIT 10

class identityNode{
    private:
        std::string companyName;
        identityNode *next[LIMIT];
    public:
        identityNode(std::string compay="");
        void insert(std::string company, std::string from, std::string to);
        std::string search(std::string credit_card);
        void display();
        bool isLeaf();
        void display(std::string message);
};

identityNode initializer();