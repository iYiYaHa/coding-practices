//Given the root of a binary tree, return its maximum depth. 
//
// A binary tree's maximum depth is the number of nodes along the longest path 
//from the root node down to the farthest leaf node. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: 3
// 
//
// Example 2: 
//
// 
//Input: root = [1,null,2]
//Output: 2
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: 0
// 
//
// Example 4: 
//
// 
//Input: root = [0]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 10⁴]. 
// -100 <= Node.val <= 100 
// 
// Related Topics Tree Depth-First Search Breadth-First Search Binary Tree 👍 50
//87 👎 107


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length <= 0 || grid[0].length <= 0) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                ans += isIslandAround(grid, i, j) ? 1 : 0;
            }
        }
        return ans;
    }

    private boolean isIslandAround(char[][] grid, int row, int col) {
        if (row < 0 || row >= grid.length) {
            return false;
        }
        if (col < 0 || col >= grid[row].length) {
            return false;
        }
        if (grid[row][col] == '1') {
            grid[row][col] = '0';
            isIslandAround(grid, row + 1, col);
            isIslandAround(grid, row - 1, col);
            isIslandAround(grid, row, col + 1);
            isIslandAround(grid, row, col - 1);
            return true;
        }
        return false;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
