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
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        LinkedList<TreeNode> queue = new LinkedList<>();
        List<Integer> res = new LinkedList<>();
        if (root != null)
            queue.offer(root);
        while (!queue.isEmpty()) {
            int layerSize = queue.size();
            for (int i = 0; i < layerSize; ++i) {
                TreeNode cur = queue.poll();
                if (i == layerSize - 1) {
                    res.add(cur.val);
                }
                if (cur.left != null) {
                    queue.offer(cur.left);
                }
                if (cur.right != null) {
                    queue.offer(cur.right);
                }
            }
        }
        return res;
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
