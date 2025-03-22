/*
 * @lc app=leetcode id=9 lang=java
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (48.03%)
 * Likes:    2531
 * Dislikes: 1600
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;
        int tmp = x;
        long reverse = 0;
        while (tmp > 0) {
            int lastDigit = tmp % 10;
            tmp /= 10;
            reverse = reverse * 10 + lastDigit;
        }
        return reverse == (long)x;
    }
}
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0||(x%10 == 0&&x!=0))
            return false;
        int half = 0;
        while (x > half) {
            int lastDigit = x % 10;
            x /= 10;
            half = half * 10 + lastDigit;
        }
        return half == x || half / 10 == x;
    }
}

// @lc code=end
