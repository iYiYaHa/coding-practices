/*
 * @lc app=leetcode id=198 lang=java
 *
 * [198] House Robber
 */

// @lc code=start
class SolutionA {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int[] dp = new int[nums.length + 1];
        dp[1] = nums[0];
        for (int i = 2; i <= nums.length; ++i) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.length];
    }
}

class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;

        int prev = 0;
        int cur = nums[0];
        for (int i = 2; i <= nums.length; ++i) {
            int next = Math.max(prev + nums[i - 1], cur);
            prev = cur;
            cur = next;
        }
        return cur;
    }
}
// @lc code=end
