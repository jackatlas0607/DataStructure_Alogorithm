#include <iostream>
#include <vector>

void printArrayVector(std::vector<int> &arr);
std::vector<int> merge(std::vector<int> arr1, std::vector<int> arr2);
std::vector<int> mergeSort(std::vector<int> &arr);

int main()
{
    int arr1[] = {15, 3, 17, 18, 35, 11, 0, 36, -336, 1054};
    std::vector<int> array(arr1, arr1 + sizeof(arr1) / sizeof(int));
    std::vector<int> result = mergeSort(array);
    printArrayVector(result);
}

std::vector<int> mergeSort(std::vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return arr;
    }
    else
    {
        int middle = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + middle);
        std::vector<int> right(arr.begin() + middle, arr.end());
        return merge(mergeSort(left), mergeSort(right));
    }
}

std::vector<int> merge(std::vector<int> arr1, std::vector<int> arr2)
{
    std::vector<int> result;

    int index1 = 0;
    int index2 = 0;

    while (index1 < arr1.size() && index2 < arr2.size())
    {
        if (arr1[index1] < arr2[index2])
        {
            result.push_back(arr1[index1]);
            index1++;
        }
        else
        {
            result.push_back(arr2[index2]);
            index2++;
        }
    }

    while (index1 < arr1.size())
    {
        result.push_back(arr1[index1]);
        index1++;
    }

    while (index2 < arr2.size())
    {
        result.push_back(arr2[index2]);
        index2++;
    }
    return result;
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
            std::cout << arr[i] << "]";
        }
    }
}