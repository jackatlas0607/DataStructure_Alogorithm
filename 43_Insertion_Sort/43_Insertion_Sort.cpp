#include "../41_Bubble_Sort/Array_function.h"
#include "../41_Bubble_Sort/Array_function.cpp"

void insertionSort(int *arr, int length);

int main()
{
    int arr[] = {14, -4, 17, 6, 22, 1, -5};
    int length = sizeof(arr) / sizeof(int);
    insertionSort(arr, length);
}

void insertionSort(int *arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1; // 指向和 key 比大小的 index, key都和他左邊的比, 找到適合的位子
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
            // printArray(arr, length);
        }
        arr[j + 1] = key;
        printArray(arr, length);
    }
}