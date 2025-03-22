/*
 * @lc app=leetcode id=224 lang=java
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (36.53%)
 * Likes:    1933
 * Dislikes: 152
 * Total Accepted:    192.2K
 * Total Submissions: 505.3K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing an expression, implement a basic calculator to
 * evaluate it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = " 2-1 + 2 "
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int calculate(String s) {
        if (s == null || s.length() <= 0)
            return 0;
        LinkedList<Integer> stack = new LinkedList<>();
        int sign = 1;
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == ' ')
                continue;
            else if (Character.isDigit(ch)) {
                num = (ch - '0');
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    num = num * 10 + (s.charAt(i + 1) - '0');
                    ++i;
                }
                stack.push(sign);
                stack.push(num);
            } else if (ch == '(') {
                stack.push(sign);
                stack.push(Integer.MIN_VALUE);
                sign = 1;
                continue;
            } else if (ch == ')') {
                int top = 0;
                int res = 0;
                while ((top = stack.pop()) != Integer.MIN_VALUE) {
                    res += top * stack.pop();
                }
                sign = stack.pop();
                stack.push(sign);
                stack.push(res);
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else {
                throw new IllegalArgumentException("Illegal input : " + ch);
            }
        }
        int res = 0;
        while (!stack.isEmpty()) {
            res += stack.pop() * stack.pop();
        }

        return res;
    }
}

class Solution {
    public int calculate(String s) {
        if (s == null || s.length() <= 0)
            return 0;
        LinkedList<Integer> stack = new LinkedList<>();
        int sign = 1;
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == ' ')
                continue;
            else if (Character.isDigit(ch)) {
                int num = (ch - '0');
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    num = num * 10 + (s.charAt(i + 1) - '0');
                    ++i;
                }
                res += sign * num;
            } else if (ch == '(') {
                stack.push(res);
                stack.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                res = res * stack.pop() + stack.pop();
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else {
                throw new IllegalArgumentException("Illegal input : " + ch);
            }
        }
        return res;
    }
}
// @lc code=end
