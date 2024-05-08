#include "Array_function.h"
#include <iostream>

void fillArray(int *arr, int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100; // 0~99
    }
}

void printArray(int *arr, int length)
{
    std::cout << "[";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i];

        if (i == length - 1)
        {
            std::cout << "]" << std::endl;
        }
        else
        {
            std::cout << ", ";
        }
    }
}