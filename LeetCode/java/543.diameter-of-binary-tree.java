/*
 * @lc app=leetcode id=543 lang=java
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    int maxPath = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        this.maxPath = 0;
        diameterCore(root);
        return maxPath;
    }

    private int diameterCore(TreeNode root){
        if(root == null) return 0;
        int left = diameterCore(root.left);
        int right = diameterCore(root.right);
        maxPath = Math.max(maxPath,left+right);
        return 1+Math.max(left,right);
    }
}
// @lc code=end
