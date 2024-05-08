#include <iostream>
#include <vector>

void buildMaxHeap(std::vector<int> &arr);
void printArrayVector(std::vector<int> &arr);
void maxHeapify(std::vector<int> &arr, int heapSize, int i);
void heapSort(std::vector<int> &arr);

int main()
{
    int arr1[] = {4, 1, 6, 10, 11, 3, 2, 14, 5, 13, 9, 7, 8, 12, 15};
    std::vector<int> array1(arr1, arr1 + sizeof(arr1) / sizeof(int));

    int arr2[] = {13, 12, 15, 3, 1, 4, 7, 9, 10, 6, 8, 5, 11, 2, 14};
    std::vector<int> array2(arr2, arr2 + sizeof(arr2) / sizeof(int));

    buildMaxHeap(array1);
    printArrayVector(array1);
    heapSort(array1);
    printArrayVector(array1);

    std::cout << "***************************************" << std::endl;

    buildMaxHeap(array2);
    printArrayVector(array2);
    heapSort(array2);
    printArrayVector(array2);

    std::cout << "***************************************" << std::endl;

    int arr3[] = {15, 3, 17, 18, 20, 2, 1, 666};
    std::vector<int> array3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    buildMaxHeap(array3);
    printArrayVector(array3);
    heapSort(array3);
    printArrayVector(array3);
}

void heapSort(std::vector<int> &arr)
{
    buildMaxHeap(arr);
    int heapSize = arr.size() - 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapSize--;
        maxHeapify(arr, heapSize, 0);
    }
}

void buildMaxHeap(std::vector<int> &arr)
{
    int heapSize = arr.size() - 1;
    for (int i = arr.size() / 2; i >= 0; i--)
    {
        maxHeapify(arr, heapSize, i);
    }
}

void maxHeapify(std::vector<int> &arr, int heapSize, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l <= heapSize && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r <= heapSize && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, heapSize, largest);
    }
}

void printArrayVector(std::vector<int> &arr)
{
    std::cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i < arr.size() - 1)
        {
            std::cout << arr[i] << ", ";
        }
        else
        {
            std::cout << arr[i] << "]" << std::endl;
        }
    }
}