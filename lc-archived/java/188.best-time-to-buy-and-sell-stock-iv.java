/*
 * @lc app=leetcode id=188 lang=java
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length == 0 || k <= 0) {
            return 0;
        }
        int[][] dp = new int[prices.length + 1][2 * k];
        for (int i = 0; i < 2 * k; ++i) {
            dp[0][i] = (i & 1) == 1 ? 0 : Integer.MIN_VALUE;
        }
        // even:hold
        // odd:unhold
        for (int i = 1; i <= prices.length; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], -prices[i - 1]);
            for (int j = 1; j < 2 * k; ++j) {
                if ((j & 1) == 1) {// Unhold
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i - 1]);
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i - 1]);
                }
            }
        }
        int maxProfit = 0;
        for (int i = 0; i < 2 * k; ++i) {
            maxProfit = Math.max(maxProfit, dp[prices.length][i]);
        }
        return maxProfit;
    }
}

class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length == 0 || k <= 0) {
            return 0;
        }
        if (k >= prices.length / 2) {
            return quickSolve(prices);
        }
        int[] dp = new int[2 * k];
        for (int i = 0; i < 2 * k; ++i) {
            dp[i] = (i & 1) == 1 ? 0 : Integer.MIN_VALUE;
        }
        // even:hold
        // odd:unhold
        for (int i = 1; i <= prices.length; ++i) {
            for (int j = 2 * k - 1; j >= 1; --j) {
                if ((j & 1) == 1) {// Unhold
                    dp[j] = Math.max(dp[j], dp[j - 1] + prices[i - 1]);
                } else {
                    dp[j] = Math.max(dp[j], dp[j - 1] - prices[i - 1]);
                }
            }
            dp[0] = Math.max(dp[0], -prices[i - 1]);
        }
        int maxProfit = 0;
        for (int i = 0; i < 2 * k; ++i) {
            maxProfit = Math.max(maxProfit, dp[i]);
        }
        return maxProfit;
    }

    private int quickSolve(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int len = prices.length, profit = 0;
        for (int i = 1; i < len; i++)
            // as long as there is a price gap, we gain a profit.
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;

    }
}

class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        if (k >= prices.length / 2) {
            return quickSolve(prices);
        }
        int[][] dp = new int[prices.length + 1][k + 1];
        for (int j = 1; j <= k; ++j) {
            int tmpMax = -prices[0];
            for (int i = 2; i <= prices.length; ++i) {
                dp[i][j] = Math.max(dp[i - 1][j], tmpMax + prices[i - 1]);
                tmpMax = Math.max(tmpMax, dp[i - 1][j - 1] - prices[i - 1]);
            }
        }
        return dp[prices.length][k];
    }

    private int quickSolve(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int maxProfit = 0;
        for (int i = 1; i < prices.length; ++i) {
            maxProfit += Math.max(0, prices[i] - prices[i - 1]);
        }
        return maxProfit;
    }
}

