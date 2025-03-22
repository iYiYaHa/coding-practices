/*
 * @lc app=leetcode id=1143 lang=java
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start

// class Solution {
//     //TLE!!!

//     private HashMap<String, Integer> cache = new HashMap<>();
//     public int longestCommonSubsequence(String text1, String text2) {
//         if(text1.length() == 0 || text2.length() == 0)
//             return 0;
//         String key = text1+ " "+text2;
//         if(cache.containsKey(key))
//             return cache.get(key);
//         Integer result = 0;
//         if(text1.charAt(0) == text2.charAt(0)){
//             result = 1+longestCommonSubsequence(text1.substring(1),text2.substring(1));
//         }else{
//             result = Math.max(longestCommonSubsequence(text1.substring(1),text2),longestCommonSubsequence(text1,text2.substring(1)));
//         }
//         cache.put(key, result);
//         return cache.get(key);
//     }
// }

class Solution {

    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()+1][text2.length()+1];
        for(int i = 1;i<=text1.length();++i){
            for(int j = 1;j<=text2.length();++j){
                if(text1.charAt(i-1) == text2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
}
// @lc code=end

