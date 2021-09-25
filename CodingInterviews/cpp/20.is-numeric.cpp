#include <iostream>

using namespace std;

class Solution
{
public:
    bool isNumeric(const char *str)
    {
        if (str == nullptr)
            return false;

        bool flag = findSigned(&str);
        if (*str == '.')
        {
            ++str;
            flag = findUnsigned(&str) || flag;
        }
        if (*str == 'E' || *str == 'e')
        {
            ++str;
            flag = findSigned(&str) && flag;
        }
        return *str == '\0' && flag;
    }

private:
    bool findSigned(const char **str)
    {
        if (**str == '+' || **str == '-')
            ++(*str);
        return findUnsigned(str);
    }

    bool findUnsigned(const char **str)
    {
        const char *beg = *str;
        while (**str != '\0' && **str >= '0' && **str <= '9')
            ++(*str);
        return (*str)>beg;
    }
};

int main()
{
    Solution s;
    char string[] = ".456a123";
    cout << string << " ";
    if (s.isNumeric(string))
    {
        cout << "is numeric.\n";
    }
    else
    {
        cout << "is not numeric.\n";
    }
}