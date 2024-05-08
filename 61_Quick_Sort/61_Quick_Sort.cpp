#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int p, int r);
void quickSort(std::vector<int> &arr, int p, int r);
void printArrayVector(std::vector<int> &arr);

int main()
{
    int arr[] = {15, 3, 17, -17, 18, 20, 2, 1, 666};
    std::vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    printArrayVector(array);
    quickSort(array, 0, array.size() - 1);
    printArrayVector(array);
}

int partition(std::vector<int> &arr, int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
}

void quickSort(std::vector<int> &arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
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