/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (73.63%)
 * Likes:    734
 * Dislikes: 67
 * Total Accepted:    160.7K
 * Total Submissions: 218.2K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 * 
 */

// @lc code=start
class SolutionA
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && !(nums[left] & 1))
                ++left;
            while (left < right && nums[right] & 1)
                --right;
            if (left < right)
            {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return nums;
    }
};

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        for (int i = 0, k = 0; i < nums.size(); ++i)
        {
            if (!(nums[i] & 1))
            {
                int tmp = nums[k];
                nums[k] = nums[i];
                nums[i] = tmp;
                ++k;
            }
        }
        return nums;
    }
};
// @lc code=end
