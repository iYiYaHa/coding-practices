/*
 * @lc app=leetcode id=912 lang=java
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
    public int[] sortArray(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    private void quickSort(int[] nums, int beg, int end) {
        if (beg >= end) {
            return;
        }
        int pivotInd = partition(nums, beg, end);
        quickSort(nums, beg, pivotInd - 1);
        quickSort(nums, pivotInd + 1, end);
    }

    private int partition(int[] nums, int beg, int end) {
        int pivot = nums[beg];
        int pivotInd = beg;
        for (int i = beg + 1; i <= end; ++i) {
            if (nums[i] <= pivot) {
                swap(nums, ++pivotInd, i);
            }
        }
        swap(nums, beg, pivotInd);
        return pivotInd;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
// @lc code=end

