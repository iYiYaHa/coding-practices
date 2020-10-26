/*
 * @lc app=leetcode id=91 lang=java
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.42%)
 * Likes:    3217
 * Dislikes: 3156
 * Total Accepted:    449.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * The answer is guaranteed to fit in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "0"
 * Output: 0
 * Explanation: There is no character that is mapped to a number starting with
 * '0'. We cannot ignore a zero when we face it while decoding. So, each '0'
 * should be part of "10" --> 'J' or "20" --> 'T'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "1"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 * 
 * 
 */

// @lc code=start
class Solution {
    class Solution {
        public int numDecodings(String s) {
            if (s == null)
                return 0;
            Map<Integer, Integer> cache = new HashMap<>();
            return numDecodings(s.toCharArray(), 0, cache);
        }

        private int numDecodings(char[] chars, int pos, Map<Integer, Integer> cache) {
            if (pos >= chars.length)
                return 1;
            if (chars[pos] == '0')
                return 0;
            if (cache.containsKey(pos)) {
                return cache.get(pos);
            }
            int res = 0;
            if (pos + 1 < chars.length) {
                int firstTwoDigit = (chars[pos] - '0') * 10 + chars[pos + 1] - '0';
                if (firstTwoDigit >= 10 && firstTwoDigit <= 26)
                    res = numDecodings(chars, pos + 1, cache) + numDecodings(chars, pos + 2, cache);
                else
                    res = numDecodings(chars, pos + 1, cache);
            } else {
                res = numDecodings(chars, pos + 1, cache);
            }
            cache.put(pos, res);
            return res;
        }
    }
}
// @lc code=end
