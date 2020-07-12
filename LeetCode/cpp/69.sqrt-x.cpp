/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.94%)
 * Likes:    1150
 * Dislikes: 1764
 * Total Accepted:    511.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

// @lc code=start
class SolutionA
{
public:
    int mySqrt(int x)
    {
        int left = 1, right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid && (mid + 1) > (x / (mid + 1)))
                return mid;
            if (mid < x / mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};

class Solution
{
public:
    int mySqrt(int x)
    {
        double ans = x;
        while (abs(ans * ans - x) > 1e-5)
        {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};
// @lc code=end
