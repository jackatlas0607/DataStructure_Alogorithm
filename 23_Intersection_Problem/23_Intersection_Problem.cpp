#include <iostream>
#include <stdlib.h>
#include <array>
#include <map>

int *intersection(int *arr1, int len1, int *arr2, int len2);

int main()
{
    int arr1[] = {1, 2, 3, 7, 9, 19, 25};
    int arr2[] = {19, 5, 6, 10, 3, 1};

    int *result = intersection(arr1, sizeof(arr1) / sizeof(int), arr2, sizeof(arr2) / sizeof(int));
    for (int i = 1; i < result[0] + 1; i++)
    {
        printf("%d\n", result[i]);
    }

    free(result);
}

int *intersection(int *arr1, int len1, int *arr2, int len2)
{
    std::map<int, int> counter;
    int count = 0;

    for (int i = 0; i < len1; i++)
    {
        // 非 0 ,NULL等即為 true
        if (counter[arr1[i]])
        {
            counter[arr1[i]]++;
            count++;
        }
        else
        {
            // counter[arr1[i]] == NULL
            counter[arr1[i]] = 1;
        }
    }

    for (int i = len1; i < len1 + len2; i++)
    {
        if (counter[arr2[i - len1]])
        {
            counter[arr2[i - len1]]++;
            count++;
        }
        else
        {
            counter[arr2[i - len1]] = 1;
        }
    }

    // result[0] = count 存有幾個相同數字
    int *result = (int *)malloc((count + 1) * sizeof(int));
    result[0] = count;
    int i = 1;

    for (std::map<int, int>::iterator iter = counter.begin(); iter != counter.end(); iter++)
    {
        if (iter->second > 1)
        {
            result[i] = iter->first;
            i++;
        }
    }
    return result;
}