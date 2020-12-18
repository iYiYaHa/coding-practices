/*
 * @lc app=leetcode id=153 lang=java
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        // 先考虑旋转后切分为两部分的情况
        // 数组被分割为左右两部分，分别递增。
        // min(leftPart) >= max(rightPart)
        // 最小值就是 rightPart 的最小值
        // 如果旋转后还为原数组，结论相同。
        // 综上，找右半部分的第一个值。

        if (nums == null || nums.length <= 0)
            return 0;
        int left = 0, right = nums.length - 1;
        while (left < right) {
            if (nums[left] < nums[right])
                break;
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
}
// @lc code=end
