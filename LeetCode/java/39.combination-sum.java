/*
 * @lc app=leetcode id=39 lang=java
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (55.51%)
 * Likes:    4817
 * Dislikes: 136
 * Total Accepted:    630.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * 
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null || candidates.length <= 0 || target < 0)
            return null;
        List<List<Integer>> res = new LinkedList<>();
        dfs(candidates, 0, target, 0, new LinkedList<Integer>(), res);
        return res;
    }

    private void dfs(int[] candidates, int pos, int target, int sum, LinkedList<Integer> comb,
            List<List<Integer>> res) {
        if (target <= sum) {
            if (!comb.isEmpty() && target == sum) {
                res.add(new LinkedList<>(comb));
            }
            return;
        }
        for (int i = pos; i < candidates.length; ++i) {
            comb.addLast(candidates[i]);
            dfs(candidates, i, target, sum + candidates[i], comb, res);
            comb.removeLast();
        }
    }
}

class SolutionB {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new LinkedList<>();
        dfs(candidates, target, 0, new LinkedList<>(), res);
        return res;
    }

    private void dfs(int[] candidates, int target, int pos, LinkedList<Integer> comb, List<List<Integer>> res) {
        if (pos >= candidates.length || target < 0)
            return;

        dfs(candidates, target, pos + 1, comb, res);

        target -= candidates[pos];
        comb.addLast(candidates[pos]);
        if (target == 0) {
            res.add(new LinkedList<>(comb));
        }
        dfs(candidates, target, pos, comb, res);
        target += candidates[pos];
        comb.removeLast();
    }
}
// @lc code=end
