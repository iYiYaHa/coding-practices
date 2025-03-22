/*
 * @lc app=leetcode id=106 lang=java
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || postorder == null || inorder.length != postorder.length)
            return null;
        return buildTreeCore(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }

    private TreeNode buildTreeCore(int[] inorder, int inBeg, int inEnd, int[] postorder, int postBeg, int postEnd) {
        if (postorder == null || inorder == null || postBeg - postEnd != inBeg - inEnd || postBeg > postEnd || inBeg > inEnd)
            return null;
        int rootVal = postorder[postEnd];

        int inRootInd = inBeg;
        while(inRootInd<=inEnd && inorder[inRootInd] != rootVal) ++ inRootInd;
        int leftPostEnd = postBeg+inRootInd-inBeg-1;

        TreeNode left = buildTreeCore(inorder,inBeg,inRootInd-1,postorder,postBeg,leftPostEnd);
        TreeNode right = buildTreeCore(inorder,inRootInd+1,inEnd,postorder,leftPostEnd+1,postEnd-1);

        return new TreeNode(rootVal, left, right);
    }
}
// @lc code=end
