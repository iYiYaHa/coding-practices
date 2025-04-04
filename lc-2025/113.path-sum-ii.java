/*
 * @lc app=leetcode id=113 lang=java
 *
 * [113] Path Sum II
 */

// @lc code=start
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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return new LinkedList<>();
        }
        List<List<Integer>> result = new LinkedList<>();
        Deque<Integer> path = new LinkedList<>();
        findAllPathWithSumEqualToTarget(root, targetSum, path, result);
        return result;
    }

    private void findAllPathWithSumEqualToTarget(TreeNode root, int targetSum, Deque<Integer> path, List<List<Integer>> result) {
        if (root == null) {
            return;
        }
        path.addLast(root.val);
        if (targetSum == root.val && isLeafNode(root)) {
            result.add(new LinkedList<>(path));
        }
        findAllPathWithSumEqualToTarget(root.left, targetSum - root.val, path, result);
        findAllPathWithSumEqualToTarget(root.right, targetSum - root.val, path, result);
        path.removeLast();
    }

    private boolean isLeafNode(TreeNode root) {
        return root.left == null && root.right == null;
    }
}
// @lc code=end

