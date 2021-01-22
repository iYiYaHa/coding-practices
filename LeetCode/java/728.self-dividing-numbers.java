/*
 * @lc app=leetcode id=728 lang=java
 *
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (74.04%)
 * Likes:    794
 * Dislikes: 305
 * Total Accepted:    143.5K
 * Total Submissions: 190.5K
 * Testcase Example:  '1\n22'
 *
 * 
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 * 
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 * 
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * 
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 * 
 * Example 1:
 * 
 * Input: 
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 
 * Note:
 * The boundaries of each input argument are 1 .
 * 
 */

// @lc code=start
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> res = new LinkedList<>();
        for (int i = left; i <= right; ++i) {
            if (isSelfDividing(i)) {
                res.add(i);
            }
        }
        return res;
    }

    private boolean isSelfDividing(int num) {
        int digits = num;
        while (digits != 0) {
            int lastDigit = digits % 10;
            if (lastDigit == 0 || num % lastDigit != 0) {
                return false;
            }
            digits /= 10;
        }
        return true;
    }
}
// @lc code=end
