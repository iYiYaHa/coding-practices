/*
 * @lc app=leetcode id=309 lang=java
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int[][] dp = new int[prices.length + 1][2];
        // dp[x][0] hold, dp[x][1] unhold.
        dp[0][0] = Integer.MIN_VALUE;
        for (int i = 1; i <= prices.length; ++i) {
            int prevUnhold = i - 2 >= 0 ? dp[i - 2][1] : 0;
            dp[i][0] = Math.max(dp[i - 1][0], prevUnhold - prices[i - 1]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);
        }
        return dp[prices.length][1];
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int[] dp = new int[prices.length + 1];
        int maxPrev = -prices[0];
        for (int i = 2; i <= prices.length; ++i) {
            dp[i] = Math.max(dp[i-1], prices[i - 1] + maxPrev);
            maxPrev = Math.max(maxPrev, dp[i - 2] - prices[i - 1]);
        }
        return dp[prices.length];
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int[][] dp = new int[prices.length + 1][3];
        // dp[i][0] hold
        // dp[i][1] cooldown
        // dp[i][2] unhold
        dp[0][0] = Integer.MIN_VALUE;
        for (int i = 1; i <= prices.length; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i - 1];
        }
        return Math.max(dp[prices.length][1], dp[prices.length][2]);
    }
}
// @lc code=end
