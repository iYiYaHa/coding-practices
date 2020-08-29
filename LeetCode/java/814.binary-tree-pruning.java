/*
 * @lc app=leetcode id=814 lang=java
 *
 * [814] Binary Tree Pruning
 */

// @lc code=start
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
    public TreeNode pruneTree(TreeNode root) {
        return pruneTreeCore(root)?root:null;
    }

    private boolean pruneTreeCore(TreeNode root){
        if(root == null)
            return false;
        boolean left = pruneTreeCore(root.left);
        boolean right = pruneTreeCore(root.right);
        if(!left)
            root.left = null;
        if(!right)
            root.right = null;
        return left||right||root.val == 1;
    }
}

class Solution {
    public TreeNode pruneTree(TreeNode root) {
        if(root == null)
            return null;
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);
        if(root.left != null||root.right != null||root.val == 1)
            return root;
        return null;
    }
}
// @lc code=end

