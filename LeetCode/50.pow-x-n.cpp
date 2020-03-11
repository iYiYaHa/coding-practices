/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (29.07%)
 * Likes:    1179
 * Dislikes: 2657
 * Total Accepted:    409.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(x > -1e-10 && x < 1e-10 && n < 0)
            throw invalid_argument("Zero as base with a negative exponent");
        
        // To handle the overflow with smallest integer.
        if(n == numeric_limits<int>::min()){
            n /= 2;
            x *= x;
        }

        unsigned int absExp = static_cast<unsigned int>(n);
        if(n<0)
            absExp = static_cast<unsigned int>(-n);

        double resPow = powCoreRecursive(x,absExp);
        if(n<0)
            resPow = 1/resPow;
        return resPow;
    }
private:
    double powCore(double x, unsigned int absExp){
        if(absExp == 0)
            return 1;
        if(absExp & 1){
            return x * powCore(x, absExp-1);
        }
        else{
            double halfPow = powCore(x, absExp>>1);
            return halfPow * halfPow;
        }
    }

    double powCoreRecursive(double x, unsigned int absExp){
        double ans = 1;
        while(absExp){
            if(absExp & 1){
                ans *= x;
            }
            x *= x;
            absExp >>= 1;
        }
        return ans;
    }
};
// @lc code=end

