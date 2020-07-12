/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.72%)
 * Likes:    2905
 * Dislikes: 148
 * Total Accepted:    404.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() <= 0 || board[0].size() <= 0)
            return false;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (isExistHelper(board, i, j, visited, word, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool isExistHelper(const vector<vector<char>> &board, int row, int col,
                       vector<vector<bool>> &visited, const string &word, int pos)
    {
        if (pos == word.size())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        if (!visited[row][col] && board[row][col] == word[pos])
        {
            visited[row][col] = true;

            if (isExistHelper(board, row + 1, col, visited, word, pos + 1) ||
                isExistHelper(board, row - 1, col, visited, word, pos + 1) ||
                isExistHelper(board, row, col + 1, visited, word, pos + 1) ||
                isExistHelper(board, row, col - 1, visited, word, pos + 1))
                return true;

            visited[row][col] = false;
        }
        return false;
    }
};
// @lc code=end
