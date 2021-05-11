/*
 * @lc app=leetcode id=99 lang=java
 *
 * [99] Recover Binary Search Tree
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
    public void recoverTree(TreeNode root) {
        // Traverse the tree by in-order and store the values in List
        List<Integer> vals = new LinkedList<>();
        inorder(root, node -> vals.add(node.val));
        // Sort the list
        Collections.sort(vals);
        // Put the sorted values back to the tree.
        Iterator<Integer> iterator = vals.iterator();
        inorder(root, node -> node.val = iterator.next());
    }

    private void inorder(TreeNode root, Consumer<TreeNode> fun) {
        LinkedList<TreeNode> stack = new LinkedList<>();
        while (root != null || !stack.isEmpty()) {
            if (root != null) {
                stack.push(root);
                root = root.left;
            } else {
                root = stack.pop();
                fun.accept(root);
                root = root.right;
            }
        }
    }
}
// @lc code=end

