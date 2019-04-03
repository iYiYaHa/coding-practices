/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (35.16%)
 * Total Accepted:    109.9K
 * Total Submissions: 312.4K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */
    // The introduce of circle making the last state relies on the decision of the first one, causing DP won't work anymore.
    // So here we divide whole solution into two sub solutions according to the first state.
class Solution {
    int helper(vector<int> &nums, int left, int right){
        int prev = 0, cur = 0;
        for(int i = left;i<=right;++i){
            int tmp = std::max(cur,prev+nums[i]);
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return std::max(helper(nums,0,nums.size()-2),helper(nums,1,nums.size()-1));
    }
};
