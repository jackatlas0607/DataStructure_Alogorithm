#include <iostream>

int rs(int n);

int main()
{
    std::cout << rs(1) << std::endl;
    std::cout << rs(2) << std::endl;
    std::cout << rs(3) << std::endl;
    std::cout << rs(4) << std::endl;
}

/*
    T(1) = 10
    T(n) = T(n-1) + 15

    n = 1  -> 10
    n = 2  -> 25
    n = 3  -> 40
    n = 4  -> 55
*/
int rs(int n)
{
    if (n == 1)
    {
        return 10;
    }
    else
    {
        return rs(n - 1) + 15;
    }
}