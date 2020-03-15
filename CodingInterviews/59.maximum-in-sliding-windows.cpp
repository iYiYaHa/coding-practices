#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Leetcode 239.
class SolutionA
{
public:
    vector<int> maxInWindows(const vector<int> &nums, unsigned int size)
    {
        deque<int> maximum;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!maximum.empty() && maximum.front() == i - size) // Pop out the element out of the window
            {
                maximum.pop_front();
            }

            while (!maximum.empty() && nums[maximum.back()] <= nums[i]) // Pop out tthe elements with values smaller than nums[i]
            {
                maximum.pop_back();
            }
            maximum.push_back(i);

            if (i >= size - 1) //For any full sliding windows, output the maximum.
                ans.push_back(nums[maximum.front()]);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &nums, unsigned int size)
    {
        vector<int> ans;
        if(size == 0) return ans;
        vector<int> left(nums.size() + 1, 0);
        vector<int> right(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            left[i] = i % size == 0 ? nums[i] : max(left[i - 1], nums[i]);
            int j = nums.size() - i - 1;
            right[j] = j % size == 0 ? nums[j] : max(right[j + 1], nums[j]);
        }
        for( int i = size-1;i<nums.size();++i){
            ans.push_back(max(left[i],right[i-size+1]));
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {};
    nums = {2, 3, 4, 2, 6, 2, 5, 1};
    assert(s.maxInWindows(nums, 3) == vector<int>({4, 4, 6, 6, 6, 5}));
    nums = {};
    assert(s.maxInWindows(nums, 3) == vector<int>({}));
    return 0;
}