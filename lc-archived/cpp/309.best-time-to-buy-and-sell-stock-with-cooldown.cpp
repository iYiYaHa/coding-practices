//	//Problem : 309. Best Time to Buy and Sell Stock with Cooldown
//	//
//	//Problem Description:
//	//  Say you have an array for which the ith element is the price of a given stock on day i.
//	//  
//	//  Design an algorithm to find the maximum profit.You may complete as many transactions 
//	//  as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//	//  
//	//  You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//	//  After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//	//
//	//  Given a list of non - negative integers representing the amount of money of each house, 
//	//  determine the maximum amount of money you can rob tonight without alerting the police.
//	//
//	//  Example1:
//	//  Input: [1,2,3,0,2]
//	//  Output: 3
//	//  Explanation : transactions = [buy, sell, cooldown, buy, sell]
//	//
//
#include<iostream>
#include<vector>
#include<algorithm>
	class SolutionA {
	public:
		int maxProfit(std::vector<int>& prices) {
			if (prices.size() <= 0)
				return 0;
			std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(3, 0));
			dp[0][0] = -prices[0];
			for (int i = 1; i < prices.size(); ++i) {
				dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
				dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][2]);
				dp[i][2] = dp[i - 1][0] + prices[i];
			}
			return std::max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
		}
};
class SolutionB {
public:
	int maxProfit(std::vector<int>& prices) {
		if (prices.size() <= 0)
			return 0;
		std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
		dp[0][0] = -prices[0];
		if (prices.size() >= 2) {
			dp[1][0] = std::max(dp[0][0], -prices[1]);
			dp[1][1] = std::max(dp[0][1], dp[0][0] + prices[1]);
		}

		for (int i = 2; i < prices.size(); ++i) {
			dp[i][0] = std::max(dp[i - 1][0], dp[i - 2][1] - prices[i]);//hold
			dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);//unhold
		}
		return dp[prices.size() - 1][1];
	}
};

class SolutionC {
public:
	int maxProfit(std::vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
			return 0;
		std::vector<int> dp(n, 0);
		int maxPrev = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i] = std::max(dp[i - 1], prices[i] + maxPrev);
			maxPrev = std::max(maxPrev, (i >= 2 ? dp[i - 2] : 0) - prices[i]);
		}
		return dp[n - 1];
	}
};

class SolutionD {
public:
	int maxProfit(std::vector<int> &prices) {
		// First convert prices into profits.
		// Then each transaction can be seen as a consecutive subsequence in profits.
		// which are split by cool down days and no-action day.
		// dp[i] = the maximum profits if we take the profit of day i.
		// dp[i] = the max in 
		//         1. profits[i] (profits[i] is the start of a new sequence.)
		//         2. profits[i] + dp[i-1] (profits[i] is part of a subsequence.)
		//         3. profits[i] + max(dp[j] for all j <= i-3).(profits[i] is the start of a new subsequence, and the previous subsequences end at day j.)

		int n = prices.size();
		if (n < 2) return 0;
		int maxProfit = 0;
		std::vector<int> dp(n, 0);
		std::vector<int> profits(n, 0);
		for (int i = 1; i < n; ++i)
			profits[i] = prices[i] - prices[i - 1];
		int maxPrev = 0;
		for (int i = 0; i < n; ++i) {
			maxPrev = i >= 3 ? std::max(dp[i - 3], maxPrev) : maxPrev;
			int tmp = 0;
			tmp = std::max(tmp, i >= 1 ? dp[i - 1] : 0);
			tmp = std::max(tmp, maxPrev);
			dp[i] = profits[i] + tmp;
			maxProfit = std::max(maxProfit, dp[i]);
		}
		return maxProfit;
	}
};

int main()
{
	std::vector < std::vector<int>> testCase = { { 1,2,3,0,2 } };
	std::vector<int> testAns = { 3 };
	for (int i = 0; i < testCase.size(); ++i) {
		if (SolutionA().maxProfit(testCase[i]) == testAns[i]) {
			std::cout << "Test case " << i + 1 << " passed.\n";
		}
		else {
			std::cout << "Test case " << i + 1 << " failed.\n";
		}
	}
	std::cin.get();
	return 0;
}