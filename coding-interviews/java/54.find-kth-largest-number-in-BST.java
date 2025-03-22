/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode res;
    private int k;
    public int kthLargest(TreeNode root, int k) {
        this.res = null;
        this.k = k;
        dfs(root);
        return res.val;
    }

    private void dfs(TreeNode root){
        if(root == null||k<=0)
            return;
        dfs(root.right);
        --this.k;
        if(this.k == 0)
            res = root;
        dfs(root.left);
    }
}