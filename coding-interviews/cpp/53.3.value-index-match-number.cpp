#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getNumberAsIndex(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid)
                return mid;
            else if (nums[mid] < mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {};
    nums = {-3, -1, 1, 3, 5};
    assert(s.getNumberAsIndex(nums) == 3);
    nums = {-5, -1, 0, 1, 4};
    assert(s.getNumberAsIndex(nums) == 4);
    return 0;
}