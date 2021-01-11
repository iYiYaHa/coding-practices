/*
 * @lc app=leetcode id=64 lang=java
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (54.01%)
 * Likes:    4064
 * Dislikes: 78
 * Total Accepted:    493.4K
 * Total Submissions: 883.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length <= 0 || grid[0].length <= 0)
            return 0;
        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1) {
                    dp[i][j] = grid[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
}
// @lc code=end
