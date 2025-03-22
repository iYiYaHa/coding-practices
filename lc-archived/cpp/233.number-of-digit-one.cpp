/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (30.98%)
 * Likes:    233
 * Dislikes: 556
 * Total Accepted:    45.9K
 * Total Submissions: 148.2K
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

// ref:https://leetcode.com/problems/number-of-digit-one/solution/
class SolutionA {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        for(long long i = 1;i<=n;i*=10){
            long long divider = i*10;
            cnt += (n/divider)*i+min(max(n%divider-i+1,0LL),i);
        }
        return cnt;
    }
};
// @lc code=end

