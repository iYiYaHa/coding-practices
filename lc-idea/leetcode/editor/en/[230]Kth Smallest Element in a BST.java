//Given the root of a binary search tree, and an integer k, return the kᵗʰ 
//smallest value (1-indexed) of all the values of the nodes in the tree. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,1,4,null,2], k = 1
//Output: 1
// 
//
// Example 2: 
//
// 
//Input: root = [5,3,6,2,4,null,null,1], k = 3
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is n. 
// 1 <= k <= n <= 10⁴ 
// 0 <= Node.val <= 10⁴ 
// 
//
// 
// Follow up: If the BST is modified often (i.e., we can do insert and delete 
//operations) and you need to find the kth smallest frequently, how would you 
//optimize? 
// Related Topics Tree Depth-First Search Binary Search Tree Binary Tree 👍 5194
// 👎 103


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
    public int kthSmallest(TreeNode root, int k) {
        if (k <= 0 || root == null) {
            throw new IllegalArgumentException("Invalid input");
        }
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left != null) {
                TreeNode prev = cur.left;
                while (prev.right != null && prev.right != cur) {
                    prev = prev.right;
                }
                if (prev.right == null) {
                    prev.right = cur;
                    TreeNode tmp = cur.left;
                    cur.left = null;
                    cur = tmp;
                } else {
                    prev.right = null;
                    if (k == 1) {
                        return cur.val;
                    }
                    cur = cur.right;
                }
            } else {
                if (k == 1) {
                    return cur.val;
                } else {
                    --k;
                    cur = cur.right;
                }
            }
        }
        throw new RuntimeException("Invalid input");
    }
}

class Solution {
    TreeNode ans;

    public int kthSmallest(TreeNode root, int k) {
        ans = null;
        return kthSmallestCore(root, k) == -1 ? ans.val : -1;
    }

    private int kthSmallestCore(TreeNode root, int k) {
        if (root == null) {
            return 0;
        }
        int leftCnt = kthSmallestCore(root.left, k);
        if (leftCnt == -1) {
            return -1;
        }
        if (leftCnt == k - 1) {
            ans = root;
            return -1;
        }

        int rightCnt = kthSmallestCore(root.right, k - 1 - leftCnt);
        if (rightCnt == -1) {
            return -1;
        }
        return 1 + leftCnt + rightCnt;
    }
}

//leetcode submit region end(Prohibit modification and deletion)
