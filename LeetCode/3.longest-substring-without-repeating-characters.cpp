/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.61%)
 * Likes:    7975
 * Dislikes: 482
 * Total Accepted:    1.4M
 * Total Submissions: 4.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class SolutionA
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0)return 0;
        vector<int> posTable(256, -1);
        vector<int> dp(s.size(), 1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int ind = s[i];
            if (posTable[ind] < 0 || i - posTable[ind] > dp[i - 1])
            {
                dp[i] = (i >= 1 ? dp[i - 1] : 0) + 1;
            }
            else
            {
                dp[i] = i - posTable[ind];
            }
            posTable[ind] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//ref: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1730/Shortest-O(n)-DP-solution-with-explanations
class SolutionB
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> posTable(256, -1);
        int ans = 0;
        for(int i = 0,j = 0;i<s.size();++i){
            j = max(posTable[s[i]],j);
            posTable[s[i]] = i;
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
// @lc code=end
