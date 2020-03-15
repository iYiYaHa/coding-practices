#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string ReverseSentence(string str)
    {
        reverseString(str, 0, str.length() - 1);
        for (int beg = 0, end = 0; end <= str.length(); ++end)
        {
            if (end == str.length() || str[end] == ' ')
            {
                reverseString(str, beg, end - 1);
                beg = end + 1;
            }
        }
        return str;
    }

private:
    void reverseString(string &str, int left, int right)
    {
        while (left < right)
        {
            char tmp = str[left];
            str[left] = str[right];
            str[right] = tmp;
            ++left;
            --right;
        }
    }
};

int main()
{
    Solution s;
    assert(s.ReverseSentence("Hello World!") == "World! Hello");
    assert(s.ReverseSentence("I am a student.") == "student. a am I");
    return 0;
}