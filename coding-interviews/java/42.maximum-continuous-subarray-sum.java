class SolutionA {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length <= 0){
            throw new IllegalArgumentException("Empty array.");
        }
        int maxSum = nums[0];
        int sum = 0;
        for(int num:nums){
            sum += num;
            maxSum = Math.max(maxSum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
}

class SolutionB {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length <= 0){
            throw new IllegalArgumentException("Empty array.");
        }
        int maxSum = nums[0];
        int[] dp = new int[nums.length+1];
        for(int i = 1;i<=nums.length;++i){
            dp[i] = Math.max(0, dp[i-1]) + nums[i-1];
            maxSum = Math.max(dp[i], maxSum);
        }
        return maxSum;
    }
}