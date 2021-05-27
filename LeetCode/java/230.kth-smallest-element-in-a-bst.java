/*
 * @lc app=leetcode id=230 lang=java
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (62.26%)
 * Likes:    3548
 * Dislikes: 82
 * Total Accepted:    504.3K
 * Total Submissions: 805.8K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * (1-indexed) smallest element in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 * 
 * 
 * 
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    TreeNode ans;

    public int kthSmallest(TreeNode root, int k) {
        ans = null;
        return kthSmallestCore(root, k) == -1 ? ans.val : -1;
    }

    private int kthSmallestCore(TreeNode root, int k) {
        if (root == null)
            return 0;

        int leftCnt = kthSmallestCore(root.left, k);
        if (leftCnt == -1)
            return -1;
        else if (leftCnt == k - 1) {
            ans = root;
            return -1;
        }

        int rightCnt = kthSmallestCore(root.right, k - 1 - leftCnt);
        if (rightCnt == -1)
            return -1;
        return 1 + leftCnt + rightCnt;
    }
}

class Solution {
    public int kthSmallest(TreeNode root, int k) {
        LinkedList<TreeNode> stack = new LinkedList<>();
        while (root != null || !stack.isEmpty()) {
            if (root != null) {
                stack.push(root);
                root = root.left;
            } else {
                root = stack.pop();
                if (--k == 0) {
                    return root.val;
                }
                root = root.right;
            }
        }
        return -1;
    }
}
// @lc code=end
