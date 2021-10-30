//Given an m x n integers matrix, return the length of the longest increasing 
//path in matrix. 
//
// From each cell, you can either move in four directions: left, right, up, or 
//down. You may not move diagonally or move outside the boundary (i.e., wrap-
//around is not allowed). 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//Output: 4
//Explanation: The longest increasing path is [1, 2, 6, 9].
// 
//
// Example 2: 
//
// 
//Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//Output: 4
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally 
//is not allowed.
// 
//
// Example 3: 
//
// 
//Input: matrix = [[1]]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// 0 <= matrix[i][j] <= 2³¹ - 1 
// 
// Related Topics Dynamic Programming Depth-First Search Breadth-First Search 
//Graph Topological Sort Memoization 👍 4307 👎 73


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    private static int[][] DIRECTIONS = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1},
    };

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length <= 0 || matrix[0].length <= 0) {
            return 0;
        }
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] memo = new int[n][m];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = Math.max(ans, longestIncreasingPath(matrix, i, j, memo));
            }
        }
        return ans;
    }

    private int longestIncreasingPath(int[][] matrix, int row, int col, int[][] memo) {
        if (memo[row][col] != 0) {
            return memo[row][col];
        }
        int subAns = 0;
        for (int[] direction : DIRECTIONS) {
            int neighborRow = row + direction[0];
            int neighborCol = col + direction[1];

            if (isValidNeighbor(matrix, row, col, neighborRow, neighborCol)) {
                subAns = Math.max(subAns, longestIncreasingPath(matrix, neighborRow, neighborCol, memo));
            }
        }
        int ans = 1 + subAns;
        memo[row][col] = ans;
        return ans;
    }

    private boolean isValidNeighbor(int[][] matrix, int curRow, int curCol, int neighborRow, int neighborCol) {
        if (neighborRow < 0 || neighborRow >= matrix.length) {
            return false;
        }
        if (neighborCol < 0 || neighborCol >= matrix[0].length) {
            return false;
        }
        return matrix[curRow][curCol] < matrix[neighborRow][neighborCol];
    }
}

class Solution {
    private static int[][] DIRECTIONS = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1},
    };

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length <= 0 || matrix[0].length <= 0) {
            return 0;
        }
        int numRows = matrix.length;
        int numCols = matrix[0].length;
        int[][] degree = new int[numRows][numCols];

        // count the degrees of each node
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                for (int[] direction : DIRECTIONS) {
                    int neighborRow = row + direction[0];
                    int neighborCol = col + direction[1];
                    if (isValidNeighbor(matrix, row, col, neighborRow, neighborCol)) {
                        ++degree[row][col];
                    }
                }
            }
        }

        Queue<int[]> queue = new LinkedList<>();
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (degree[row][col] == 0) {
                    queue.add(new int[]{row, col});
                }
            }
        }
        int len = 0;
        while (!queue.isEmpty()) {
            int queueLen = queue.size();
            len += 1;
            for (int i = 0; i < queueLen; ++i) {
                int[] node = queue.poll();
                for (int[] direction : DIRECTIONS) {
                    int neighborRow = node[0] + direction[0];
                    int neighborCol = node[1] + direction[1];
                    if (isValidNeighbor(matrix, neighborRow, neighborCol, node[0], node[1])) {
                        --degree[neighborRow][neighborCol];
                        if (degree[neighborRow][neighborCol] == 0) {
                            queue.add(new int[]{neighborRow, neighborCol});
                        }
                    }
                }
            }
        }
        return len;
    }

    private boolean isValidNeighbor(int[][] matrix, int curRow, int curCol, int neighborRow, int neighborCol) {
        if (curRow < 0 || curRow >= matrix.length) {
            return false;
        }
        if (neighborRow < 0 || neighborRow >= matrix.length) {
            return false;
        }
        if (curCol < 0 || curCol >= matrix[0].length) {
            return false;
        }
        if (neighborCol < 0 || neighborCol >= matrix[0].length) {
            return false;
        }
        return matrix[curRow][curCol] < matrix[neighborRow][neighborCol];
    }
}

class Solution {
    private static int[][] DIRECTIONS = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1},
    };

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length <= 0 || matrix[0].length <= 0) {
            return 0;
        }
        int numRows = matrix.length;
        int numCols = matrix[0].length;
        int[][] degree = new int[numRows][numCols];

        // count the degrees of each node
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                for (int[] direction : DIRECTIONS) {
                    int neighborRow = row + direction[0];
                    int neighborCol = col + direction[1];
                    if (neighborRow >= 0 && neighborRow < matrix.length &&
                            neighborCol >= 0 && neighborCol < matrix[0].length && matrix[row][col] < matrix[neighborRow][neighborCol]) {
                        ++degree[row][col];
                    }
                }
            }
        }

        Queue<int[]> queue = new LinkedList<>();
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (degree[row][col] == 0) {
                    queue.add(new int[]{row, col});
                }
            }
        }
        int len = 0;
        while (!queue.isEmpty()) {
            int queueLen = queue.size();
            len += 1;
            for (int i = 0; i < queueLen; ++i) {
                int[] node = queue.poll();
                int row = node[0];
                int col = node[1];
                for (int[] direction : DIRECTIONS) {
                    int neighborRow = node[0] + direction[0];
                    int neighborCol = node[1] + direction[1];
                    if (neighborRow >= 0 && neighborRow < matrix.length &&
                            neighborCol >= 0 && neighborCol < matrix[0].length && matrix[row][col] > matrix[neighborRow][neighborCol]) {
                        --degree[neighborRow][neighborCol];
                        if (degree[neighborRow][neighborCol] == 0) {
                            queue.add(new int[]{neighborRow, neighborCol});
                        }
                    }
                }
            }
        }
        return len;

    }
}
//leetcode submit region end(Prohibit modification and deletion)
