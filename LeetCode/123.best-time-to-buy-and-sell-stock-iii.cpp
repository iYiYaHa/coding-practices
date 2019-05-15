/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
class SolutionA
{
    // When we define states and state transition equation, think more from the view of states rather than actions.
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][2] = numeric_limits<int>::min();
        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(-prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return max(dp.back()[1], dp.back()[3]);
    }
};

class SolutionB
{
    // Think about the reason adjusting the orders of the above four assignments.
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 0)
            return 0;
        vector<int> dp(4, 0);
        dp[0] = numeric_limits<int>::min();
        dp[2] = numeric_limits<int>::min();
        for (int i = 0; i < prices.size(); ++i)
        {
            dp[3] = max(dp[3], dp[2] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[0] = max(-prices[i], dp[0]);
        }
        return max(dp[1], dp[3]);
    }
};

class Solution
{
    // left_right[i] the maximum profit can be made by at most one transaction in prices[0..i]
    // right_left[i] the maximum profit can be made by at most one transaction in prices[i+1..n]
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 0)
            return 0;
        int n = prices.size();
        vector<int> left_right(n, 0);
        vector<int> right_left(n, 0);
        int res = std::numeric_limits<int>::min();
        for (int i = 0, minNum = numeric_limits<int>::max(),
                 localMax = numeric_limits<int>::min();
             i < n; ++i)
        {
            minNum = min(minNum, prices[i]);
            localMax = max(localMax, prices[i] - minNum);
            left_right[i] = localMax;
        }

        for (int i = n - 2, maxNum = numeric_limits<int>::min(),
                 localMax = numeric_limits<int>::min();
             i >= 0; --i)
        {
            maxNum = max(maxNum, prices[i + 1]);
            localMax = max(localMax, maxNum - prices[i + 1]);
            right_left[i] = localMax;
        }
        for (int i = 0; i < n; ++i)
        {
            res = max(res, left_right[i] + right_left[i]);
        }
        return res;
    }
};
