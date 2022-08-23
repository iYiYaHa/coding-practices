//There is an integer array nums sorted in ascending order (with distinct 
//values). 
//
// Prior to being passed to your function, nums is possibly rotated at an 
//unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k]
//, nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For 
//example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0
//,1,2]. 
//
// Given the array nums after the possible rotation and an integer target, 
//return the index of target if it is in nums, or -1 if it is not in nums. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
// Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
// 
// Example 2: 
// Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1
// 
// Example 3: 
// Input: nums = [1], target = 0
//Output: -1
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5000 
// -10⁴ <= nums[i] <= 10⁴ 
// All values of nums are unique. 
// nums is an ascending array that is possibly rotated. 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related Topics 数组 二分查找 👍 2257 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//
//    public int search(int[] nums, int target) {
//        if (nums == null || nums.length <= 0) {
//            return -1;
//        }
//        int left = 0, right = nums.length - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] == target) {
//                return mid;
//            }
//            if (nums[mid] <= nums[right]) {
//                // Think which part is in order
//                // nums[mid] ~ nums[right] is ascending
//                // By judging whether target is between nums[mid] and nums[right]
//                // we can know whether to search the left part(nums[left] ~ nums[mid])
//                // or the right part(nums[mid] ~ nums[right]);
//                if (nums[mid] <= target && target <= nums[right]) {
//                    left = mid + 1;
//                } else {
//                    right = mid - 1;
//                }
//            } else {
//                if (nums[mid] >= target && target >= nums[left]) {
//                    right = mid - 1;
//                } else {
//                    left = mid + 1;
//                }
//            }
//        }
//        return -1;
//    }
//}

//https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution
//class Solution {
//
//    public int search(int[] nums, int target) {
//        if (nums == null || nums.length <= 0) {
//            return -1;
//        }
//        int rotateInd = getRotateIndInRotatedArray(nums);
//        System.out.println(rotateInd);
//        return searchInRotatedArray(nums, target, rotateInd);
//
//    }
//
//    private int searchInRotatedArray(int[] nums, int target, int rotateInd) {
//        int left = 0, right = nums.length - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            int realMid = (mid + rotateInd) % nums.length;
//            if (nums[realMid] == target) {
//                return realMid;
//            }
//            if (nums[realMid] < target) {
//                left = mid + 1;
//            } else {
//                right = mid - 1;
//            }
//        }
//        return -1;
//    }
//
//    private int getRotateIndInRotatedArray(int[] nums) {
//        int left = 0, right = nums.length - 1;
//        while (left < right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > nums[right]) {
//                left = mid + 1;
//            } else {
//                right = mid;
//            }
//        }
//        return left;
//    }
//}

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me
class Solution {

    public int search(int[] nums, int target) {
        if (nums == null || nums.length <= 0) {
            return -1;
        }
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = (target < nums[0]) == (nums[mid] < nums[0]) ? nums[mid]:
            (target < nums[0] ? Integer.MIN_VALUE : Integer.MAX_VALUE);
            if (num == target) {
                return mid;
            } else if (num > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;

    }
}
//leetcode submit region end(Prohibit modification and deletion)
