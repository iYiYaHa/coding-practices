/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 *
 * https://leetcode.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    343
 * Dislikes: 114
 * Total Accepted:    19K
 * Total Submissions: 41.2K
 * Testcase Example:  '1'
 *
 * Given a function rand7 which generates a uniform random integer in the range
 * 1 to 7, write a function rand10 which generates a uniform random integer in
 * the range 1 to 10.
 * 
 * Do NOT use system's Math.random().
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: [7]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: [8,4]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: [8,1,10]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * rand7 is predefined.
 * Each testcase has one argument: n, the number of times that rand10 is
 * called.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What is the expected value for the number of calls to rand7() function?
 * Could you minimize the number of calls to rand7()?
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// 生成一个更大范围的均匀分布，然后拒绝采样。
class Solution {
public:
    int rand10() {
        int row,col,ind;
        do{
            row = rand7();
            col = rand7();
            ind = (row-1)*7+col;
        }while(ind>40);
        return (ind-1)%10+1;
    }
};
// @lc code=end

