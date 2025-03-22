/*
 * @lc app=leetcode id=59 lang=java
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (53.27%)
 * Likes:    1484
 * Dislikes: 125
 * Total Accepted:    236.5K
 * Total Submissions: 412.4K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[][] generateMatrix(int n) {
        if (n <= 0)
            return null;
        int[][] matrix = new int[n][n];
        int nextNum = 1;
        for (int pos = 0; 2 * pos < n; ++pos) {
            nextNum = fillWithBoundary(matrix, pos, pos, nextNum);
        }
        return matrix;
    }

    private int fillWithBoundary(int[][] matrix, int row, int col, int counter) {
        int m = matrix.length, n = matrix[0].length;
        // top line
        for (int i = col; i <= n - col - 1; ++i) {
            matrix[row][i] = counter++;
        }

        // right line
        for (int i = row + 1; i < m - row - 1; ++i) {
            matrix[i][n - col - 1] = counter++;
        }

        if (m - row - 1 > row) {
            // bottom line
            for (int i = n - col - 1; i >= col; --i) {
                matrix[m - row - 1][i] = counter++;
            }
        }

        // left line
        if (n - col - 1 > col)
            for (int i = m - row - 2; i > row; --i) {
                matrix[i][col] = counter++;
            }
        return counter;
    }
}
// @lc code=end
