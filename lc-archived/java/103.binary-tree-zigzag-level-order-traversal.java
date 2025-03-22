import java.util.Deque;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=103 lang=java
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        LinkedList<TreeNode> oddStack = new LinkedList<>();
        LinkedList<TreeNode> evenStack = new LinkedList<>();
        LinkedList<List<Integer>> res = new LinkedList<>();
        if (root != null)
            oddStack.add(root);
        while (!oddStack.isEmpty() || !evenStack.isEmpty()) {
            LinkedList<Integer> layer = new LinkedList<>();
            if (!oddStack.isEmpty()) {
                int layerSize = oddStack.size();
                for (int i = 0; i < layerSize; ++i) {
                    TreeNode node = oddStack.pop();
                    layer.add(node.val);
                    if (node.left != null) {
                        evenStack.push(node.left);
                    }
                    if (node.right != null) {
                        evenStack.push(node.right);
                    }
                }
            } else {
                int layerSize = evenStack.size();
                for (int i = 0; i < layerSize; ++i) {
                    TreeNode node = evenStack.pop();
                    layer.add(node.val);
                    if (node.right != null) {
                        oddStack.push(node.right);
                    }
                    if (node.left != null) {
                        oddStack.push(node.left);
                    }
                }
            }
            res.add(layer);
        }
        return res;
    }
}
// @lc code=end
