#include <iostream>
#include <string>

void isSubsequence(std::string str1, std::string str2);

int main()
{
    isSubsequence("hello", "hello Dear"); // true
    isSubsequence("book", "brooklyn");    // true
    isSubsequence("abc", "bac");          // false (order matters)
    isSubsequence("abc", "abc");          // true
    isSubsequence("", "abc");             // true
}

void isSubsequence(std::string str1, std::string str2)
{
    int pointer1 = 0;
    int pointer2 = 0;

    while (pointer2 < str2.length())
    {
        if (str1[pointer1] == str2[pointer2])
        {
            pointer1++;
        }

        pointer2++;

        if (pointer1 >= str1.length())
        {
            std::cout << "true" << std::endl;
            return;
        }
    }
    std::cout << "false" << std::endl;
}