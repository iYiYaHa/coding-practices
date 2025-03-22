/*
 * @lc app=leetcode id=222 lang=java
 *
 * [222] Count Complete Tree Nodes
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
class SolutionA {
    public int countNodes(TreeNode root) {
        if(root == null)
            return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}

class Solution {
    public int countNodes(TreeNode root) {
        if(root == null)
            return 0;
         int heightOfLeft = findLeftHeight(root);
         int heightOfRight = findRightHeight(root);
         if(heightOfLeft == heightOfRight){ // Complete binary tree
            int height = heightOfLeft;
            return countNodesOfCompleteBT(height);
         }else{
            int heightOfRightOfLeft = findRightHeight(root.left);
            if(heightOfLeft - 1 == heightOfRightOfLeft){
                return countNodesOfCompleteBT(heightOfRightOfLeft) + countNodes(root.right) + 1;
            }else{
                return countNodesOfCompleteBT(heightOfRight - 1) + countNodes(root.left) + 1;
            }
         }
    }

    private int findLeftHeight(TreeNode root){
        if(root == null)
            return 0;
        return 1 + findLeftHeight(root.left);
    }

    private int findRightHeight(TreeNode root){
        if(root == null)
            return 0;
        return 1 + findRightHeight(root.right);
    }

    private int countNodesOfCompleteBT(int height){
        assert(height >= 0);
        return  (int)Math.pow(2, height) - 1;
    }
}


// @lc code=end

