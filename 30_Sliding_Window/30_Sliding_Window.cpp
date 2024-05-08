#include <iostream>
#include <limits.h>
#include <array>
#include <vector>

int maxSum(int *arr, int length, int size);
int improvedMaxSum(int *arr, int length, int size);
int minSum(int *arr, int length, int size);

int main()
{
    int arr1[] = {2, 7, 3, 0, 6, 1, -5, -12, -11};
    int arr2[] = {2, 7, 3, 7, 25, 0, 6, 1, -5, 12, -11};
    std::cout << maxSum(arr1, sizeof(arr1) / sizeof(int), 3) << std::endl;         // 12
    std::cout << improvedMaxSum(arr2, sizeof(arr2) / sizeof(int), 3) << std::endl; // 35
    std::cout << minSum(arr1, sizeof(arr1) / sizeof(int), 3) << std::endl;         // -28
}

int maxSum(int *arr, int length, int size)
{
    int max = -INT_MAX;

    for (int i = 0; i < length - size + 1; i++)
    {
        int temp = 0;
        for (int j = i; j < size + i; j++)
        {
            temp += arr[j];
        }

        if (temp > max)
        {
            max = temp;
        }
    }
    return max;
}

int improvedMaxSum(int *arr, int length, int size)
{
    /*
    [2,7,3]    2 + 7 + 3 = 12
      [7,3,0]   12 - 2 + 0 = 10
        [3,0,6]   10 - 7 + 6 = 9
             .....
    */

    int max = 0;
    for (int i = 0; i < size; i++)
    {
        max += arr[i];
    }

    int temp = max;

    for (int i = 1; i < length - size + 1; i++)
    {
        temp = temp - arr[i - 1] + arr[i - 1 + size];
        if (max < temp)
        {
            max = temp;
        }
    }
    return max;
}

int minSum(int *arr, int length, int size)
{
    int min = INT_MAX;

    for (int i = 0; i < length - size + 1; i++)
    {
        int temp = 0;
        for (int j = i; j < size + i; j++)
        {
            temp += arr[j];
        }

        if (temp < min)
        {
            min = temp;
        }
    }
    return min;
}
