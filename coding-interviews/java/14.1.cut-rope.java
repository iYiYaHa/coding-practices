class Solution {
    public int cuttingRope(int n) {
        if(n <= 0)
            return 0;
        int[] dp = new int[n+1];
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = 0;
            for(int j = 1;j <= i/2;++j){
                dp[i] = Math.max(dp[i], j * Math.max(i-j, dp[i-j]));
            }
        }
        return dp[n];
    }
}