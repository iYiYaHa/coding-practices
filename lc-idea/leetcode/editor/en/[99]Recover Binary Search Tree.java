//You are given the root of a binary search tree (BST), where the values of 
//exactly two nodes of the tree were swapped by mistake. Recover the tree without 
//changing its structure. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,3,null,null,2]
//Output: [3,1,null,null,2]
//Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 
//makes the BST valid.
// 
//
// Example 2: 
//
// 
//Input: root = [3,1,4,null,null,2]
//Output: [2,1,4,null,null,3]
//Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 
//and 3 makes the BST valid.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [2, 1000]. 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// 
//Follow up: A solution using O(n) space is pretty straight-forward. Could you 
//devise a constant O(1) space solution? Related Topics Tree Depth-First Search 
//Binary Search Tree Binary Tree 👍 3418 👎 130


//leetcode submit region begin(Prohibit modification and deletion)
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
    private TreeNode first;
    private TreeNode second;
    private TreeNode prev;

    public void recoverTree(TreeNode root) {
        initContext();
        inorderTraversal(root, this::nodeFun);
        swap(first, second);
    }

    private void initContext() {
        first = null;
        second = null;
        prev = null;
    }

    private void nodeFun(TreeNode cur) {
        if (cur == null) {
            return;
        }
        if (prev != null && prev.val > cur.val) {
            if (first == null) {
                first = prev;
            }
            second = cur;
        }
        prev = cur;
    }

    public void inorderTraversal(TreeNode root, Consumer<TreeNode> nodeFun) {
        TreeNode cur = root;
        TreeNode lastAccessed = null;
        while (cur != null) {
            if (cur.left != null) {
                TreeNode prev = cur.left;
                while (prev.right != null && prev.right != cur) {
                    prev = prev.right;
                }
                if (prev.right == null) {
                    prev.right = cur;
                    cur = cur.left;
                } else {
                    prev.right = null;
                    nodeFun.accept(cur);
                    cur = cur.right;
                }
            } else {
                nodeFun.accept(cur);
                cur = cur.right;
            }
        }
    }

    private void swap(TreeNode nodeA, TreeNode nodeB) {
        if (nodeA == null || nodeB == null) {
            return;
        }
        int tmp = nodeA.val;
        nodeA.val = nodeB.val;
        nodeB.val = tmp;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
