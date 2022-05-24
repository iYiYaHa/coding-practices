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
// Related Topics Array Binary Search Divide and Conquer 👍 16438 👎 2005


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) {
            throw new IllegalArgumentException("Input array is null...");
        }
        int totalLen = nums1.length + nums2.length;
        if ((totalLen & 1) == 1) {
            return findKthNumInTwoSortedArrays(nums1, nums2, totalLen / 2);
        } else {
            int kthEle = findKthNumInTwoSortedArrays(nums1, nums2, (totalLen / 2));
            int k1thEle = findKthNumInTwoSortedArrays(nums1, nums2, (totalLen / 2 - 1));
            System.out.println((totalLen / 2) + " "+(totalLen / 2 - 1));
            System.out.println(kthEle + " " +k1thEle);
            return (kthEle + k1thEle) / 2.0;
        }
    }

    private int findKthNumInTwoSortedArrays(int[] nums1, int[] nums2, int k) {
        return findKthNumInTwoSortedArraysCore(nums1, 0, nums1.length - 1, nums2, 0, nums2.length - 1, k);
    }

    private int findKthNumInTwoSortedArraysCore(int[] nums1, int leftA, int rightA, int[] nums2, int leftB, int rightB, int k) {
        if (leftA > rightA) {
            return nums2[leftB + k];
        }
        if (leftB > rightB) {
            return nums1[leftA + k];
        }
        if (k == 0) {
            return Math.min(nums1[leftA], nums2[leftB]);
        }

        int midA = Math.min(leftA + k / 2, rightA - 1);
        int midB = Math.min(leftB + k / 2, rightB - 1);
        if (nums1[midA] <= nums2[midB]) {
            return findKthNumInTwoSortedArraysCore(nums1, midA + 1, rightA, nums2, leftB, rightB, k - (midA - leftA + 1));
        } else {
            return findKthNumInTwoSortedArraysCore(nums1, leftA, rightA, nums2, midB + 1, rightB, k - (midB - leftB + 1));
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
