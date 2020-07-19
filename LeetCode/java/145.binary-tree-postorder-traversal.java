import java.util.LinkedList;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=145 lang=java
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (54.41%)
 * Likes:    1776
 * Dislikes: 93
 * Total Accepted:    381.8K
 * Total Submissions: 699.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        postorderTraversalCore(root, result);
        return result;
    }

    private void postorderTraversalCore(TreeNode root, List<Integer> result) {
        if (root == null)
            return;
        postorderTraversalCore(root.left, result);
        postorderTraversalCore(root.right, result);
        result.add(root.val);
    }
}

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        TreeNode prev = null;
        while (cur != null || !stack.isEmpty()) {
            if (cur != null) {
                stack.addLast(cur);
                cur = cur.left;
            } else {
                cur = stack.removeLast();
                if (cur.right == null || cur.right == prev) {
                    result.add(cur.val);
                    prev = cur;
                    cur = null;
                } else {
                    stack.addLast(cur);
                    cur = cur.right;
                }
            }
        }
        return result;
    }
}

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        if(root != null)stack.addLast(root);
        while(!stack.isEmpty()){
            TreeNode cur = stack.removeLast();
            if(cur == null){
                cur = stack.removeLast();
                result.add(cur.val);
            }else{
                stack.addLast(cur);
                stack.addLast(null);
                if(cur.right!= null) stack.addLast(cur.right);
                if(cur.left!= null) stack.addLast(cur.left);
            }
        }
        return result;
    }
}
// @lc code=end
