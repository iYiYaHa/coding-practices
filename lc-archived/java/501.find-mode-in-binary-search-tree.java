/*
 * @lc app=leetcode id=501 lang=java
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (43.30%)
 * Likes:    1214
 * Dislikes: 399
 * Total Accepted:    102.7K
 * Total Submissions: 236.7K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
 * 
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
    int maxCounter = 0;
    int counter = 0;
    Integer prev = null;
    public int[] findMode(TreeNode root) {
        maxCounter = 0;
        counter = 0;
        List<Integer> modes = new LinkedList<>();
        inorderTraversal(root, modes);
        int[] res = new int[modes.size()];
        int ind = 0;
        for(int val : modes){
            res[ind++] = val;
        }
        return res;
    }
    
    private void inorderTraversal(TreeNode root, List<Integer> modes){
        if(root == null)
            return;
        inorderTraversal(root.left, modes);
        if(prev != null && prev == root.val){
                ++counter;
        }else{
                counter = 1;
        }
        if(counter > maxCounter){
            modes.clear();
            maxCounter = counter;
            modes.add(root.val);
        }else if(counter == maxCounter){
            modes.add(root.val);
        }
        prev = root.val;
        inorderTraversal(root.right, modes);
    }
}
// @lc code=end

