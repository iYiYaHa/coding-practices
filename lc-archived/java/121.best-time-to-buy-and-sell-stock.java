/*
 * @lc app=leetcode id=121 lang=java
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.length; ++i) {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        return maxProfit;
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0)
            return 0;
        int maxProfit = 0;
        int curProfit = 0;
        for (int i = 1; i < prices.length; ++i) {
            curProfit = curProfit + prices[i] - prices[i - 1];
            maxProfit = Math.max(curProfit, maxProfit);
            curProfit = curProfit < 0 ? 0 : curProfit;
        }
        return maxProfit;
    }
}
// @lc code=end
