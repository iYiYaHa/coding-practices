/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */
class SolutionA
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<vector<long>> dp(n + 1, vector<long>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
                // if(s[i-1]==t[j-1])
                // dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                // else
                // {
                //     dp[i][j]=dp[i-1][j];
                // }
            }
        }
        return dp[n][m];
    }
};

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<long> dp(n + 1, 1);
        for (int i = 1,prev = 0; i <= m; ++i)
        {
            prev = dp[0];
            dp[0] = 0;
            for (int j = 1; j <= n; ++j)
            {
                int tmp = dp[j];
                dp[j] = dp[j - 1] + (s[j - 1] == t[i - 1] ? prev : 0);
                prev = tmp;
            }
        }
        return dp[n];
    }
};
