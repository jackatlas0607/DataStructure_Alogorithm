#include "../41_Bubble_Sort/Array_function.h"
#include "../41_Bubble_Sort/Array_function.cpp"

void selectionSort(int *arr, int length);

int main()
{
    int arr[] = {14, -4, 17, 6, 22, 1, -5};
    int length = sizeof(arr) / sizeof(int);
    selectionSort(arr, length);
    printArray(arr, length);
}

void selectionSort(int *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < length; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
