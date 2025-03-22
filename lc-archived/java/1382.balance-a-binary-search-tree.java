/*
 * @lc app=leetcode id=1382 lang=java
 *
 * [1382] Balance a Binary Search Tree
 *
 * https://leetcode.com/problems/balance-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (76.17%)
 * Likes:    529
 * Dislikes: 27
 * Total Accepted:    28.4K
 * Total Submissions: 37.2K
 * Testcase Example:  '[1,null,2,null,3,null,4,null,null]'
 *
 * Given a binary search tree, return a balanced binary search tree with the
 * same node values.
 * 
 * A binary search tree is balanced if and only if the depth of the two
 * subtrees of every node never differ by more than 1.
 * 
 * If there is more than one answer, return any of them.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,2,null,3,null,4,null,null]
 * Output: [2,1,3,null,null,null,4]
 * Explanation: This is not the only correct answer, [3,1,4,null,2,null,null]
 * is also correct.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is between 1 and 10^4.
 * The tree nodes will have distinct values between 1 and 10^5.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public TreeNode balanceBST(TreeNode root) {
        ArrayList<Integer> vals = new ArrayList<>();
        inorderTraversal(root, vals);
        return buildBSTFromValues(vals, 0, vals.size() - 1);
    }

    private void inorderTraversal(TreeNode root, List<Integer> vals) {
        if (root == null)
            return;
        inorderTraversal(root.left, vals);
        vals.add(root.val);
        inorderTraversal(root.right, vals);
    }

    private TreeNode buildBSTFromValues(ArrayList<Integer> values, int beg, int end) {
        if (beg > end)
            return null;
        int mid = beg + (end - beg) / 2;
        TreeNode left = buildBSTFromValues(values, beg, mid - 1);
        TreeNode right = buildBSTFromValues(values, mid + 1, end);
        return new TreeNode(values.get(mid), left, right);
    }
}
// @lc code=end
