/*
 * @lc app=leetcode id=120 lang=java
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (43.74%)
 * Likes:    2256
 * Dislikes: 261
 * Total Accepted:    261.7K
 * Total Submissions: 586.9K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

// @lc code=start
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int nRow = triangle.size();
        int[][] dp = new int[nRow + 1][nRow + 1];
        for(int i = 0;i<=nRow;++i){
            for(int j = 0;j<=nRow;++j){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= nRow; ++i) {
            for (int j = 1; j <= i; ++j) {
                int left = dp[i-1][j-1];
                int right = dp[i-1][j];
                dp[i][j] = triangle.get(i - 1).get(j - 1) + Math.min(left, right);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= nRow; ++i) {
            ans = Math.min(ans, dp[nRow][i]);
        }
        return ans;
    }
}

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int nRow = triangle.size();
        int[] dp = new int[nRow + 1];
        for(int i = 0;i<=nRow;++i){
            dp[i] = Integer.MAX_VALUE;
        }
        int prev = 0;
        for (int i = 1; i <= nRow; ++i) {
            for (int j = 1; j <= i; ++j) {
                int left = prev;
                prev = dp[j];
                int right = dp[j];
                dp[j] = triangle.get(i - 1).get(j - 1) + Math.min(left, right);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= nRow; ++i) {
            ans = Math.min(ans, dp[i]);
        }
        return ans;
    }
}
// @lc code=end
