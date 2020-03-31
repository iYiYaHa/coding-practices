/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.78%)
 * Likes:    1884
 * Dislikes: 518
 * Total Accepted:    327.7K
 * Total Submissions: 994.7K
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
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return vector<int>();
        vector<int> ans;
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; 2 * i < rows && 2 * i < cols; ++i)
        {
            traverseCircle(matrix, rows, cols, i, ans);
        }
        return ans;
    }

private:
    void traverseCircle(const vector<vector<int>> &matrix, int rows, int cols, int start, vector<int> &ans)
    {
        if (start >= rows || start >= cols)
            return;
        int begRow = start;
        int begCol = start;
        int endRow = rows - begRow - 1;
        int endCol = cols - begCol - 1;
        for (int i = begCol; i <= endCol; ++i)
            ans.push_back(matrix[begRow][i]);
        for (int i = begRow + 1; i <= endRow; ++i)
            ans.push_back(matrix[i][endCol]);
        if (endRow > begRow)
            for (int i = endCol - 1; i >= begCol; --i)
                ans.push_back(matrix[endRow][i]);
        if (endCol > begCol)
            for (int i = endRow - 1; i >= begRow + 1; --i)
                ans.push_back(matrix[i][begCol]);
    }
};
// @lc code=end
