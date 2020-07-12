/*
 * @lc app=leetcode id=122 lang=java
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
// class Solution {
//     public int maxProfit(int[] prices) {
//         if (prices == null || prices.length == 0) {
//             return 0;
//         }
//         int[][] dp = new int[prices.length + 1][2];
//         dp[0][0] = Integer.MIN_VALUE;
//         for (int i = 1; i <= prices.length; ++i) {
//             dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
//             dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);
//         }
//         return dp[prices.length][1];
//     }
// }

// class Solution {
//     public int maxProfit(int[] prices) {
//         if (prices == null || prices.length == 0) {
//             return 0;
//         }
//         int holdProfit = Integer.MIN_VALUE;
//         int unholdProfit = 0;
//         for (int i = 0; i < prices.length; ++i) {
//             int newHoldProfit = Math.max(holdProfit,unholdProfit-prices[i]);
//             int newUnholdProfit =Math.max(unholdProfit,holdProfit+prices[i]);
//             holdProfit = newHoldProfit;
//             unholdProfit = newUnholdProfit;
//         }
//         return unholdProfit;
//     }
// }

class Solution {
    //ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int profit = 0;
        for (int i = 1; i < prices.length; ++i) {
            profit += Math.max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
}
// @lc code=end
