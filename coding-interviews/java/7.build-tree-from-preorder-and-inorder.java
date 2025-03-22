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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1);
    }
    
    private TreeNode helper(int[] preorder, int preBeg, int preEnd, 
                            int[] inorder, int inBeg, int inEnd){
            if(preBeg > preEnd || inBeg > inEnd)
                return null;
            int rootVal = preorder[preBeg];

            // Find the index of the root value in the inorder seqeuence.
            int rootInOrderPos = inBeg;
            while(rootInOrderPos <= inEnd && inorder[rootInOrderPos] != rootVal)
                ++rootInOrderPos;
            
            // Construct the tree recursively.
            TreeNode root = new TreeNode(rootVal);
            root.left = helper(preorder, preBeg+1, rootInOrderPos-inBeg+preBeg, 
                               inorder, inBeg, rootInOrderPos-1);
            root.right = helper(preorder, rootInOrderPos-inBeg+preBeg+1, preEnd, 
                               inorder, rootInOrderPos+1, inEnd);
            return root;
    }
}