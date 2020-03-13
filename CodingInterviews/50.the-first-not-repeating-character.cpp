#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        vector<int> table(256, 0);
        for (char ch : str)
            table[ch] += 1;
        for (int i = 0; i < str.length(); ++i)
        {
            if (table[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    assert(s.FirstNotRepeatingChar(string("aabcbcbd")) == 7);
    assert(s.FirstNotRepeatingChar(string("aabcd")) == 2);
    assert(s.FirstNotRepeatingChar(string("")) == -1);
    return 0;
}