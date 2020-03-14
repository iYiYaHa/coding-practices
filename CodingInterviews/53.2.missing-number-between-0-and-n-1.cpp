#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left == nums.size() ? nums.size() : nums[left] - 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 3};
    assert(s.missingNumber(nums) == 2);
    nums = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    assert(s.missingNumber(nums) == 8);
    nums = {0, 1, 2};
    assert(s.missingNumber(nums) == 3);
    nums = {1, 2, 3};
    assert(s.missingNumber(nums) == 0);
    nums = {0, 1, 3};
    assert(s.missingNumber(nums) == 2);
    return 0;
}