/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (33.09%)
 * Likes:    2230
 * Dislikes: 753
 * Total Accepted:    420.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */

// @lc code=start
class SolutionA
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() == 0 || k % nums.size() == 0)
            return;
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

private:
    void reverse(vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            ++left;
            --right;
        }
    }
};

// Move from the front to the back until all elements have moved.
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() == 0 || k % nums.size() == 0)
            return;
        k = k % nums.size();

        int cnt = 0;
        for (int i = 0; cnt < nums.size(); ++i)
        {
            int prev = nums[i];
            int cur = i;
            do
            {
                int nextInd = (cur + k) % nums.size();
                int tmp = nums[nextInd];
                nums[nextInd] = prev;
                prev = tmp;
                cur = nextInd;
                ++cnt;
            } while (cur != i);
        }
    }
};
// @lc code=end
