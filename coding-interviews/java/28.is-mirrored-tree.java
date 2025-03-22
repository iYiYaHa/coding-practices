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
    public boolean isSymmetric(TreeNode root) {
        if(root == null)
            return true;
        return isMirrored(root.left, root.right); 
    }

    private boolean isMirrored(TreeNode a, TreeNode b){
        if(a == null && b == null)
            return true;
        if(a == null || b == null)
            return false;
        return isMirrored(a.left, b.right) && isMirrored(a.right, b.left) && a.val == b.val;
    }
}