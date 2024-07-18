#ifndef Node_H
#define Node_H
#include <string>

class Node
{
private:
    std::string data;
    Node *next;

public:
    Node(std::string data);
    Node *getNext();
    void setNext(Node *node);
    std::string getData();
};

#endif