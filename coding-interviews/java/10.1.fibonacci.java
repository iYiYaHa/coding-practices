class Solution {
    public int fib(int n) {
        if(n <= 0)
            return 0;
        int a = 0, b = 1;
        for(int i = 1; i < n; ++i){
            int sum = (a+b)%1000000007;
            a = b;
            b = sum;
        }
        return b;
    }
}