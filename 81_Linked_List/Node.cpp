#include "LinkedList.h"
#include <iostream>

Node::Node(std::string data)
{
    this->data = data;
    this->next = NULL;
}

Node *Node::getNext()
{
    return this->next;
}

void Node::setNext(Node *node)
{
    this->next = node;
}

std::string Node::getData()
{
    return this->data;
}