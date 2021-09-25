#include <iostream>
#include <vector>

using namespace std;

// Like a sliding window on the positive number sequence.
class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        int small = 1, big = 2;
        int curSum = 3;
        int mid = sum / 2;
        vector<vector<int>> ans;
        while (small <= mid)
        {
            if (curSum == sum)
            {
                vector<int> curAns;
                for (int i = small; i <= big; ++i)
                    curAns.push_back(i);
                ans.push_back(curAns);
            }
            if (curSum >= sum)
            {
                curSum -= small;
                ++small;
            }
            else
            {
                ++big;
                curSum += big;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    assert(s.FindContinuousSequence(15) == vector<vector<int>>({{1, 2, 3, 4, 5}, {4, 5, 6}, {7, 8}}));
    assert(s.FindContinuousSequence(100) == vector<vector<int>>({{9,10,11,12,13,14,15,16}, {18,19,20,21,22}}));
    return 0;
}