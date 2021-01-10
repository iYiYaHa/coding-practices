/*
 * @lc app=leetcode id=54 lang=java
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (33.80%)
 * Likes:    2991
 * Dislikes: 612
 * Total Accepted:    420.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length <= 0 || matrix[0].length <= 0)
            return new LinkedList<>();
        int m = matrix.length, n = matrix[0].length;
        LinkedList<Integer> res = new LinkedList<>();
        for (int row = 0, col = 0; 2 * row < m && 2 * col < n; ++row, ++col) {
            fillWithBoundary(matrix, row, col, res);
        }
        return res;
    }

    private void fillWithBoundary(int[][] matrix, int row, int col, List<Integer> res) {
        int m = matrix.length, n = matrix[0].length;

        // top line
        for (int i = col; i <= n - col - 1; ++i) {
            res.add(matrix[row][i]);
        }

        // right line
        for (int i = row + 1; i < m - row - 1; ++i) {
            res.add(matrix[i][n - col - 1]);
        }

        if (m - row - 1 > row) {
            // bottom line
            for (int i = n - col - 1; i >= col; --i) {
                res.add(matrix[m - row - 1][i]);
            }
        }

        // left line
        if (n - col - 1 > col)
            for (int i = m - row - 2; i > row; --i) {
                res.add(matrix[i][col]);
            }
    }
}
// @lc code=end
