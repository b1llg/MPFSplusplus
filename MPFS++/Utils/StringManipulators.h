#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

bool String_Contains(std::string hay, std::string needle)
{
    return (hay.find(needle) != std::string::npos);
}

std::vector<std::string> String_Split(std::string str, char delim = '_')
{
    std::string temp;
    std::vector<std::string> res;


    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != delim)
        {
            temp.push_back(str[i]);
        }
        else
        {
            res.push_back(temp);
            temp.clear();
        }

    }
    res.push_back(temp);

    std::cout << std::endl;

    return res;

}
