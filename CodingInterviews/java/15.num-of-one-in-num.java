public class SolutionA {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0){
            ++cnt;
            n = (n-1) & n;
        }
        return cnt;
    }
}

public class SolutionB {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0){
            if((n & 1) != 0){
                ++cnt;
            }
            n>>>=1;
        }
        return cnt;
    }
}