#include <iostream>
#include <limits.h>
#include <string>
#include <map>

int uniqueLetterString(std::string str);
int uniqueLetterString_v2(std::string str); // 比較好

int main()
{
    std::cout << uniqueLetterString("thisishowwedoit") << std::endl;    // 6  wedoit
    std::cout << uniqueLetterString_v2("thisishowwedoit") << std::endl; // 6  wedoit
}

int uniqueLetterString(std::string str)
{
    std::map<char, int> counter;   // 記錄該substring 每一個 char的 出現次數
    std::map<char, int> charIndex; // 記錄該substring 每一個 char的 index
    int left = 0;
    int right = 0;
    int length = 0;

    // babcadef  6
    while (right < str.length())
    {
        if (counter[str[right]])
        {
            counter[str[right]]++;
        }
        else
        {
            counter[str[right]] = 1;
            charIndex[str[right]] = right;
        }

        int tempLength = right - left + 1;

        if (counter[str[right]] >= 2)
        {
            left = charIndex[str[right]] + 1;

            if (tempLength - 1 > length)
            {
                length = tempLength;
            }

            for (int i = 0; i < charIndex[str[right]]; i++)
            {
                counter[str[i]] = 0;
                charIndex[str[i]] = NULL;
            }

            charIndex[str[right]] = right;
        }
        else
        {
            if (tempLength > length)
            {
                length = tempLength;
            }
        }
        right++;
    }
    return length;
}

int uniqueLetterString_v2(std::string str)
{
    std::map<char, int> counter; // 記錄該substring 每一個 char的 出現次數
    int left = 0;
    int right = 0;
    int length = 0;

    // babcadef
    while (right < str.length())
    {
        if (counter[str[right]])
        {
            counter[str[right]]++;
        }
        else
        {
            counter[str[right]] = 1;
        }

        while (counter[str[right]] >= 2)
        {
            counter[str[left]]--;
            left++;
        }

        int tempLength = right - left + 1;
        if (tempLength > length)
        {
            length = tempLength;
        }
        right++;
    }
    return length;
}