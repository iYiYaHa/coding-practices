/*
 * @lc app=leetcode id=377 lang=java
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (45.11%)
 * Likes:    1781
 * Dislikes: 215
 * Total Accepted:    144.1K
 * Total Submissions: 314.3K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 */

// @lc code=start
class Solution {
    public int combinationSum4(int[] nums, int target) {
        HashMap<Integer, Integer> cache = new HashMap<>();
        return dfs(nums, target, cache);
    }

    private int dfs(int[] nums, int target, HashMap<Integer, Integer> cache) {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (cache.containsKey(target))
            return cache.get(target);
        int res = 0;
        for (int i = 0; i < nums.length; ++i) {
            res += dfs(nums, target - nums[i], cache);
        }
        cache.put(target, res);
        return res;
    }
}
// @lc code=end
