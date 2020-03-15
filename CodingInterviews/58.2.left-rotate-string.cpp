#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        int len = str.length();
        if (len == 0 || n == 0)
            return str;
        reverseString(str, 0, n - 1);
        reverseString(str, n, len - 1);
        reverseString(str, 0, len - 1);
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
    assert(s.LeftRotateString("abcdefg", 2) == "cdefgab");
    assert(s.LeftRotateString("", 6) == "");
    return 0;
}