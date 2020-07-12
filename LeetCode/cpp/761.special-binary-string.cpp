/*
 * @lc app=leetcode id=761 lang=cpp
 *
 * [761] Special Binary String
 */

// Taken 1 as ( and 0 as 0, each special binary string can be regarded as valid parenthese.
// Then there are two different of circumstances:
//  (a) nested VP which looks like ((...))
//  (b) unnested VP consists of several continuous sub VP which looks like (...)(...)
// For (a), we recursively handle the inner part.
// For (b), we just find all VP and rank them.

class Solution
{
public:
    string makeLargestSpecial(string S)
    {
        int cnt = 0;
        vector<string> subStr;

        // Find all sub special binary strings
        for (int i = 0, j = 0; j < S.size(); ++j)
        {
            cnt += S[j] == '1' ? 1 : -1;
            if (cnt == 0)
            {
                subStr.push_back('1' +makeLargestSpecial( S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        // Rank all sub special strings.
        sort(subStr.begin(),subStr.end(),std::greater<string>());

        // Assemble all sub special strings into a whole one as final result.
        string res = "";
        for(string str:subStr){
            res+=str;
        }
        return res;
    }
};
