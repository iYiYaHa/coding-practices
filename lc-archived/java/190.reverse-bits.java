import java.util.Map;

/*
 * @lc app=leetcode id=190 lang=java
 *
 * [190] Reverse Bits
 */

// @lc code=start
// public class SolutionA {
//     Map<Integer, Integer> cache = new HashMap<>();

//     // you need treat n as an unsigned value
//     public int reverseBits(int n) {
//         if (cache.containsKey(n)) {
//             return cache.get(n);
//         }
//         int result = 0;
//         for (int i = 0; i < 32; ++i) {
//             result = (result << 1) | (n & 1);
//             n >>= 1;
//         }
//         cache.put(n, result);
//         return result;
//     }
// }

public class Solution {

    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        n = (n << 16) | (n >>> 16);
        n = ((n & 0xff00ff00)) >>> 8 | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0)) >>> 4 | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc)) >>> 2 | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa)) >>> 1 | ((n & 0x55555555) << 1);
        return n;
    }
}
// @lc code=end
