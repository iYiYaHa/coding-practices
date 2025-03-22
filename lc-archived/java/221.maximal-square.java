/*
 * @lc app=leetcode id=221 lang=java
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix == null||matrix.length == 0||matrix[0].length == 0)
        return 0;
        int n = matrix.length, m = matrix[0].length;
        int[][] dp = new int[n+1][m+1];
        int maxLen = 0;
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                if(matrix[i-1][j-1] == '0'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = Math.min(dp[i-1][j-1],
                    Math.min(dp[i][j-1],dp[i-1][j]))+1;
                }
                maxLen = Math.max(maxLen,dp[i][j]);
            }
        }
        return maxLen * maxLen;
    }
}
// @lc code=end

