/*
 * @lc app=leetcode id=95 lang=java
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (42.19%)
 * Likes:    2811
 * Dislikes: 197
 * Total Accepted:    219.4K
 * Total Submissions: 518K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
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
    public List<TreeNode> generateTrees(int n) {
        return generateTreesCore(1, n);
    }
    
    private List<TreeNode> generateTreesCore(int beg, int end){
        if(beg > end){
            List<TreeNode> res = new LinkedList<>();
            res.add(null);
            return res;
        }
        List<TreeNode> res = new LinkedList<>();
        for(int i = beg;i <= end; ++i){
            List<TreeNode> left = generateTreesCore(beg, i - 1);
            List<TreeNode> right = generateTreesCore(i + 1, end);
            for(TreeNode leftRoot : left){
                for(TreeNode rightRoot : right){
                    res.add(new TreeNode(i, leftRoot, rightRoot));
                }
            }
        }
        return res;
    }
}
// @lc code=end

