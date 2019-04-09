/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.30%)
 * Total Accepted:    191.2K
 * Total Submissions: 574.1K
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
 *
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 */
class SolutionA {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m <= 0)
      return 0;
    int n = obstacleGrid[0].size();
    if (n <= 0)
      return 0;
    vector<vector<long>> dp(m, vector<long>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        long left = i - 1 >= 0 ? dp[i - 1][j] : 0;
        long above = j - 1 >= 0 ? dp[i][j - 1] : 0;
        dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i][j] + left + above;
      }
    }
    return dp[m - 1][n - 1];
  }
};

class SolutionB {
  // better logic than solutionA
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m <= 0)
      return 0;
    int n = obstacleGrid[0].size();
    if (n <= 0)
      return 0;
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] =
            obstacleGrid[i - 1][j - 1] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};
class SolutionC {
  // Optimized on solutionB
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m <= 0)
      return 0;
    int n = obstacleGrid[0].size();
    if (n <= 0)
      return 0;
    vector<long> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else if (j > 0)
          dp[j] += dp[j - 1];
      }
    }
    return dp.back();
  }
};
