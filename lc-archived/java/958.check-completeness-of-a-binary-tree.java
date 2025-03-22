import java.util.LinkedList;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=958 lang=java
 *
 * [958] Check Completeness of a Binary Tree
 *
 * https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (51.88%)
 * Likes:    887
 * Dislikes: 14
 * Total Accepted:    59.2K
 * Total Submissions: 113.7K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a binary tree, determine if it is a complete binary tree.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [1,2,3,4,5,6]
 * Output: true
 * Explanation: Every level before the last is full (ie. levels with
 * node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are
 * as far left as possible.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [1,2,3,4,5,null,7]
 * Output: false
 * Explanation: The node with value 7 isn't as far left as possible.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The tree will have between 1 and 100 nodes.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if (root == null)
            return true;
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addLast(root);
        boolean flag = false;
        while (!queue.isEmpty()) {
            TreeNode top = queue.removeFirst();
            if (top.left != null && top.right != null) {
                if (flag == true)
                    return false;
                if (top.left != null)
                    queue.addLast(top.left);
                if (top.right != null)
                    queue.addLast(top.right);
            } else if (top.left == null && top.right != null) {
                return false;
            } else if (top.left != null && top.right == null) {
                if (flag == true)
                    return false;
                queue.addLast(top.left);
                flag = true;
            } else {
                flag = true;
            }
        }
        return true;
    }
}
// @lc code=end
