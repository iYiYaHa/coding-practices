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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(B == null)// Empty tree is not substructure of any tree.
            return false;
        if(A == null)// Non-empty tree is not substructure of an empty tree.
            return false;
        return isSame(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }

    private boolean isSame(TreeNode a, TreeNode b){
        if(b == null)
            return true;
        if(a == null)
            return false;
        return a.val == b.val && isSame(a.left, b.left) && isSame(a.right, b.right);
    }
}