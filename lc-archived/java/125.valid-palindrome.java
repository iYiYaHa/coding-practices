/*
 * @lc app=leetcode id=125 lang=java
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (35.68%)
 * Likes:    1404
 * Dislikes: 3155
 * Total Accepted:    679.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(String s) {
        if (s == null)
            return true;
        char[] chars = s.toLowerCase().toCharArray();
        for (int i = 0, j = chars.length - 1; i < j;) {
            if (!Character.isLetterOrDigit(chars[i])) {
                ++i;
                continue;
            }
            if (!Character.isLetterOrDigit(chars[j])) {
                --j;
                continue;
            }
            if (chars[i] != chars[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
}
// @lc code=end
