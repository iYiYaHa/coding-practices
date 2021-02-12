/*
 * @lc app=leetcode id=96 lang=java
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (54.22%)
 * Likes:    4270
 * Dislikes: 159
 * Total Accepted:    346.9K
 * Total Submissions: 638.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */

// @lc code=start
class Solution {
    public int numTrees(int n) {
        if(n < 1)
            return 0;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n; ++i){
            for(int j = 1;j <= i; ++j){
                int left = dp[j - 1];
                int right = dp[i - j];
                dp[i] += left * right;
            }
        }
        return dp[n];
    }
}
// @lc code=end

