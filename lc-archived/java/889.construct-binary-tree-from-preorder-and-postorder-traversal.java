/*
 * @lc app=leetcode id=889 lang=java
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 */

// @lc code=start

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return constructFromPrePostCore(pre, 0, pre.length - 1,
                post, 0, post.length - 1);
    }

    private TreeNode constructFromPrePostCore(int[] pre, int preBeg, int preEnd,
                                              int[] post, int postBeg, int postEnd) {
        if (preBeg > preEnd || postBeg > postEnd)
            return null;
        TreeNode left = null, right = null;
        if (preBeg + 1 <= preEnd) {
            int leftPostEnd = postBeg;
            while (preBeg + 1 <= preEnd && leftPostEnd <= postEnd && post[leftPostEnd] != pre[preBeg + 1])
                ++leftPostEnd;
            left = constructFromPrePostCore(pre, preBeg + 1, preBeg + leftPostEnd - postBeg + 1,
                    post, postBeg, leftPostEnd);
            right = constructFromPrePostCore(pre, preBeg + leftPostEnd - postBeg + 2, preEnd,
                    post, leftPostEnd + 1, postEnd - 1);
        }
        return new TreeNode(pre[preBeg], left, right);
    }
}
// @lc code=end

