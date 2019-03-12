/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (39.32%)
 * Total Accepted:    28.8K
 * Total Submissions: 73.1K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 *
 *
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 *
 *
 *
 * Note:
 *
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 *
 *
 *
 * Example 1:
 *
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 *
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are ¡°10,¡±0001¡±,¡±1¡±,¡±0¡±
 *
 *
 *
 * Example 2:
 *
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 *
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 *
 *
 */
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>

class SolutionA
{
	// 0-1 knapsack
public:
	int findMaxForm(std::vector<std::string> &strs, int m, int n)
	{
		std::vector<std::vector<std::vector<int>>> dp(strs.size() + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));
		std::vector<std::pair<int, int>> weights;
		// Preprocessing cost of each string
		for (const std::string &str : strs)
		{
			int ones = std::count_if(str.begin(), str.end(), [](unsigned char c) { return c == '1'; });
			int zeroes = std::count_if(str.begin(), str.end(), [](unsigned char c) { return c == '0'; });
			weights.push_back(std::make_pair(ones, zeroes));
		}

		for (int i = 1; i <= strs.size(); ++i)
		{
			int ones = weights[i - 1].first;
			int zeroes = weights[i - 1].second;
			for (int j = 0; j <= m; ++j)
			{
				for (int k = 0; k <= n; ++k)
				{
					dp[i][j][k] = dp[i - 1][j][k];
					if (j >= zeroes && k >= ones)
					{
						dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - zeroes][k - ones] + 1);
					}
				}
			}
		}

		return dp[strs.size()][m][n];
	}
};

class SolutionB
{
	// Optimized from above solution
public:
	int findMaxForm(std::vector<std::string> &strs, int m, int n)
	{
		std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
		for (int i = 1; i <= strs.size(); ++i)
		{
			int ones = std::count_if(strs[i - 1].begin(), strs[i - 1].end(), [](unsigned char c) { return c == '1'; });
			int zeroes = std::count_if(strs[i - 1].begin(), strs[i - 1].end(), [](unsigned char c) { return c == '0'; });
			for (int j = m; j >= zeroes; --j)
			{
				for (int k = n; k >= ones; --k)
				{
					dp[j][k] = std::max(dp[j][k], dp[j - zeroes][k - ones] + 1);
				}
			}
		}

		return dp[m][n];
	}
};
