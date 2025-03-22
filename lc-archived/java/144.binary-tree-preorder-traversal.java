import java.util.LinkedList;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=144 lang=java
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (55.29%)
 * Likes:    1536
 * Dislikes: 58
 * Total Accepted:    500K
 * Total Submissions: 902.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        preorderTraversalCore(root, result);
        return result;
    }

    private void preorderTraversalCore(TreeNode root, List<Integer> result){
        if(root == null)return;
        result.add(root.val);
        preorderTraversalCore(root.left, result);
        preorderTraversalCore(root.right, result);
    }
}
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        while(cur != null|| !stack.isEmpty()){
            if(cur != null){
                result.add(cur.val);
                stack.addLast(cur.right);
                cur = cur.left;
            }else{
                cur = stack.removeLast();
            }
        }
        return result;
    }
}
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        if(root != null)stack.addLast(root);
        while(!stack.isEmpty()){
            TreeNode cur = stack.removeLast();
            if(cur == null){
                cur = stack.removeLast();
                result.add(cur.val);
            }else{
                if(cur.right!= null) stack.addLast(cur.right);
                if(cur.left!= null) stack.addLast(cur.left);
                stack.addLast(cur);
                stack.addLast(null);
            }
        }
        return result;
    }
}
// @lc code=end

