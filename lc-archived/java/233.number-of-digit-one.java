/*
 * @lc app=leetcode id=233 lang=java
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (31.25%)
 * Likes:    312
 * Dislikes: 653
 * Total Accepted:    50.2K
 * Total Submissions: 159.3K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * Example:
 * 
 * 
 * Input: 13
 * Output: 6 
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int countDigitOne(int n) {
        // 按位进行统计
        // |abcd| x |efg|
        // |high|cur|low|
        // cur == 0      high * digit
        // cur == 1      high * digit + low + 1
        // cur == 2 ~ 9  (high + 1) * digit

        int cnt = 0;
        int digit = 1;
        int high = n / 10, low = 0;
        int cur = n % 10;
        while(high != 0 || cur != 0){
            if(cur == 0){
                cnt += high * digit;
            }else if(cur == 1){
                cnt += high * digit + low + 1;
            }else{
                cnt += (high + 1) * digit;
            }

            low = cur * digit + low;
            cur = high % 10;
            high = high / 10;
            digit *= 10;
        }
        return cnt;
    }
}

class Solution {
    public int countDigitOne(int n) {
        if(n == 0)
            return 0;
        String str = String.valueOf(n);
        int high = str.charAt(0) - '0';
        int pow = (int)(Math.pow(10, str.length()-1));
        int last = n - high * pow;
        if(high == 1){
            return countDigitOne(pow - 1) + last + 1 + countDigitOne(last);
        }else{
            return high * countDigitOne(pow - 1) + pow + countDigitOne(last);
        }
    }
}
// @lc code=end

