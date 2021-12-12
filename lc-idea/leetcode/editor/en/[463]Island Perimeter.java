//You are given row x col grid representing a map where grid[i][j] = 1 
//represents land and grid[i][j] = 0 represents water. 
//
// Grid cells are connected horizontally/vertically (not diagonally). The grid 
//is completely surrounded by water, and there is exactly one island (i.e., one or 
//more connected land cells). 
//
// The island doesn't have "lakes", meaning the water inside isn't connected to 
//the water around the island. One cell is a square with side length 1. The grid 
//is rectangular, width and height don't exceed 100. Determine the perimeter of 
//the island. 
//
// 
// Example 1: 
//
// 
//Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
//Output: 16
//Explanation: The perimeter is the 16 yellow stripes in the image above.
// 
//
// Example 2: 
//
// 
//Input: grid = [[1]]
//Output: 4
// 
//
// Example 3: 
//
// 
//Input: grid = [[1,0]]
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// row == grid.length 
// col == grid[i].length 
// 1 <= row, col <= 100 
// grid[i][j] is 0 or 1. 
// There is exactly one island in grid. 
// 
// Related Topics Array Depth-First Search Breadth-First Search Matrix 👍 3819 ?
//? 219


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int islandPerimeter(int[][] grid) {
        if (grid == null || grid.length <= 0 || grid[0].length <= 0) {
            return 0;
        }
        int perimeter = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                perimeter += getPerimeterOfLand(grid, i, j);
            }
        }
        return perimeter;
    }

    private int getPerimeterOfLand(int[][] grid, int row, int col) {
        if (isGridOutOfBounds(grid, row, col) || grid[row][col] == 0) {
            return 0;
        }
        int perimeter = 0;
        if (isGridOutOfBounds(grid, row + 1, col) || grid[row + 1][col] == 0) {
            perimeter += 1;
        }
        if (isGridOutOfBounds(grid, row - 1, col) || grid[row - 1][col] == 0) {
            perimeter += 1;
        }
        if (isGridOutOfBounds(grid, row, col + 1) || grid[row][col + 1] == 0) {
            perimeter += 1;
        }
        if (isGridOutOfBounds(grid, row, col - 1) || grid[row][col - 1] == 0) {
            perimeter += 1;
        }
        return perimeter;
    }

    private boolean isGridOutOfBounds(int[][] grid, int row, int col) {
        int rows = grid.length;
        int cols = grid[0].length;
        return (row < 0 || row >= rows) || (col < 0 || col >= cols);
    }
}

class Solution {
    public int islandPerimeter(int[][] grid) {
        if (grid == null || grid.length <= 0 || grid[0].length <= 0) {
            return 0;
        }
        int rows = grid.length;
        int cols = grid[0].length;
        int perimeter = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                perimeter += 4;
                if (i > 0 && grid[i - 1][j] == 1) {
                    perimeter -= 2;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
