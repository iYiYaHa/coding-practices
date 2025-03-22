/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (40.16%)
 * Likes:    1070
 * Dislikes: 52
 * Total Accepted:    81.3K
 * Total Submissions: 201.6K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> t1(26, 0);
        vector<int> t2(26, 0);
        int len1 = s1.length(), len2 = s2.length();
        for (char ch : s1)
            ++t1[ch - 'a'];
        for (int i = 0; i < len2; ++i)
        {
            if (i >= len1)
            {
                --t2[s2[i - len1] - 'a'];
            }
            ++t2[s2[i] - 'a'];
            if (t1 == t2)
                return true;
        }
        return false;
    }
};
// @lc code=end
