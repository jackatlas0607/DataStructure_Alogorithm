#include <iostream>

int fs(int n);

int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << fs(i) << std::endl;
    }
}

/*
   F(0) = 0
   F(1) = 1
   F(n) = F(n-1) + F(n-2)
*/
int fs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fs(n - 1) + fs(n - 2);
    }
}