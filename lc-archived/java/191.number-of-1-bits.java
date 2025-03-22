/*
 * @lc app=leetcode id=191 lang=java
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt += 1;
            n = n & (n - 1);
        }
        return cnt;
    }
}

public class SolutionA {
    public int hammingWeight(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt += (n & 1);
            n >>>= 1;
        }
        return cnt;
    }

}
// @lc code=end
