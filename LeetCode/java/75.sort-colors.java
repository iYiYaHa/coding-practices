/*
 * @lc app=leetcode id=75 lang=java
 *
 * [75] Sort Colors
 */

// @lc code=start
// class Solution {
//     public void sortColors(int[] nums) {
//         int cntZero = 0, cntOne = 0, cntTwo = 0;
//         for (int num : nums) {
//             if (num == 0) {
//                 ++cntZero;
//             } else if (num == 1) {
//                 ++cntOne;
//             } else {
//                 ++cntTwo;
//             }
//         }

//         int index = 0;
//         for (; cntZero > 0; --cntZero)
//             nums[index++] = 0;
//         for (; cntOne > 0; --cntOne)
//             nums[index++] = 1;
//         for (; cntTwo > 0; --cntTwo)
//             nums[index++] = 2;
//     }
// }

class Solution {
    public void sortColors(int[] nums) {
        int low = 0, mid = 0,high = nums.length-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums, low, mid);
                ++low;
                ++mid;
            }else if(nums[mid] == 1){
                ++mid;
            }else{
                swap(nums,mid,high);
                --high;
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

