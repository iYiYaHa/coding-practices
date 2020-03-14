/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (50.34%)
 * Likes:    1407
 * Dislikes: 1804
 * Total Accepted:    389.5K
 * Total Submissions: 772.9K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

// @lc code=start
class SolutionA
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xorRes = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            xorRes = xorRes ^ i ^ nums[i];
        }
        return xorRes ^ nums.size();
    }
};

// ref:https://leetcode.com/problems/missing-number/discuss/69808/Java-solution%3A-Time-O(n)-Space-O(1)-no-XOR-no-Gauss'-math-method
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int diff = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            diff += (nums[i] - i);
        }
        return nums.size() - diff;
    }
};
// @lc code=end
