import java.util.HashMap;
import java.util.TreeSet;

/*
 * @lc app=leetcode id=220 lang=java
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (20.87%)
 * Likes:    1426
 * Dislikes: 1515
 * Total Accepted:    161K
 * Total Submissions: 755.7K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * Example 3:
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * nums[j]
 * 0 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^4
 * 0 <= t <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class SolutionA {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Long> treeSet = new TreeSet<>();
        for (int i = 0; i < nums.length; ++i) {
            Long leftBound = (long) nums[i] - t;
            Long ceilingNum = treeSet.ceiling(leftBound);
            if (ceilingNum != null && Math.abs(ceilingNum - nums[i]) <= t)
                return true;
            treeSet.add((long) nums[i]);
            if (treeSet.size() > k) {
                treeSet.remove((long) nums[i - k]);
            }
        }
        return false;
    }
}

// 维护一个大小为 k 的窗口，每次检测窗口中是否存在差的绝对值小于等于 t 的数字。如果线性遍历窗口，则 O(nk)
// 如果将窗口维护为 BST，则 O(nlogk)
// 如果想进一步优化查询窗口时 O(logk) 的复杂度，只能通过 Hash 的方法将其优化到 O(1)。
// 即如何通过 Hash 使得查询窗口中是否存在符合要求的目标数达到 O(1)。
// 因此，引入桶。
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        HashMap<Long, Long> map = new HashMap<>(); // 桶编号 -> 桶中数字
        Long width = (long) (t + 1);
        for (int i = 0; i < nums.length; ++i) {
            Long bucketId = getBucketId((long) nums[i], width);
            if (map.get(bucketId) != null)// 桶中已经存在一个数字，则该数字和当前数字之间的差距必定小于 t
                return true;
            if (map.get(bucketId - 1) != null && Math.abs(map.get(bucketId - 1) - nums[i]) <= t)
                return true;
            if (map.get(bucketId + 1) != null && Math.abs(map.get(bucketId + 1) - nums[i]) <= t)
                return true;
            map.put(bucketId, (long) nums[i]);
            if (map.size() > k) {
                map.remove(getBucketId((long) nums[i - k], width));
            }
        }
        return false;
    }

    private Long getBucketId(Long num, Long width) {
        // Get the ID of the bucket from element value x and bucket width w
        // In Java, `-3 / 5 = 0` and but we need `-3 / 5 = -1`.
        return num < 0 ? (num + 1) / width - 1 : num / width;
    }
}

// @lc code=end
