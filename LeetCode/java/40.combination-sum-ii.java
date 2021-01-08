/*
 * @lc app=leetcode id=40 lang=java
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (47.59%)
 * Likes:    2188
 * Dislikes: 75
 * Total Accepted:    361.2K
 * Total Submissions: 732.5K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
    // To understand the solution, think about the search tree formed during the dfs
    // process.
    // To avoid duplicate combinations, for each node, when going to its children
    // nodes, each value can only appear once in its children nodes.
    // To keep this uniqueness, we compare each candidate with its previous one when
    // picking the children node.
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new LinkedList<>();
        Arrays.sort(candidates);
        dfs(candidates, 0, target, new LinkedList<>(), res);
        return res;
    }

    private void dfs(int[] candidates, int pos, int target, LinkedList<Integer> comb, List<List<Integer>> res) {
        if (pos >= candidates.length)
            return;

        for (int i = pos; i < candidates.length; ++i) {
            if (i > pos && candidates[i] == candidates[i - 1])
                continue;
            target -= candidates[i];
            comb.addLast(candidates[i]);

            if (target == 0 && !comb.isEmpty()) {
                res.add(new LinkedList<>(comb));
            }

            // Pruning
            if (target >= 0)
                dfs(candidates, i + 1, target, comb, res);

            target += candidates[i];
            comb.removeLast();
        }

    }
}
// @lc code=end
