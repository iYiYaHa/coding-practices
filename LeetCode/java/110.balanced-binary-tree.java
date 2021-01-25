/*
 * @lc app=leetcode id=110 lang=java
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    // Unnecessary traversal
    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;
        int leftHeight = getTreeHeight(root.left);
        int rightHeight = getTreeHeight(root.right);
        return isBalanced(root.left) && isBalanced(root.right) && Math.abs(leftHeight - rightHeight) <= 1;
    }

    private int getTreeHeight(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(getTreeHeight(root.left), getTreeHeight(root.right));
    }
}

class Solution {
    boolean result;

    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;
        result = true;
        getTreeHeight(root);
        return result;
    }

    private int getTreeHeight(TreeNode root) {
        if (root == null)
            return 0;
        int leftHeight = getTreeHeight(root.left);
        int rightHeight = getTreeHeight(root.right);
        if (Math.abs(leftHeight - rightHeight) > 1)
            result = false;
        return 1 + Math.max(leftHeight, rightHeight);
    }
}

class Solution {
    public boolean isBalanced(TreeNode root) {
        return getHeightIfBalanced(root) != -1;
    }

    private int getHeightIfBalanced(TreeNode root) {
        if (root == null)
            return 0;
        int left = getHeightIfBalanced(root.left);
        if (left == -1)
            return -1;
        int right = getHeightIfBalanced(root.right);
        if (right == -1)
            return -1;
        if (Math.abs(left - right) <= 1)
            return 1 + Math.max(left, right);
        return -1;

    }
}
// @lc code=end
