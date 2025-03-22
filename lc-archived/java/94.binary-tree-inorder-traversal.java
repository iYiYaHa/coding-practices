import java.util.LinkedList;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=94 lang=java
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (62.81%)
 * Likes:    3182
 * Dislikes: 134
 * Total Accepted:    741.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        inorderTraversalCore(root, result);
        return result;
    }

    private void inorderTraversalCore(TreeNode root, List<Integer> result) {
        if (root == null)
            return;
        inorderTraversalCore(root.left, result);
        result.add(root.val);
        inorderTraversalCore(root.right, result);
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        while(cur != null || !stack.isEmpty()){
            if(cur != null){
                stack.addLast(cur);
                cur = cur.left;
            }else{
                cur = stack.removeLast();
                result.add(cur.val);
                cur = cur.right;
            }
        }
        return result;
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
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
                stack.addLast(cur);
                stack.addLast(null);
                if(cur.left!= null) stack.addLast(cur.left);
            }
        }
        return result;
    }
}

// Morris Traversal
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        TreeNode cur = root;
        while(cur != null){
            if(cur.left == null){
                result.add(cur.val);
                cur = cur.right;
            }else{
                TreeNode pre = cur.left;
                while(pre.right != null){
                    pre = pre.right;
                }
                pre.right = cur;
                TreeNode tmp = cur.left;
                cur.left = null;
                cur = tmp;
            }
        }
        return result;
    }
}

// @lc code=end
