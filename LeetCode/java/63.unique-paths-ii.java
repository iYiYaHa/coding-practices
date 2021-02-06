/*
 * @lc app=leetcode id=63 lang=java
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (35.16%)
 * Likes:    2397
 * Dislikes: 274
 * Total Accepted:    346.1K
 * Total Submissions: 984K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * An obstacle and space is marked as 1 and 0 respectively in the grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length, m = obstacleGrid[0].length;

        int[][] dp = new int[n + 1][m + 1];
        dp[0][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (obstacleGrid[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }
}
// @lc code=end
