class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null || word == null || board.length == 0 ||
           board[0].length == 0 || word.equals(""))
            return false;
        int rows = board.length, cols = board[0].length;
        boolean[][] visited = new boolean[rows][cols];
        for(int i = 0;i < rows;++i){
            for(int j = 0;j < cols;++j){
                if(helper(board, visited, i, j, word, 0))return true;
            }
        }
        return false;
    }

    private boolean helper(char[][] board, boolean[][] visited, int row, int col, String word, int pos){
        if(pos >= word.length())
            return true;
        if(row < 0 || row >= board.length || col < 0 || col >= board[0].length)
            return false;
        if(!visited[row][col] && word.charAt(pos) == board[row][col]){
            visited[row][col] = true;
            if(helper(board,visited,row+1,col,word,pos+1)||
                        helper(board,visited,row-1,col,word,pos+1)||
                        helper(board,visited,row,col+1,word,pos+1)||
                        helper(board,visited,row,col-1,word,pos+1))
                return true;
            visited[row][col] = false;
        }
        return false;
    }
}