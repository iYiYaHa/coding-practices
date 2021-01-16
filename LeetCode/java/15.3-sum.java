/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.41%)
 * Likes:    8230
 * Dislikes: 891
 * Total Accepted:    1.1M
 * Total Submissions: 3.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums == null || nums.length <= 0)
            return new LinkedList<>();

        Arrays.sort(nums);

        List<List<Integer>> res = new LinkedList<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }
                if (k < nums.length - 1 && nums[k] == nums[k + 1]) {
                    --k;
                    continue;
                }
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    List<Integer> ele = new LinkedList<>();
                    ele.add(nums[i]);
                    ele.add(nums[j]);
                    ele.add(nums[k]);
                    res.add(ele);
                    ++j;
                    --k;
                } else if (sum > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
}
// @lc code=end
