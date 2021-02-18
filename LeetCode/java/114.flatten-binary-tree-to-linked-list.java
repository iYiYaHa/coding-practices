/*
 * @lc app=leetcode id=114 lang=java
 *
 * [114] Flatten Binary Tree to Linked List
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
    public void flatten(TreeNode root) {
        if(root == null)
            return;
        flatten(root.left);
        flatten(root.right);
        if(root.left != null){
            TreeNode rightHead = root.right;
            root.right=root.left;
            root.left=null;
            TreeNode cur = root;
            while(cur.right != null){
                cur = cur.right;
            }
            cur.right = rightHead;
        }
    }
}

class Solution {
    TreeNode tail = null;
    public void flatten(TreeNode root) {
        if(root == null)
            return;
        tail = root;
        
        TreeNode left = root.left;
        TreeNode right = root.right;
        
        if(left != null){
        
            // Flatten the left subtree.
            flatten(left);
            // Put the left part between the root node and the right part.
            root.right = left;
            root.left = null;
            // Concatenate the tail of the left part with the head of the right part.
            tail.right = right;
        }
        // Flatten the right part.
        flatten(right);
    }
}
// @lc code=end

