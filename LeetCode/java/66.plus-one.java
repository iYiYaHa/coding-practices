/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.91%)
 * Likes:    2014
 * Dislikes: 2882
 * Total Accepted:    754.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of decimal digits representing a non-negative
 * integer, increment one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contains a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = [0]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] plusOne(int[] digits) {
        if (digits == null || digits.length <= 0)
            return null;

        int carry = 1;
        for (int i = digits.length - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0)
                return digits;
        }

        int[] res = new int[digits.length + 1];
        res[0] = 1;
        return res;
    }
}
// @lc code=end
