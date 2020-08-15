/*
 * @lc app=leetcode id=154 lang=java
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        if(nums == null || nums.length < 0)
            return 0;
        int left = 0, right = nums.length-1;
        while(left<right){
            if(nums[left]<nums[right])
                break;
            int mid = left + (right-left) / 2;
            if(nums[left]<nums[mid]){
                left = mid + 1;
            }else if(nums[left] > nums[mid]){
                right = mid;
            }else{
                ++left;
            }
        }
        return nums[left];
    }
}

// @lc code=end

