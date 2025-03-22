#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Same as leetcode 3

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> posTable(256, -1);
        int ans = 0;
        for (int i = 0, j = 0; i < s.size(); ++i)
        {
            j = max(posTable[s[i]] + 1, j);
            ans = max(ans, i - j + 1);
            posTable[s[i]] = i;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    assert(s.lengthOfLongestSubstring("") == 0);
    assert(s.lengthOfLongestSubstring(" ") == 1);
    assert(s.lengthOfLongestSubstring("arabcacfr") == 4);
    return 0;
}