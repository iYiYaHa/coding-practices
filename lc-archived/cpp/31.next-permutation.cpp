/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    2940
 * Dislikes: 1043
 * Total Accepted:    339.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class SolutionA
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
                --j;
            swap(nums[i], nums[j]);
        }
        reverseVector(nums, i + 1, nums.size() - 1);
    }

private:
    void reverseVector(vector<int> &nums, int i, int j)
    {
        while (i <= j)
        {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
};
// @lc code=end
