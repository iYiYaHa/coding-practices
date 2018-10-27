//Problem : Target Sum
//
//Problem Description:
//  
//  You are given a list of non - negative integers, a1, a2, ..., an, and a target, S.Now you have 2 
//  symbols + and -.For each integer, you should choose one from + and -as its new symbol.
//  
//  Find out how many ways to assign symbols to make sum of integers equal to target S.
//  
//  Example 1:
//		Input: nums is[1, 1, 1, 1, 1], S is 3.
//		Output : 5
//		Explanation :
//  		-1 + 1 + 1 + 1 + 1 = 3
//  		+ 1 - 1 + 1 + 1 + 1 = 3
//  		+ 1 + 1 - 1 + 1 + 1 = 3
//  		+ 1 + 1 + 1 - 1 + 1 = 3
//  		+ 1 + 1 + 1 + 1 - 1 = 3
//  
//  		There are 5 ways to assign symbols to make the sum of nums be target 3.
//
//  Note:
// 
//  1.The length of the given array is positive and will not exceed 20.
//  2.The sum of elements in the given array will not exceed 1000.
//  3.Your output answer is guaranteed to be fitted in a 32 - bit integer.

// list all references
// https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C++-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation?page=1
// https://blog.csdn.net/sysu_xiamengyou/article/details/70986185
// https://leetcode.com/problems/target-sum/discuss/170191/Sharing-my-DP-and-DFS-solutions-in-C%25252B%25252B-with-explanation/191313
// https://leetcode.com/problems/target-sum/discuss/170191/Sharing-my-DP-and-DFS-solutions-in-C++-with-explanation
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
class Solution {
	// DFS
public:
	int findTargetSumWaysA(std::vector<int>& nums, int S) {
		return findTargetSumWaysRecursiveA(nums, 0, S);
	}
private:
	int findTargetSumWaysRecursiveA(std::vector<int> &nums, int beg, int target) {
		if (beg == nums.size())
			if (target == 0)
				return 1;
			else
				return 0;
		return findTargetSumWaysRecursiveA(nums, beg + 1, target + nums[beg]) + findTargetSumWaysRecursiveA(nums, beg + 1, target - nums[beg]);
	}
};

class SolutionA {
	// DFS with pruning
public:
	// Using sum_left to pruning
	int findTargetSumWays(std::vector<int>& nums, int S) {
		std::vector<int> sum_left(nums.size(), 0);
		sum_left[nums.size() - 1] = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; --i)
			sum_left[i] = sum_left[i + 1] + nums[i];
		return findTargetSumWaysRecursive(nums, sum_left, 0, S);
	}
private:

	int findTargetSumWaysRecursive(std::vector<int> &nums, std::vector<int> &sum_left, int beg, int target) {
		if (beg == nums.size())
			if (target == 0)
				return 1;
			else
				return 0;
		if (target > sum_left[beg] || target < -sum_left[beg])
			return 0;
		return findTargetSumWaysRecursive(nums, sum_left, beg + 1, target + nums[beg]) + findTargetSumWaysRecursive(nums, sum_left, beg + 1, target - nums[beg]);
	}
};
class SolutionC {
public:
	// subset sum
	int findTargetSumWays(std::vector<int>& nums, int S) {
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (S<-sum || S> sum || (S + sum) & 1)
			return 0;
		int target = (S + sum) / 2;
		std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(target + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= nums.size(); ++i) {
			dp[i][nums[i - 1]] = 1;
			for (int j = target; j >= 0; --j) {
				dp[i][j] = dp[i - 1][j];
				if (j >= nums[i - 1])
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
			}
		}
		return dp[nums.size()][target];
	}
};
class SolutionD {
public:
	// Can be seen as optimization on Solution C
	// Also can be seen as dp[i] = dp[i-nums[j]]
	int findTargetSumWays(std::vector<int>& nums, int S) {
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (S<-sum || S> sum || (S + sum) & 1)
			return 0;
		int target = (S + sum) / 2;
		std::vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (auto i : nums) {
			for (int j = target; j >= i; --j) {
				dp[j] += dp[j - i];
			}
		}
		return dp[target];
	}
};

class SolutionE {
public:
	int findTargetSumWays(std::vector<int>& nums, int S) {
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (S<-sum || S> sum || (S + sum) & 1)
			return 0;
		std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(2 * sum + 1, 0));
		dp[0][nums[0] + sum] += 1;//+= to handle nums[0] == 0
		dp[0][-nums[0] + sum] += 1;
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = 0; j < 2 * sum + 1; ++j) {
				int a = (j - nums[i]) >= 0 && (j - nums[i]) < 2 * sum + 1 ? dp[i - 1][j - nums[i]] : 0;
				int b = (j + nums[i]) >= 0 && (j + nums[i]) < 2 * sum + 1 ? dp[i - 1][j + nums[i]] : 0;
				dp[i][j] = a + b;
			}
		}
		return dp[nums.size() - 1][S + sum];
	}
};

int main() {
	Solution solution;
	std::vector<std::pair<std::vector<int>, int>> testCase = { std::make_pair(std::vector<int>({1, 1, 1, 1, 1}),3) };
	std::vector<int> testAns = { 5 };
	for (int i = 0; i < testCase.size(); ++i) {
		bool result = solution.findTargetSumWaysA(testCase[i].first, testCase[i].second) == testAns[i];
		if (result)
			std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
		else
			std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
	}
	std::cin.get();
	return 0;
}