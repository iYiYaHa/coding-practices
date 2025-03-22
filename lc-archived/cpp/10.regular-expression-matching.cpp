/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (26.19%)
 * Likes:    3600
 * Dislikes: 632
 * Total Accepted:    387.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// @lc code=start
class SolutionA
{
public:
    bool isMatch(string s, string p)
    {
        return isMatchRecursively(s, p, 0, 0);
    }

private:
    bool isMatchRecursively(const string &s, const string &p, int i, int j)
    {
        if (j == p.length())
            return i == s.length();

        bool isFirstMatch = i < s.length() && (p[j] == '.' || s[i] == p[j]);
        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            return isMatchRecursively(s, p, i, j + 2) ||
                   (isFirstMatch && isMatchRecursively(s, p, i + 1, j));
        }
        else
        {
            return isFirstMatch && isMatchRecursively(s, p, i + 1, j + 1);
        }
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[s.length()][p.length()] = true;

        for (int i = s.length(); i >= 0; --i)
        {
            for (int j = p.length() - 1; j >= 0; --j)
            {
                bool isFirstMatch = i < s.length() && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < p.length() && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || (isFirstMatch && dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = isFirstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
