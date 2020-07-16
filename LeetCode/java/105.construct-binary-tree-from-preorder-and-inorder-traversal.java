/*
 * @lc app=leetcode id=105 lang=java
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */

class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null || preorder.length != inorder.length)
            return null;
        return buildTreeCore(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private TreeNode buildTreeCore(int[] preorder, int preBeg, int preEnd, int[] inorder, int inBeg, int inEnd) {
        if (preorder == null || inorder == null || preBeg - preEnd != inBeg - inEnd || preBeg > preEnd || inBeg > inEnd)
            return null;
        int rootVal = preorder[preBeg];
        int rootInd = inBeg;
        while (rootInd <= inEnd && inorder[rootInd] != rootVal)
            ++rootInd;

        int leftInEnd = rootInd - inBeg + preBeg;
        TreeNode left = buildTreeCore(preorder, preBeg + 1, leftInEnd, inorder, inBeg, rootInd - 1);
        TreeNode right = buildTreeCore(preorder, leftInEnd + 1, preEnd, inorder, rootInd + 1, inEnd);

        TreeNode rootNode = new TreeNode(rootVal, left, right);
        return rootNode;
    }
}
// @lc code=end
