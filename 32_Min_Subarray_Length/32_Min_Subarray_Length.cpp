#include <iostream>
#include <limits.h>

int minSubLength(int *arr, int length, int sum);
int minSubLength_v2(int *arr, int length, int sum);

int main()
{
    int arr1[] = {9, 8, 1, 4, 9, 5, 1, 2};
    int arr2[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int arr3[] = {8, 1, 6, 15, 3, 16, 5, 7, 14, 30, 12};
    std::cout << minSubLength(arr1, sizeof(arr1) / sizeof(int), 11) << std::endl; // 2
    std::cout << minSubLength(arr2, sizeof(arr2) / sizeof(int), 11) << std::endl; // 0
    std::cout << minSubLength(arr3, sizeof(arr3) / sizeof(int), 60) << std::endl; // 4

    std::cout << "********************" << std::endl;

    std::cout << minSubLength_v2(arr1, sizeof(arr1) / sizeof(int), 11) << std::endl; // 2
    std::cout << minSubLength_v2(arr2, sizeof(arr2) / sizeof(int), 11) << std::endl; // 0
    std::cout << minSubLength_v2(arr3, sizeof(arr3) / sizeof(int), 60) << std::endl; // 4
}

int minSubLength(int *arr, int length, int sum)
{
    int left = 0;
    int right = 0;
    int minLength = INT_MAX;
    int currentSum = 0;

    while (right < length)
    {
        currentSum += arr[right];

        if (currentSum < sum)
        {
            right++;
        }
        else
        {
            int tempLength = right - left + 1;
            if (tempLength < minLength)
            {
                minLength = tempLength;
            }
            currentSum = currentSum - arr[left] - arr[right];
            left++;
        }
    }

    if (minLength == INT_MAX)
    {
        return 0;
    }
    else
    {
        return minLength;
    }
}

int minSubLength_v2(int *arr, int length, int sum)
{
    int left = 0;
    int right = 0;
    int minLength = INT_MAX;
    int currentSum = 0;

    while (right < length)
    {
        currentSum += arr[right];

        while (currentSum >= sum)
        {
            int tempLength = right - left + 1;
            if (tempLength < minLength)
            {
                minLength = tempLength;
            }
            currentSum -= arr[left];
            left++;
        }
        right++;
    }

    if (minLength == INT_MAX)
    {
        return 0;
    }
    else
    {
        return minLength;
    }
}