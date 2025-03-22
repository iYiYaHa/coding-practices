/*
 * @lc app=leetcode id=10 lang=java
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
    public boolean isMatch(String s, String p) {
        if (s == null || p == null) {
            return false;
        }
        int lenS = s.length(), lenP = p.length();
        boolean[][] dp = new boolean[lenS + 1][lenP + 1];
        dp[lenS][lenP] = true;

        for (int i = lenS; i >= 0; --i) {
            for (int j = lenP - 1; j >= 0; --j) {
                boolean isCharMatch = i < lenS && (p.charAt(j) == '.' || s.charAt(i) == p.charAt(j));
                if (j + 1 < lenP && p.charAt(j + 1) == '*') {
                    dp[i][j] = dp[i][j + 2] || (isCharMatch && dp[i + 1][j]);
                } else {
                    dp[i][j] = isCharMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}

class Solution {
    public boolean isMatch(String s, String p) {
        return isMatchCore(s,p,0,0);
    }
    
    private boolean isMatchCore(String s, String p, int i, int j){
        if(j == p.length())
            return i == s.length();
        
        boolean isFirstMatch = i<s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
        if(j+1<p.length() && p.charAt(j+1) == '*'){
            return (isFirstMatch && isMatchCore(s,p,i+1,j)) || isMatchCore(s,p,i,j+2);
        }else{
            return isFirstMatch && isMatchCore(s,p,i+1,j+1);
        }
    }
}
// @lc code=end

