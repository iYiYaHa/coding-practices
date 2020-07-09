/*
 * @lc app=leetcode id=199 lang=java
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class SolutionA {
    public List<Integer> rightSideView(TreeNode root) {
        LinkedList<Integer> result = new LinkedList<>();
        rightSideViewCore(root, result);
        return result;
    }

    private void rightSideViewCore(TreeNode root, LinkedList<Integer> res) {
        if (root == null)
            return;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        Integer layerCnt = 1;
        res.addLast(root.val);
        while (!queue.isEmpty()) {
            TreeNode head = queue.remove();
            System.out.println(head.val);
            if (head.right != null) {
                queue.add(head.right);
            }
            if (head.left != null) {
                queue.add(head.left);
            }
            --layerCnt;
            if (layerCnt == 0 && !queue.isEmpty()) {
                layerCnt = queue.size();
                res.addLast(queue.element().val);
            }
        }
    }
}

class Solution {

    private Integer maxDepth = 0;

    public List<Integer> rightSideView(TreeNode root) {
        LinkedList<Integer> result = new LinkedList<>();
        dfs(root, 0, result);
        return result;
    }

    private void dfs(TreeNode root, int parentDepth, LinkedList<Integer> result) {
        if (root == null) {
            return;
        }
        int depth = parentDepth + 1;
        if (depth > this.maxDepth) {
            this.maxDepth = depth;
            result.addLast(root.val);
        }
        dfs(root.right, depth, result);
        dfs(root.left, depth, result);

    }

}
// @lc code=end
