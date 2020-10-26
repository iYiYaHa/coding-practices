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
    public int numDecodings(String s) {
        if(s == null)
            return 0;
        char[] chars = s.toCharArray();
        return numDecodings(chars, 0, new HashMap<>());
    }
    
    private int numDecodings(char[] chars, int pos, Map<Integer, Integer> cache){
        if(pos >= chars.length)
            return 1;
        if(cache.containsKey(pos))
            return cache.get(pos);
        int res = 0;
        if(chars[pos] == '0'){
            res = 0;
        }else{
            res = numDecodings(chars, pos + 1, cache);
            if(pos + 1 < chars.length){
               int firstTwoDigits = (chars[pos] - '0') * 10 + chars[pos+1] - '0'; 
               if(firstTwoDigits >= 10 && firstTwoDigits <= 26){
                   res += numDecodings(chars, pos + 2, cache);
               }
            }
        }
        cache.put(pos, res);
        return res;
    }
}

class Solution {
    public int numDecodings(String s) {
        if (s == null)
            return 0;
        char[] chars = s.toCharArray();
        int[] dp = new int[chars.length + 1];
        dp[0] = 1;

        for (int i = 1; i <= chars.length; ++i) {
            dp[i] = chars[i - 1] == '0' ? 0 : dp[i - 1];
            if (i - 1 >= 1) {
                int firstTwoDigit = (chars[i - 2] - '0') * 10 + chars[i - 1] - '0';
                if (firstTwoDigit >= 10 && firstTwoDigit <= 26)
                    dp[i] += dp[i - 2];
            }
        }

        return dp[chars.length];
    }
}

// @lc code=end
