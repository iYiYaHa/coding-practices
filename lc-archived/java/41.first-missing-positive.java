/*
 * @lc app=leetcode id=41 lang=java
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (31.76%)
 * Likes:    4080
 * Dislikes: 846
 * Total Accepted:    367.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Follow up:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
class Solution {
    public int firstMissingPositive(int[] nums) {
        int ind = 0;
        while (ind < nums.length) {
            // 把数字放到正确的位置上去
            while(nums[ind]!=ind+1 &&nums[ind]>0 && nums[ind]<=nums.length){
                int pos = nums[ind]-1;
                if(nums[pos] == nums[ind])
                    break;
                int tmp = nums[pos];
                nums[pos] = nums[ind];
                nums[ind] = tmp;
            }
            ++ind;
            
        }
        for(int i = 0;i<nums.length;++i){
            if(nums[i] != i+1)
                return i+1;
        }
        return nums.length+1;
    }
}
// @lc code=end
