class Solution {
    public int numWays(int n) {
        final int MOD = 1000000007;
        if(n < 0)
            return 0;
        int a = 1, b = 1;
        for(int i = 1;i < n;++i){
            int tmp = (a+b) % MOD;
            a = b;
            b = tmp;
        }
        return b;
    }
}