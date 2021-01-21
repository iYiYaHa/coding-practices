/*
 * @lc app=leetcode id=75 lang=java
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
    public void sortColors(int[] nums) {
        int cntZero = 0, cntOne = 0, cntTwo = 0;
        for (int num : nums) {
            if (num == 0) {
                ++cntZero;
            } else if (num == 1) {
                ++cntOne;
            } else {
                ++cntTwo;
            }
        }

        int index = 0;
        for (; cntZero > 0; --cntZero)
            nums[index++] = 0;
        for (; cntOne > 0; --cntOne)
            nums[index++] = 1;
        for (; cntTwo > 0; --cntTwo)
            nums[index++] = 2;
    }
}

class Solution {
    public void sortColors(int[] nums) {
        if(nums == null || nums.length <= 1)
            return;
        
        int left = -1, right = nums.length;
        int ind = 0;
        while(ind < right){
            if(nums[ind] == 0){
                swap(nums, ind, ++left);
                ++ind;
            }else if(nums[ind] == 1){
                ++ind;
            }else{
                swap(nums, ind, --right);
            }
        }
    }
    
    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
// @lc code=end

