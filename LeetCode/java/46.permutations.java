/*
 * @lc app=leetcode id=46 lang=java
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (62.89%)
 * Likes:    4670
 * Dislikes: 114
 * Total Accepted:    684.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        permuteCore(nums, 0, res);
        return res;
    }

    private void permuteCore(int[] nums, int pos, List<List<Integer>> res){
        if(pos == nums.length){
            List<Integer> ele = new LinkedList<>();
            for(int num : nums){
                ele.add(num);
            }
            res.add(ele);
            return;
        }
        for(int i = pos; i < nums.length; ++i){
            swap(nums, i, pos);
            permuteCore(nums, pos + 1, res);
            swap(nums, i, pos);
        }
    }

    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

// @lc code=end

