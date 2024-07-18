#include "Hashtable.h"
#include <math.h>
#include <iostream>

Hashtable::Hashtable(int size)
{
    this->size = size;

    std::vector<Data> arr;
    for (int i = 0; i < size; i++)
    {
        this->hashtable.push_back(arr);
    }
}

int Hashtable::hash1(int key)
{
    return key % this->size;
}

int Hashtable::hash2(int key)
{
    double A = (sqrt(5) - 1) / 2;
    return floor(this->size * ((int)(key * A) % 1));
}

void Hashtable::set(int key, std::string value)
{

    int index = this->hash1(key);
    this->hashtable[index].push_back(Data(key, value));
}

Data Hashtable::get(int key)
{
    int index = this->hash1(key); // 找到在第幾個 index的 vector
    for (int i = 0; i < this->hashtable[index].size(); i++)
    {
        if (this->hashtable[index][i].getKey() == key)
        {
            return this->hashtable[index][i];
        }
    }
    throw "This key does not exist!!!";
}

void Hashtable::printAll()
{
    std::cout << "[ ";
    for (int i = 0; i < this->hashtable.size(); i++)
    {
        std::cout << "[ ";
        for (int j = 0; j < this->hashtable[i].size(); j++)
        {
            std::cout << "(" << this->hashtable[i][j].getKey() << ":" << this->hashtable[i][j].getValue() << "), ";
        }
        std::cout << "], ";
    }
    std::cout << "]" << std::endl;
}
