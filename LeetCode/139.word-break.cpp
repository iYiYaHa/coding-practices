/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (34.75%)
 * Total Accepted:    317.3K
 * Total Submissions: 912.7K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
class SolutionA
{
    // Dynamic Programming
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> dict;
        for (string word : wordDict)
            dict.insert(word);
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                dp[i] = dict.find(s.substr(j, i - j + 1)) != dict.end() && (j == 0 || dp[j - 1]);
                if (dp[i])
                    break;
            }
        }
        return dp.back();
    }
};

class SolutionB
{
    // Dynamic Programming with optimization with the maximum and minimum word length.
    // Beats 100%, very niubi.
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> dict;
        int minLen = std::numeric_limits<int>::max(), maxLen = 0;
        for (string word : wordDict)
        {
            dict.insert(word);
            maxLen = std::max(maxLen, static_cast<int>(word.length()));
            minLen = std::min(minLen, static_cast<int>(word.length()));
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = minLen; i <= s.size(); ++i)
        {
            for (int j = i - minLen + 1; j >= std::max(1, i - maxLen + 1); --j)
            {
                dp[i] = dict.find(s.substr(j - 1, i - j + 1)) != dict.end() && (dp[j - 1]); // Be careful when computing subscript.
                if (dp[i])
                    break;
            }
        }
        return dp.back();
    }
};

class SolutionC
{
    map<string, bool> memo;
    // DFS with memoization
    bool dfs(string s, vector<string> &dict)
    {
        if (s == "")
            return false;
        if (memo.count(s) != 0)
            return memo[s];
        for (string word : dict)
        {
            if (s == word)
                return true;
            if (s.substr(0, word.length()) == word && dfs(s.substr(word.length()), dict))
            {
                memo.insert(std::make_pair(s, true));
                return true;
            }
        }
        memo.insert(std::make_pair(s, false));
        return false;
    }

  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        sort(wordDict.rbegin(), wordDict.rend());
        return dfs(s, wordDict);
    }
};

class SolutionD
{
    //BFS
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<int> visited;
        queue<int> queue;
        set<string> dict;
        for (string word : wordDict)
            dict.insert(word);
        queue.push(0);
        while (!queue.empty())
        {
            int begInd = queue.front();
            queue.pop();
            if (visited.find(begInd) == visited.end())
            {
                visited.insert(begInd);
                for (int endInd = begInd; endInd < s.size(); ++endInd)
                {
                    if (dict.find(s.substr(begInd, endInd - begInd + 1)) != dict.end())
                    {
                        if (endInd + 1 == s.size())
                            return true;
                        queue.push(endInd + 1);
                    }
                }
            }
        }
        return false;
    }
};
