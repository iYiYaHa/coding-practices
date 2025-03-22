/*
 * @lc app=leetcode id=102 lang=java
 *
 * [102] Binary Tree Level Order Traversal
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null)
            return new LinkedList<>();
        List<List<Integer>> result = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        Integer levelSize = 1;
        List<Integer> levelNodes = new LinkedList<>();
        while(!queue.isEmpty()){
            TreeNode node = queue.remove();
            levelNodes.add(node.val);
            --levelSize;
            if(node.left != null)
                queue.add(node.left);
            if(node.right != null)
                queue.add(node.right);
            if(levelSize == 0){
                result.add(levelNodes);
                levelSize = queue.size();
                levelNodes = new LinkedList<>();
            }
        }
        return result;
    }
}
// @lc code=end

