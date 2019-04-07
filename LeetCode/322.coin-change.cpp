/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (29.48%)
 * Total Accepted:    178.1K
 * Total Submissions: 599.9K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class SolutionA
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int coin : coins)
            {
                if (i >= coin && dp[i - coin] != -1)
                {
                    dp[i] = dp[i] == -1 ? dp[i - coin] + 1 : std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp.back();
    }
};

class SolutionB
{
    // DFS with memoization
  private:
    int helper(vector<int> &coins, int amount, vector<int> &memo)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (memo[amount] != std::numeric_limits<int>::max())
            return memo[amount];
        int min = -1;
        for (int coin : coins)
        {
            int res = helper(coins, amount - coin, memo);
            if (res != -1)
                min = min == -1 ? res + 1 : std::min(res + 1, min);
        }
        memo[amount] = min;
        return min;
    }

  public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, std::numeric_limits<int>::max());
        return helper(coins, amount, memo);
    }
};
