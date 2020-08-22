/*
 * @lc app=leetcode id=375 lang=java
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
class Solution {
    Map<String, Integer> cache;

    public int getMoneyAmount(int n) {
        cache = new HashMap<>();
        return dfs(1, n);
    }

    private int dfs(int i, int j){
        if(i >= j){
            return 0;
        }
        String key = i + " " + j;
        if(cache.containsKey(key)){
            return cache.get(key);
        }
        int ans = Integer.MAX_VALUE;
        for(int k = i;k<=j;++k){
            int tmp = 0;
            tmp = Math.max(tmp,dfs(i,k-1)+k);
            tmp = Math.max(tmp,dfs(k+1,j)+k);
            ans = Math.min(ans,tmp);
        }
        cache.put(key,ans);
        return ans;
    }
}
class Solution {

    public int getMoneyAmount(int n) {
        int[][] dp = new int[n + 2][n + 2];
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i + len <= n; ++i) {
                dp[i][i+len] = Integer.MAX_VALUE;
                for (int k = i ; k <= i + len; ++k) {
                    int tmp = 0;
                    tmp = Math.max(tmp, k + dp[i][k - 1]);
                    tmp = Math.max(tmp, k + dp[k + 1][i + len]);
                    dp[i][i + len] = Math.min(dp[i][i + len], tmp);
                }
            }
        }
        return dp[1][n];
    }
}
// @lc code=end

