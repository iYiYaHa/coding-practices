/*
 * @lc app=leetcode id=8 lang=java
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (15.32%)
 * Likes:    1827
 * Dislikes: 10311
 * Total Accepted:    625.6K
 * Total Submissions: 4M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered a whitespace character.
 * Assume we are dealing with an environment that could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str = "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str = "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign. Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str = "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: str = "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical digit or a +/- sign. Therefore no valid conversion could be
 * performed.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: str = "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer. Thefore INT_MIN (−2^31) is returned.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 200
 * s consists of English letters (lower-case and upper-case), digits, ' ', '+',
 * '-' and '.'.
 * 
 * 
 */

// @lc code=start

class Solution {
    public int myAtoi(String str) {
        if(str == null || str.length() <= 0)
            return 0;

        char[] chars = str.toCharArray();
        int ind = 0;
        
        // 去掉先导空格
        while(ind < chars.length && chars[ind] == ' ') ++ind;

        if(ind >= chars.length)
            return 0;
        // 判断正负号
        boolean isPositive = true;
        if(chars[ind] == '+' || chars[ind] == '-'){
            isPositive = chars[ind] == '+'?true:false;
            ++ind;
        }
        int num = 0;
        while(ind < chars.length){
            if(chars[ind] > '9' || chars[ind] < '0')
                break;
            int digit = chars[ind] - '0';
            /*
            if(isPositive){
                if(num > Integer.MAX_VALUE/10 || 
                  (num == Integer.MAX_VALUE/10 && digit > Integer.MAX_VALUE%10))
                return Integer.MAX_VALUE;
            }else{
                if(num > Integer.MAX_VALUE/10 || 
                  (num == Integer.MAX_VALUE/10 && digit >= (Integer.MAX_VALUE%10+1)))
                return Integer.MIN_VALUE;
            }
            */
            if(num > Integer.MAX_VALUE/10 || 
                  (num == Integer.MAX_VALUE/10 && digit > Integer.MAX_VALUE%10)){
                      return isPositive?Integer.MAX_VALUE:Integer.MIN_VALUE;
                  }
            num *= 10;
            num += digit;
            ++ind;
        }
        return isPositive ? num : -num;
    }
}
// @lc code=end

