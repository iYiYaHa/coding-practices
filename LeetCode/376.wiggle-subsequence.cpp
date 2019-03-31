/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (37.06%)
 * Total Accepted:    45K
 * Total Submissions: 121.4K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The
 * first difference (if one exists) may be either positive or negative. A
 * sequence with fewer than two elements is trivially a wiggle sequence.
 * 
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
 * (6,-3,5,-7,3) are alternately positive and negative. In contrast,
 * [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
 * first two differences are positive and the second because its last
 * difference is zero.
 * 
 * Given a sequence of integers, return the length of the longest subsequence
 * that is a wiggle sequence. A subsequence is obtained by deleting some number
 * of elements (eventually, also zero) from the original sequence, leaving the
 * remaining elements in their original order.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is
 * [1,17,10,13,10,16,8].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * Follow up:
 * Can you do it in O(n) time?
 * 
 * 
 * 
 */

// ref:https://leetcode.com/problems/wiggle-subsequence/solution/
class SolutionA
{
    // DP
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, 0));
        for (int i = 1; i <= nums.size(); ++i)
        {
            dp[i][0] = dp[i][1] = 1;
            for (int j = i - 1; j >= 1; --j)
            {
                dp[i][0] = std::max(nums[i - 1] > nums[j - 1] ? dp[j][1] + 1 : 0, dp[i][0]);
                dp[i][1] = std::max(nums[i - 1] < nums[j - 1] ? dp[j][0] + 1 : 0, dp[i][1]);
            }
        }
        return std::max(dp.back()[0], dp.back()[1]);
    }
};

class SolutionB
{
    // linear dp
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = up[i - 1] + 1;
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up.back(), down.back());
    }
};

class SolutionC
{
    // Optimized linear DP. Or greedy algorithm
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int p = 1, q = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
                p = q + 1;
            else if (nums[i] < nums[i - 1])
                q = p + 1;
        }
        return max(p, q);
    }
};

class Solution
{
    // Actually I don't think this approach is a greedy algorithm because there no direct optimal substructure in this approach.
    // It's just finding all inflection points.
    // trend == 0 means we are at the beginning of nums(may be with consecutive same numbers.)
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int trend = 0;
        int len = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1] && trend != 1)
            {
                trend = 1;
                ++len;
            }
            else if (nums[i] < nums[i - 1] && trend != -1)
            {
                trend = -1;
                ++len;
            }
        }
        return len;
    }
};