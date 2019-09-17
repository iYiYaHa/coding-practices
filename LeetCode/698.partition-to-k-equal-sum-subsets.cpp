/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */
class SolutionA
{
private:
    bool helper(vector<int> &nums, int k, int sum, int target)
    {
        if (k == 1)
            return true;
        if (sum == target)
            return helper(nums, k - 1, 0, target);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0 || sum + nums[i] > target)
                continue;
            int tmp = nums[i];
            nums[i] = 0;
            if (helper(nums, k, sum + tmp, target))
                return true;
            nums[i] = tmp;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());

        // Impossible under following circumstances.
        // k <= 0 invalid input
        // sum can not be divided by k
        // The largest number is bigger than sum/k
        if (k <= 0 || sum % k != 0 || nums[0] > (sum / k))
            return false;
        return helper(nums, k, 0, sum / k);
    }
};

class SolutionB
{
private:
    bool helper(vector<int> &nums, int ind, vector<int> &bins, int target)
    {
        if (ind >= nums.size())
            return true;
        for (int i = 0; i < bins.size(); ++i)
        {
            if (bins[i] + nums[ind] <= target)
            {
                bins[i] += nums[ind];
                if (helper(nums, ind + 1, bins, target))
                    return true;
                bins[i] -= nums[ind];
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());
        if (k <= 0 || sum % k != 0 || nums[0] > (sum / k))
            return false;
        vector<int> bins(k, 0);
        return helper(nums, 0, bins, sum / k);
    }
};

class Solution
{
//ref:https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/335668/DP-with-Bit-Masking-Solution-%3A-Best-for-Interviews
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());
        int target = sum / k, n = nums.size();
        if (k <= 0 || sum % k != 0 || nums[0] > target)
            return false;

        vector<bool> dp(1 << n, false);
        dp[0] = true;
        vector<int> subsetSum(1 << n);

        for (int i = 0; i < (1 << n); ++i)
        {
            if (dp[i])
            {
                for (int j = 0; j < n; ++j)
                {
                    int newSubset = i | (1 << j);
                    if (newSubset != i)
                    {
                        if (nums[j] <= target - (subsetSum[i] % target))
                        { //nums[j] not in subset represented by i
                            dp[newSubset] = true;
                            subsetSum[newSubset] = subsetSum[i] + nums[j];
                        }
                        else
                            break;
                    }
                }
            }
        }

        return dp.back();
    }
};
