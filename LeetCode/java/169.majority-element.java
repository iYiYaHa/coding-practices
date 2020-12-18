/*
 * @lc app=leetcode id=169 lang=java
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (58.39%)
 * Likes:    4133
 * Dislikes: 238
 * Total Accepted:    751.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// @lc code=start
class Solution {
    public int majorityElement(int[] nums) {
        if (nums == null || nums.length <= 0)
            throw new IllegalArgumentException("No empty arrays allowed.");
        int ans = nums[0];
        int counter = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == ans) {
                ++counter;
            } else {
                --counter;
            }
            if (counter == 0) {
                counter = 1;
                ans = nums[i];
            }
        }
        return ans;
    }
}
// @lc code=end
