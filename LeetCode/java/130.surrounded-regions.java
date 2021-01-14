/*
 * @lc app=leetcode id=130 lang=java
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (27.76%)
 * Likes:    2408
 * Dislikes: 734
 * Total Accepted:    276.4K
 * Total Submissions: 948.4K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
class Solution {
    public void solve(char[][] board) {
        if(board == null || board.length <= 0 || board[0].length <= 0)
            return;
        int n = board.length, m = board[0].length;
        for(int i = 0; i < n; ++i){
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for(int i = 0; i < m; ++i){
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    private void dfs(char[][] board, int row, int col){
        if(row < 0 || col < 0 || row >= board.length || col >= board[row].length)
            return;
        if(board[row][col] == 'X' || board[row][col] == '#')
            return;
        board[row][col] = '#';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
}

class Solution {
    
    class UnionFind{
        private int[] parent;
        private int[] size;
        
        UnionFind(int n){
            parent = new int[n];
            size = new int[n];
            for(int i = 0; i < n; ++i){
                parent[i] = i;
            }
        }
        
        public void union(int i, int j){
            int rootI = getRoot(i);
            int rootJ = getRoot(j);
            if(rootI == rootJ)
                return;
            int sizeI = size[rootI];
            int sizeJ = size[rootJ];
            if(sizeI <= sizeJ){
                parent[rootI] = rootJ;
                size[rootJ] += size[rootI];
            }else{
                parent[rootJ] = rootI;
                size[rootI] += size[rootJ];
            }
        }
        
        public int getRoot(int i){
            while(i != parent[i]){
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        }
    }
    
    public void solve(char[][] board) {
        if(board == null || board.length <= 0 || board[0].length <= 0)
            return;
        int n = board.length, m = board[0].length;
        UnionFind uf = new UnionFind(n * m + 1);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'O'){
                    if(i == 0 || i == n-1 || j == 0 || j == m - 1 )
                        uf.union(i * m + j, n * m);
                    else{
                        if(board[i+1][j] == 'O')
                            uf.union(i * m + j, (i+1) * m + j);
                        if(board[i-1][j] == 'O')
                            uf.union(i * m + j, (i-1) * m + j);
                        if(board[i][j+1] == 'O')
                            uf.union(i * m + j, i * m + (j+1));
                        if(board[i][j-1] == 'O')
                            uf.union(i * m + j, i * m + (j-1));
                    }
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(uf.getRoot(i*m+j) != uf.getRoot(n*m)){
                    board[i][j] = 'X';
                }
            }
        }
    }
}

// @lc code=end

