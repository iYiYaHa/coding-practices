/*
 * @lc app=leetcode id=52 lang=java
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new LinkedList<>();
        if(n <= 0)
            return result;
        char[][] board = new char[n][n];
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                board[i][j] = '.';
            }
        }
        boolean[] columnOccupied = new boolean[n];
        nQueensCore(board, columnOccupied, 0, result);
        return result;
    }
    
    private void nQueensCore(char[][] board, boolean[] columnOccupied, int row, List<List<String>> result){
        if(row >= board.length){
            List<String> ans = new LinkedList<>();
            for(int i = 0;i < board.length;++i)
                ans.add(new String(board[i]));
            result.add(ans);
            return;
        }
        for(int col = 0;col < board[row].length;++col){
            if(checkOk(board, columnOccupied, row, col)){
                board[row][col] = 'Q';
                columnOccupied[col] = true;
                nQueensCore(board, columnOccupied, row+1, result);
                columnOccupied[col] = false;
                board[row][col] = '.';
            }
        }
    }
    
    private boolean checkOk(char[][] board, boolean[] columnOccupied, int row, int col){
        if(row < 0 || row > board.length || col < 0 || col > board[row].length)
            return false;
        // check column
        if(columnOccupied[col])
            return false;
        
        // check left diagonal
        for(int i = row-1, j = col-1; i >= 0 && j >= 0;--i,--j){
            if(board[i][j] == 'Q')
                return false;
        }
        
        // check right diagonal
        for(int i = row-1, j = col+1; i >= 0 && j < board[i].length;--i,++j){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    public int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
}
// @lc code=end

