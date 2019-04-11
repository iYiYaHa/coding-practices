/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (32.60%)
 * Total Accepted:    123.7K
 * Total Submissions: 379.6K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Output: 4
 *
 */
class Solution {
    // Dynamic Programming
    // It can be optimized to use less space.
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int n = matrix.size();
    if (n <= 0)
      return 0;
    int m = matrix[0].size();
    if (m <= 0)
      return 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (matrix[i - 1][j - 1] == '1')
          dp[i][j] =std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) +1;
        else
          dp[i][j] = 0;
        maxLen = std::max(maxLen,dp[i][j]);
      }
    }
    return maxLen*maxLen;
  }
};
