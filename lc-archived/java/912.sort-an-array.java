/*
 * @lc app=leetcode id=912 lang=java
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
    private interface Sort {
        public void sort(int[] nums);

        default public void swap(int[] nums, int i, int j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    private class SelectionSort implements Sort {
        public void sort(int[] nums) {
            if (nums == null || nums.length <= 1)
                return;
            for (int i = 0; i < nums.length; ++i) {
                int min = i;
                for (int j = i + 1; j < nums.length; ++j) {
                    if (nums[j] < nums[min]) {
                        min = j;
                    }
                }
                swap(nums, i, min);
            }
        }
    }

    private class InsertionSort implements Sort {
        public void sort(int[] nums) {
            if (nums == null || nums.length <= 1)
                return;
            for (int i = 0; i < nums.length; ++i) {
                for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
                    swap(nums, j, j - 1);
                }
            }
        }
    }

    private class ShellSort implements Sort {
        public void sort(int[] nums) {
            if (nums == null || nums.length <= 1)
                return;
            int n = nums.length;

            int h = 1;
            while (h < n / 3)
                h = 3 * h + 1;

            while (h >= 1) {
                for (int i = h; i < n; ++i) {
                    for (int j = i; j >= h && nums[j] < nums[j - h]; j -= h) {
                        swap(nums, j, j - h);
                    }
                }
                h /= 3;
            }
        }
    }

    private class QuickSort implements Sort {
        public void sort(int[] nums) {
            if (nums == null || nums.length <= 1)
                return;
            sort(nums, 0, nums.length - 1);
        }

        private void sort(int[] nums, int beg, int end) {
            if (beg >= end)
                return;
            int pivotInd = partition(nums, beg, end);
            sort(nums, beg, pivotInd - 1);
            sort(nums, pivotInd + 1, end);
        }

        private int partition(int[] nums, int beg, int end) {
            int pivotVal = nums[beg];
            int pivotInd = beg;
            for (int i = beg + 1; i <= end; ++i) {
                if (nums[i] <= pivotVal) {
                    ++pivotInd;
                    swap(nums, i, pivotInd);
                }
            }
            swap(nums, beg, pivotInd);
            return pivotInd;
        }
    }

    private class MergeSort implements Sort {
        public void sort(int[] nums) {
            if (nums == null || nums.length <= 1)
                return;
            sort(nums, 0, nums.length - 1);
        }

        private void sort(int[] nums, int beg, int end) {
            if (beg >= end)
                return;
            int mid = beg + (end - beg) / 2;
            sort(nums, beg, mid);
            sort(nums, mid + 1, end);

            int[] tmp = new int[end - beg + 1];
            int ind = 0;
            int ptrA = beg, ptrB = mid + 1;
            while (ptrA <= mid || ptrB <= end) {
                int numA = ptrA <= mid ? nums[ptrA] : Integer.MAX_VALUE;
                int numB = ptrB <= end ? nums[ptrB] : Integer.MAX_VALUE;
                if (numA <= numB) {
                    tmp[ind++] = numA;
                    ++ptrA;
                } else {
                    tmp[ind++] = numB;
                    ++ptrB;
                }
            }
            for (int i = beg; i <= end; ++i) {
                nums[i] = tmp[i - beg];
            }
        }
    }

    public int[] sortArray(int[] nums) {
        Sort sort = new MergeSort();
        sort.sort(nums);
        return nums;
    }
}
// @lc code=end
