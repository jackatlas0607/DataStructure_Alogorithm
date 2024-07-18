#include "Hashtable.h"
#include "Hashtable.cpp"

int main()
{
    Hashtable h1(3);

    h1.set(21, "A");
    h1.set(22, "B");
    h1.set(23, "C");
    h1.set(24, "D");
    h1.set(25, "E");
    h1.set(26, "F");
    h1.set(27, "G");
    h1.printAll();

    try
    {
        std::cout << h1.get(28).getKey() << ":" << h1.get(24).getValue();
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
}