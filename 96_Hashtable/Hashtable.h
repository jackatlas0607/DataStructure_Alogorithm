#ifndef Hashtable_H
#define Hashtable_H

#include <vector>
#include <string>

class Data
{
private:
    int key;
    std::string value;

public:
    Data(int key, std::string value)
    {
        this->key = key;
        this->value = value;
    }

    int getKey()
    {
        return this->key;
    }

    std::string getValue()
    {
        return this->value;
    }
};

class Hashtable
{
private:
    int size;
    std::vector<std::vector<Data>> hashtable;

public:
    Hashtable(int size);

private:
    int hash1(int key); // division method
    int hash2(int key); // multiplication method

public:
    void set(int key, std::string value);
    Data get(int key);
    void printAll();
};
#endif