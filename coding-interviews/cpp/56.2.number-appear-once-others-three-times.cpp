#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        const int bitsNum = sizeof(int) * 8;
        vector<int> table(bitsNum, 0);

        for (int num : nums)
        {
            for (int i = bitsNum - 1; i >= 0; --i)
            {
                if ((num & (1 << i)) != 0)
                    table[i] += 1;
            }
        }
        int ans = 0;
        for (int i = bitsNum - 1; i >= 0; --i)
        {
            ans <<= 1;
            ans += table[i] % 3;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 3, 3};
    assert(s.singleNumber(nums) == 2);
    nums = {9, 1, 7, 9, 7, 9, 7};
    assert(s.singleNumber(nums) == 1);
    return 0;
}