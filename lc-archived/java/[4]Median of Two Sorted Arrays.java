//Given two sorted arrays nums1 and nums2 of size m and n respectively, return 
//the median of the two sorted arrays. 
//
// The overall run time complexity should be O(log (m+n)). 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
// 
//
// Example 2: 
//
// 
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// 
//
// 
// Constraints: 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
// 
// Related Topics 数组 二分查找 分治 👍 5463 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) {
            throw new IllegalArgumentException("Input is null...");
        }
        int cntEle = nums1.length + nums2.length;
        if (cntEle % 2 != 0) {
            return findKthEle(nums1, nums2, cntEle / 2);
        } else {
            return (findKthEle(nums1, nums2, cntEle / 2) + findKthEle(nums1, nums2, cntEle / 2 - 1)) / 2.0D;
        }
    }

    private int findKthEle(int[] nums1, int[] nums2, int k) {
        return findKthEle(nums1, 0, nums1.length - 1, nums2, 0, nums2.length - 1, k);
    }

    private int findKthEle(int[] nums1, int leftA, int rightA, int[] nums2, int leftB, int rightB, int k) {
        if (leftA > rightA) {
            return nums2[leftB + k];
        }
        if (leftB > rightB) {
            return nums1[leftA + k];
        }
        if (k == 0) {
            return Math.min(nums1[leftA], nums2[leftB]);
        }
        int midA = Math.min(leftA + (k - 1) / 2, rightA);
        int midB = Math.min(leftB + (k - 1) / 2, rightB);
        if (nums1[midA] <= nums2[midB]) {
            return findKthEle(nums1, midA + 1, rightA, nums2, leftB, rightB, k - (midA - leftA + 1));
        } else {
            return findKthEle(nums1, leftA, rightA, nums2, midB + 1, rightB, k - (midB - leftB + 1));
        }
    }
}

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) {
            throw new IllegalArgumentException("null input...");
        }
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.length;
        int m = nums2.length;
        int left = 0, right = n;
        int median1 = 0, median2 = 0;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i;
            int eleI = i < n ? nums1[i] : Integer.MAX_VALUE;
            int eleJ = j < m ? nums2[j] : Integer.MAX_VALUE;
            int eleIminusOne = i > 0 ? nums1[i - 1] : Integer.MIN_VALUE;
            int eleJminusOne = j > 0 ? nums2[j - 1] : Integer.MIN_VALUE;
            if (eleIminusOne <= eleJ) {
                median1 = Math.max(eleIminusOne, eleJminusOne);
                median2 = Math.min(eleI, eleJ);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (n + m) % 2 == 0 ? (median1 + median2) / 2.0D : median1;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
