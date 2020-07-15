import java.util.Deque;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=103 lang=java
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null)return new LinkedList<>();
        List<List<Integer>> result = new LinkedList<>();
        Deque<TreeNode> stackOdd = new LinkedList<>();
        Deque<TreeNode> stackEven =new LinkedList<>();
        stackEven.add(root);
        while(!stackOdd.isEmpty() || !stackEven.isEmpty()){
            List<Integer> level = new LinkedList<>();
            if(!stackOdd.isEmpty()){
                while(!stackOdd.isEmpty()){
                    TreeNode node = stackOdd.removeLast();
                    level.add(node.val);
                    if(node.right!=null)
                        stackEven.addLast(node.right);
                    if(node.left!=null)
                        stackEven.addLast(node.left);
                }
            }else{
                while(!stackEven.isEmpty()){
                    TreeNode node = stackEven.removeLast();
                    level.add(node.val);
                    if(node.left!=null)
                        stackOdd.addLast(node.left);
                    if(node.right!=null)
                        stackOdd.addLast(node.right);
                }

            }
            result.add(level);
        }
        return result;
    }
}
// @lc code=end

