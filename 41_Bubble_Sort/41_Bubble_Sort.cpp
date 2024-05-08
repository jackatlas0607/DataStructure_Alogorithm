#include "Array_function.h"
#include "Array_function.cpp"

// void fillArray(int *arr, int length);
void bubbleSort(int *arr, int length);
void bubbleSort_v2(int *arr, int length);
// void printArray(int *arr, int length);

int main()
{
    int arr1[10];
    int arr2[10];

    fillArray(arr1, sizeof(arr1) / sizeof(int));
    printArray(arr1, sizeof(arr1) / sizeof(int));
    bubbleSort(arr1, sizeof(arr1) / sizeof(int));
    printArray(arr1, sizeof(arr1) / sizeof(int));

    std::cout << "***************************************" << std::endl;

    fillArray(arr2, sizeof(arr2) / sizeof(int));
    printArray(arr2, sizeof(arr2) / sizeof(int));
    bubbleSort_v2(arr2, sizeof(arr2) / sizeof(int));
    printArray(arr2, sizeof(arr2) / sizeof(int));
}

void bubbleSort(int *arr, int length)
{
    /*
    每一輪都把一個最小(大)的值丟到左(右)邊
    只需要arr.length()-1輪，因為剩一個的時候一釘在正確位置
    */

    // 每一輪都把小的丟到左邊
    for (int i = length - 1; i > 0; i--)
    {
        for (int j = length - 1; j > length - i - 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void bubbleSort_v2(int *arr, int length)
{
    // 每一輪都把大的丟到右邊
    for (int i = 0; i < length - 1; i++)
    {
        // 可以做的優化，當沒element在交換，就表示已經排好了，可以提早結束
        bool swapping = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapping = true;
            }
        }
        if (!swapping)
        {
            break;
        }
    }
}