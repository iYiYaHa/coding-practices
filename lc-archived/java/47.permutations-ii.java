/*
 * @lc app=leetcode id=47 lang=java
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (45.97%)
 * Likes:    2155
 * Dislikes: 64
 * Total Accepted:    374K
 * Total Submissions: 796K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        permuteUniqueCore(nums, 0, res);
        return res;
    }

    private void permuteUniqueCore(int[] nums, int pos, List<List<Integer>> res) {
        if (pos == nums.length) {
            List<Integer> ele = new LinkedList<>();
            for (int num : nums) {
                ele.add(num);
            }
            res.add(ele);
            return;
        }
        Set<Integer> swapped = new HashSet<>();
        for (int i = pos; i < nums.length; ++i) {
            if (!swapped.contains(nums[i])) {
                swapped.add(nums[i]);
                swap(nums, i, pos);
                permuteUniqueCore(nums, pos + 1, res);
                swap(nums, i, pos);
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
// @lc code=end
