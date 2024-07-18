#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
    this->head = NULL;
    this->length = 0;
}

int LinkedList::getLength()
{
    return this->length;
}

Node *LinkedList::getIndex(int index)
{
    if (index < 0 || index > this->length - 1)
    {
        throw "Invalid index";
    }
    else
    {
        Node *currentNode = this->head;
        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->getNext();
        }
        return currentNode;
    }
}

void LinkedList::push(std::string data)
{
    Node *newnode = new Node(data);
    if (this->head == NULL)
    {
        this->head = newnode;
    }
    else
    {
        Node *currentnode = this->head;
        while (currentnode->getNext() != NULL)
        {
            currentnode = currentnode->getNext();
        }

        currentnode->setNext(newnode);
    }
    this->length++;
}

void LinkedList::pop()
{
    if (this->head == NULL)
    {
        std::cout << "No element in the linked list!!!" << std::endl;
        return;
    }
    else if (this->length == 1)
    {
        Node *temp = this->head;
        std::cout << "Remove " << temp->getData() << std::endl;
        delete temp;
        this->head = NULL;
        this->length = 0;
    }
    else
    {
        Node *currentNode = this->head;
        for (int i = 0; i < this->length - 2; i++)
        {
            currentNode = currentNode->getNext();
        }
        Node *lastElement = currentNode->getNext();
        currentNode->setNext(NULL);
        std::cout << "Remove " << lastElement->getData() << std::endl;
        delete lastElement;
        this->length--;
    }
}

void LinkedList::unshift(std::string data)
{
    Node *newnode = new Node(data);
    if (this->head == NULL)
    {
        this->head = newnode;
    }
    else
    {
        Node *temp = this->head;
        newnode->setNext(temp);
        this->head = newnode;
    }
    this->length++;
}

void LinkedList::shift()
{
    if (this->head == NULL)
    {
        std::cout << "No element in the linked list!!!" << std::endl;
        return;
    }
    else if (this->length == 1)
    {
        Node *temp = this->head;
        std::cout << "Remove " << temp->getData() << std::endl;
        delete temp;
        this->head = NULL;
        this->length = 0;
    }
    else
    {
        Node *temp = this->head;
        this->head = this->head->getNext();
        std::cout << "Remove " << temp->getData() << std::endl;
        delete temp;
        this->length--;
    }
}

void LinkedList::insertAt(int index, std::string data)
{
    if (index > this->length || index < 0)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    else if (index == 0)
    {
        this->unshift(data);
    }
    else if (index == this->length)
    {
        this->push(data);
    }
    else
    {
        Node *newnode = new Node(data);
        Node *currentNode = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->getNext();
        }

        Node *nextNode = currentNode->getNext();
        currentNode->setNext(newnode);
        newnode->setNext(nextNode);
        this->length++;
    }
}

void LinkedList::removeAt(int index)
{
    if (index < 0 || index > this->length - 1)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    else if (index == 0)
    {
        this->shift();
    }
    else if (index == this->length - 1)
    {
        this->pop();
    }
    else
    {
        Node *currentNode = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->getNext();
        }

        Node *nextNode = currentNode->getNext()->getNext();
        std::cout << "Remove " << currentNode->getNext()->getData() << std::endl;
        delete currentNode->getNext();
        currentNode->setNext(nextNode);
        this->length--;
    }
}

void LinkedList::printAll()
{
    if (this->head == NULL)
    {
        std::cout << "No elements in Linked List!!!" << std::endl;
        return;
    }

    Node *currentNode = this->head;

    std::cout << "[";
    while (currentNode->getNext() != NULL)
    {
        std::cout << currentNode->getData() << ", ";
        currentNode = currentNode->getNext();
    }
    std::cout << currentNode->getData() << "]" << std::endl;
}