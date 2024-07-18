#include "LinkedList.h"
#include "Node.h"
#include "LinkedList.cpp"
#include "Node.cpp"

int main()
{
    LinkedList l1;

    l1.unshift("Hatake Kakashi");
    l1.unshift("Uzumaki Naruto");
    l1.unshift("Uchiha Sasuke");
    l1.printAll();
    std::cout << l1.getLength() << std::endl;

    l1.insertAt(2, "Uchiha Itachi");
    l1.printAll();
    std::cout << l1.getLength() << std::endl;

    l1.removeAt(2);
    l1.printAll();
    std::cout << l1.getLength() << std::endl;

    try
    {
        std::cout << l1.getIndex(2)->getData() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    try
    {
        std::cout << l1.getIndex(20)->getData() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
}