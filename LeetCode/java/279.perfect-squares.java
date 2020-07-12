/*
 * @lc app=leetcode id=279 lang=java
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            int sqrt = (int) Math.sqrt(i);
            if (sqrt * sqrt == i) {
                dp[i] = 1;
            } else {
                for (int j = 1; j <= i / 2; ++j) {
                    dp[i] = Math.min(dp[i], dp[j] + dp[i - j]);
                }
            }
        }
        return dp[n];
    }
}

// Faster
class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = Math.min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
}
// @lc code=end
