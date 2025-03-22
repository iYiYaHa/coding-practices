/*
 * @lc app=leetcode id=123 lang=java
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int[][] dp = new int[prices.length + 1][4];
        // dp[i][0] first time hold
        // dp[i][1] first time unhold
        // dp[i][2] second time hold
        // dp[i][3] second time unhold
        dp[0][0] = Integer.MIN_VALUE;
        dp[0][2] = Integer.MIN_VALUE;
        for (int i = 1; i <= prices.length; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], -prices[i - 1]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);
            dp[i][2] = Math.max(dp[i - 1][2], dp[i - 1][1] - prices[i - 1]);
            dp[i][3] = Math.max(dp[i - 1][3], dp[i - 1][2] + prices[i - 1]);
        }
        return Math.max(dp[prices.length][1], dp[prices.length][3]);
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int[] dp = new int[4];
        dp[0] = Integer.MIN_VALUE;
        dp[2] = Integer.MIN_VALUE;
        for (int i = 1; i <= prices.length; ++i) {
            dp[3] = Math.max(dp[3], dp[2] + prices[i - 1]);
            dp[2] = Math.max(dp[2], dp[1] - prices[i - 1]);
            dp[1] = Math.max(dp[1], dp[0] + prices[i - 1]);
            dp[0] = Math.max(dp[0], -prices[i - 1]);
        }
        return Math.max(dp[1], dp[3]);
    }
}
// @lc code=end
