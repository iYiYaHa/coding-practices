//Given an m x n matrix board containing 'X' and 'O', capture all regions that 
//are 4-directionally surrounded by 'X'. 
//
// A region is captured by flipping all 'O's into 'X's in that surrounded 
//region. 
//
// 
// Example 1: 
//
// 
//Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X",
//"O","X","X"]]
//Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X",
//"X"]]
//Explanation: Surrounded regions should not be on the border, which means that 
//any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not 
//on the border and it is not connected to an 'O' on the border will be flipped to 
//'X'. Two cells are connected if they are adjacent cells connected horizontally 
//or vertically.
// 
//
// Example 2: 
//
// 
//Input: board = [["X"]]
//Output: [["X"]]
// 
//
// 
// Constraints: 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 200 
// board[i][j] is 'X' or 'O'. 
// 
// Related Topics Array Depth-First Search Breadth-First Search Union Find 
//Matrix 👍 4105 👎 1000


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }
        int rows = board.length;
        int cols = board[0].length;
        for (int i = 0; i < rows; ++i) {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int i = 1; i < cols; ++i) {
            dfs(board, 0, i);
            dfs(board, rows - 1, i);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                board[i][j] = board[i][j] == 'V' ? 'O' : 'X';
            }
        }
    }

    private void dfs(char[][] board, int i, int j) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length) {
            return;
        }
        if (board[i][j] == 'X' || board[i][j] == 'V') {
            return;
        }
        board[i][j] = 'V';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
}

class Solution {

    class UnionFind {
        private int[] parent;
        private int[] size;

        UnionFind(int n, int m) {
            parent = new int[n * m + 1];
            size = new int[n * m + 1];
            for (int i = 0; i < parent.length; ++i) {
                parent[i] = i;
            }
        }

        int findParent(int i) {
            while (parent[i] != parent[parent[i]]) {
                parent[i] = parent[parent[i]];
            }
            return parent[i];
        }

        void union(int i, int j) {
            int rootI = findParent(i);
            int rootJ = findParent(j);
            if (rootI == rootJ) {
                return;
            }
            int sizeI = size[rootI];
            int sizeJ = size[rootJ];
            if (sizeI <= sizeJ) {
                parent[rootI] = parent[rootJ];
                size[rootJ] += sizeI;
            } else {
                parent[rootJ] = parent[rootI];
                size[rootI] += sizeJ;
            }
        }
    }

    public void solve(char[][] board) {
        if (board == null || board.length <= 0 || board[0].length <= 0) {
            return;
        }
        int rows = board.length;
        int cols = board[0].length;
        UnionFind uf = new UnionFind(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                        uf.union(i * cols + j, rows * cols);
                    } else {
                        if (board[i + 1][j] == 'O') {
                            uf.union((i + 1) * cols + j, i * cols + j);
                        }
                        if (board[i - 1][j] == 'O') {
                            uf.union((i - 1) * cols + j, i * cols + j);
                        }
                        if (board[i][j + 1] == 'O') {
                            uf.union(i * cols + (j + 1), i * cols + j);
                        }
                        if (board[i][j - 1] == 'O') {
                            uf.union(i * cols + (j - 1), i * cols + j);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (uf.findParent(i * cols + j) != uf.findParent(rows * cols)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
