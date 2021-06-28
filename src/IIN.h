#include <iostream>
#include <vector>

#define LIMIT 10

using namespace std;

class identityNode{
    private:
        string companyName;
        identityNode *next[LIMIT];
    public:
        identityNode(string compay="");
        void insert(string company, string from, string to);
        string search(string credit_card);
        void display();
        bool isLeaf();
        void display(string message);
};