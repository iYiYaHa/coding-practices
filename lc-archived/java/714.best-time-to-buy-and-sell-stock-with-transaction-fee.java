/*
 * @lc app=leetcode id=714 lang=java
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if (prices == null || prices.length == 0)
            return 0;
        int[] dp = new int[prices.length + 1];
        int maxPrev = -prices[0];
        for (int i = 2; i <= prices.length; ++i) {
            dp[i] = Math.max(dp[i - 1], maxPrev + prices[i - 1] - fee);
            maxPrev = Math.max(maxPrev, dp[i] - prices[i - 1]);
        }
        return dp[prices.length];
    }
}
// @lc code=end
