/*
 * @lc app=leetcode id=124 lang=java
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    private Integer maxSum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        maxPathSumCore(root);
        return this.maxSum;
    }

    private int maxPathSumCore(TreeNode root) {
        if (root == null)
            return 0;
        int leftPathSum = maxPathSumCore(root.left);
        int rightPathSum = maxPathSumCore(root.right);
        int rootPathSum = root.val + Math.max(0, Math.max(leftPathSum, rightPathSum));

        maxSum = Math.max(maxSum, Math.max(rootPathSum, root.val + leftPathSum + rightPathSum));
        return rootPathSum;
    }
}
// @lc code=end
