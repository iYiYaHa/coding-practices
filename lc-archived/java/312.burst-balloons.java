/*
 * @lc app=leetcode id=312 lang=java
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
    public int maxCoins(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int[] padded = new int[nums.length + 2];
        System.arraycopy(nums, 0, padded, 1, nums.length);
        padded[0] = padded[nums.length+1] = 1;

        int[][] cache = new int[nums.length + 2][nums.length + 2];
        for (int i = 0; i < nums.length + 2; ++i) {
            for (int j = 0; j < nums.length + 2; ++j) {
                cache[i][j] = -1;
            }
        }
        return maxCoinsCore(padded, 0, nums.length + 1, cache);
    }

    private int maxCoinsCore(int[] nums, int left, int right, int[][] cache) {
        if (left + 1 == right) {
            return 0;
        }
        if (cache[left][right] != -1) {
            return cache[left][right];
        }

        int result = 0;
        for (int i = left + 1; i <= right - 1; ++i) {
            int tmp = nums[i] * nums[left] * nums[right]
                    + maxCoinsCore(nums, left, i, cache)
                    + maxCoinsCore(nums, i, right, cache);
            result = Math.max(result, tmp);
        }
        cache[left][right] = result;
        return cache[left][right];
    }
}
class Solution {
    public int maxCoins(int[] nums) {
        if(nums == null || nums.length <= 0)
            return 0;
        int[] padded = new int[nums.length+2];
        System.arraycopy(nums,0,padded,1,nums.length);
        padded[0] = padded[nums.length+1] = 1;
        int[][] dp = new int[nums.length+2][nums.length+2];
        for(int i = 0;i<nums.length+2;++i){
            dp[i][0] = padded[i];
            dp[i][1] = 0;
        }
        for(int len = 2;len<nums.length+2;++len){
            for(int i = 0;i+len<nums.length+2;++i){
                for(int k = i+1;k<i+len;++k){
                    dp[i][i+len] = Math.max(dp[i][i+len],padded[i]*padded[i+len]*padded[k]+dp[i][k]+dp[k][i+len]);
                }
            }
        }

        return dp[0][nums.length+1];
    }
}
// @lc code=end

