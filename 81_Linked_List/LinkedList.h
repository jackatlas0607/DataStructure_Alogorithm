#ifndef LinkedList_H
#define LinkedList_H
#include "Node.h"

class LinkedList
{
private:
    int length;
    Node *head; // 指向 linked list的第一個 element

public:
    LinkedList();
    int getLength();
    Node *getIndex(int index);
    void push(std::string data);                // 在尾端加入
    void pop();                                 // 刪除尾端的值
    void unshift(std::string data);             // 在開頭加入
    void shift();                               // 刪除開頭的值
    void insertAt(int index, std::string data); // 在特定 index insert
    void removeAt(int index);                   // 刪除特定 index
    void printAll();
};
#endif