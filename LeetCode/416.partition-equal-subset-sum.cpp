/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (39.90%)
 * Total Accepted:    74.9K
 * Total Submissions: 187.6K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 *
 *
 * Note:
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 *
 *
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 */

#include<vector>
#include<algorithm>
#include<bitset>
#include<numeric>

class SolutionA
{
	//bitset
public:
	bool canPartition(std::vector<int> &nums)
	{
		const int MAX_NUM = 100;
		const int MAX_SIZE = 200;
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1)
			return false;
		sum >>= 1;
		std::bitset<MAX_NUM * MAX_SIZE> bitset;
		bitset[0] = 1;
		for (const int num : nums)
		{
			bitset |= bitset << num;
		}
		return bitset[sum];
	}
};

class SolutionB
{
	// dynamic programming
public:
	bool canPartition(std::vector<int> &nums)
	{
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		sum >>= 1;

		std::vector<std::vector<bool>> dp(nums.size() + 1, std::vector<bool>(sum + 1, false));
		for (int i = 1; i <= nums.size(); ++i)
		{
			dp[i][0] = true;
			for (int j = 1; j <= sum; ++j)
			{
				dp[i][j] = dp[i - 1][j] || ((j - nums[i - 1] >= 0) && dp[i - 1][j - nums[i - 1]]);
			}
		}
		return dp[nums.size()][sum];
	}
};

class SolutionC
{
	// Optimized dynamic programming
public:
	bool canPartition(std::vector<int> &nums)
	{
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		sum >>= 1;

		std::vector<std::vector<bool>> dp(2, std::vector<bool>(sum + 1, false));
		for (int i = 1; i <= nums.size(); ++i)
		{
			dp[i % 2][0] = true;
			for (int j = 1; j <= sum; ++j)
			{
				dp[i % 2][j] = dp[(i - 1) % 2][j] || ((j - nums[i - 1] >= 0) && dp[(i - 1) % 2][j - nums[i - 1]]);
			}
			if (dp[i % 2].back())
				return true;
		}
		return dp[nums.size() % 2][sum];
	}
};

class SolutionD
{
	// backtracking with pruning
private:
	bool helper(const std::vector<int> &nums, int front, int target)
	{
		if (target == 0)
			return true;
		if (target < 0 || front >= nums.size())
			return false;
		for (int i = front; i < nums.size(); ++i)
		{
			if (i > front && nums[i] == nums[i - 1])
				continue;
			if (helper(nums, i + 1, target - nums[i]))
				return true;
		}
		return false;
	}

public:
	bool canPartition(std::vector<int> &nums)
	{
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1)
			return false;
		sum >>= 1;
		std::sort(nums.rbegin(), nums.rend());
		return helper(nums, 0, sum);
	}
};

class SolutionE
{
	// magic code
	// like pruned backtracking
	// Update: Wrong solution!!! Just pass all solutions coincidently.
public:
	bool canPartition(std::vector<int> &nums)
	{
		if (nums.size() < 2)
			return false;
		int total = std::accumulate(nums.begin(), nums.end(), 0);

		std::sort(nums.rbegin(), nums.rend());
		int target = total / 2;
		// total must be even, and no member can be larger than half the total
		if ((total % 2) || (nums[0] > target))
			return false;

		for (int i = 0; i < nums.size(); ++i)
		{
			int test = nums[i];
			for (int j = i + 1; test < target && j < nums.size(); ++j)
			{
				if (test + nums[j] <= target)
				{
					test = test + nums[j];
				}
			}
			if (test == target)
				return true;
		}
		return false;
	}
};