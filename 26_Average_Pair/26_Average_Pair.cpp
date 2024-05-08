#include <iostream>
#include <vector>
#include <array>

std::vector<std::array<int, 2>> average_pair(double *arr, int length, double avg);

int main()
{
    /*
    int arr[] = {11, 22, 33, 44};
    std::cout << "The Length of the Array is : " << std::end(arr) - std::begin(arr); // length
    */
    double arr[] = {-11, 0, 1, 2, 3, 9, 14, 17, 21};
    std::vector<std::array<int, 2>> result = average_pair(arr, std::end(arr) - std::begin(arr), 1.5);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << "[" << result[i][0] << "," << result[i][1] << "]" << std::endl;
    }
}

std::vector<std::array<int, 2>> average_pair(double *arr, int length, double avg)
{
    int left = 0;
    int right = length - 1;

    std::vector<std::array<int, 2>> result;
    while (left <= right)
    {
        double temp = (arr[left] + arr[right]) / 2;
        if (temp > avg)
        {
            right--;
        }
        else if (temp < avg)
        {
            left++;
        }
        else
        {
            std::array<int, 2> pair = {(int)arr[left], (int)arr[right]};
            result.push_back(pair);
            left++;
            right--;
        }
    }
    return result;
}