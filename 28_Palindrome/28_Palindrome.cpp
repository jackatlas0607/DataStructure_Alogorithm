#include <iostream>
#include <string>

void palindrome(std::string str);

int main()
{
    std::string str1 = "tacocat";
    palindrome(str1);                    // true
    palindrome("amanaplanacanalpanama"); // true
    palindrome("asdfsafeaw");            // false
}

void palindrome(std::string str)
{
    int left = 0;
    int right = str.size() - 1;

    while (left <= right)
    {
        if (str[left] == str[right])
        {
            left++;
            right--;
        }
        else if (str[left] != str[right])
        {
            std::cout << "False" << std::endl;
            return;
        }
    }
    std::cout << "True" << std::endl;
}
