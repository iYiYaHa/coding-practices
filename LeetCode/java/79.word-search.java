/*
 * @lc app=leetcode id=79 lang=java
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null||word==null||board.length<=0||board[0].length<=0)
            return false;
        for(int i = 0;i<board.length;++i){
            for(int j = 0;j<board[i].length;++j){
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int row, int col, int pos){
        if(pos>=word.length())
            return true;
        if(row<0||row>=board.length||col<0||col>=board[0].length)
            return false;
        if(board[row][col] == word.charAt(pos)){
            char old = board[row][col];
            board[row][col] = 0;
            if(dfs(board,word,row+1,col,pos+1)||
               dfs(board,word,row-1,col,pos+1)||
               dfs(board,word,row,col+1,pos+1)||
               dfs(board,word,row,col-1,pos+1))
                return true;
            board[row][col] = old;
        }
        return false;
    }
}
// @lc code=end

