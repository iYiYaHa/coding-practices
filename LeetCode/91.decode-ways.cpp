/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// There are many details and corner cases in this problem. Be careful.
class SolutionA
{
public:
    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        int n = s.length();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != '0') // s[i]
                dp[i] = i >= 1 ? dp[i - 1] : 1;

            if (i >= 1 && s[i - 1] !='0')
            {
                int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if (num >= 1 && num <= 26)
                    dp[i] += i >= 2 ? dp[i - 2] : 1;
            }
        }
        return dp.back();
    }
};

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        int n = s.length();
        int prev2 = 1, prev1= 1,ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = 0;
            if (s[i] != '0') // s[i]
                ans = prev1;

            if (i >= 1 && s[i - 1] !='0')
            {
                int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if (num >= 1 && num <= 26)
                    ans += prev2;
            }
            prev2=prev1;
            prev1=ans;
        }
        return ans;
    }
};
