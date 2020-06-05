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
    public TreeNode mirrorTree(TreeNode root) {
        if(root == null)
            return null;
        TreeNode mirroredLeft = mirrorTree(root.left);
        TreeNode mirroredRight = mirrorTree(root.right);
        root.left = mirroredRight;
        root.right = mirroredLeft;
        return root;
    }
}