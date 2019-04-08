/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (41.99%)
 * Total Accepted:    39.8K
 * Total Submissions: 94.9K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of
 * coin.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: amount = 10, coins = [10] 
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * You can assume that
 * 
 * 
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 * 
 * 
 */
class SolutionA
{
    // ref: https://leetcode.com/problems/coin-change-2/discuss/176706/Beginner-Mistake%3A-Why-an-inner-loop-for-coins-doensn't-work-Java-Soln
    // ref: https://leetcode.com/problems/coin-change-2/discuss/123701/Why-doesn't-it-work-I-changed-the-iterative-order
  public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = 0; i <= amount; ++i)
            {
                if (i - coin >= 0)
                    dp[i] += dp[i - coin];
            }
        }

        // The reason of below code doesn't work is that it consider duplicate combinations.
        // By put the coin loop outside, we only consider limited coins which avoid duplicate combinations.
        // This solution can also be seen as optimization on solution B.
        // BTW, this logic seems familiar to me as it may appeared in previously solved problems.
        // for (int i = 0; i <= amount; ++i)
        // {
        //     for (int coin : coins)
        //     {
        //         if (i - coin >= 0)
        //             dp[i] += dp[i - coin];
        //     }
        // }
        return dp.back();
    }
};

class SolutionB
{
    // Dynamic Programming where dp[i][j] represents the number of combinations to get i with first j coins.
  public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));
        for (int i = 0; i <= coins.size(); ++i)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 1; j <= coins.size(); ++j)
            {
                dp[i][j] = dp[i][j - 1];
                if (i >= coins[j - 1])
                    dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
        return dp[amount][coins.size()];
    }
};