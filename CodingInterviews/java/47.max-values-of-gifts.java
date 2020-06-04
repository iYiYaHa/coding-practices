class SolutionA {
    public int maxValue(int[][] grid) {
        if(grid == null || grid.length <= 0 || grid[0].length <= 0)
            return 0;
        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[n+1][m+1];
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[n][m];
    }
}

class SolutionB {
    public int maxValue(int[][] grid) {
        if(grid == null || grid.length <= 0 || grid[0].length <= 0)
            return 0;
        int n = grid.length, m = grid[0].length;
        int[] dp = new int[m+1];
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                dp[j] = Math.max(dp[j], dp[j-1]) + grid[i-1][j-1];
            }
        }
        return dp[m];
    }
}