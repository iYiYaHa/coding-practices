/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (49.33%)
 * Likes:    813
 * Dislikes: 202
 * Total Accepted:    96.6K
 * Total Submissions: 195.8K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */

// @lc code=start

class Solution {
public:
    int integerBreak(int n)
    {
        if(n<2)
            return 0;
        vector<int> dp(n+1);
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=i/2;++j){
                int tmp = j * max(dp[i-j],i-j);
                dp[i] = max(tmp,dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

