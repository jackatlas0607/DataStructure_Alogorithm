#include <iostream>
#include <string>
#include <map>

bool same_frequency(std::string str1, std::string str2);

int main()
{
    std::cout << same_frequency("aabb", "abab");
}

bool same_frequency(std::string str1, std::string str2)
{
    // You might see some C++ programs that use the size() function to get the length of a string.
    // This is just an alias of length().
    if (str1.length() != str2.length())
    {
        return false;
    }

    std::map<char, int> counter1;
    std::map<char, int> counter2;

    for (int i = 0; i < str1.size(); i++)
    {
        if (counter1[str1[i]])
        {
            counter1[str1[i]]++;
        }
        else
        {
            counter1[str1[i]] = 1;
        }
    }

    for (int i = 0; i < str2.size(); i++)
    {
        if (counter2[str2[i]])
        {
            counter2[str2[i]]++;
        }
        else
        {
            counter2[str2[i]] = 1;
        }
    }

    for (auto &t : counter1)
    {
        if (!counter2[t.first] || counter2[t.first] != t.second)
        {
            return false;
        }
    }
    return true;
}