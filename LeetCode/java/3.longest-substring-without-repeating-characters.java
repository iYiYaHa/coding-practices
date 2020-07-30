/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLen = 0;
        int[] table = new int[256];
        Arrays.fill(table, -1);
        for(int i = 0, j = 0;j<s.length();++j){
            i = Math.max(i,table[s.charAt(j)]);
            table[s.charAt(j)] = j+1;
            maxLen = Math.max(maxLen, j-i+1);
        }
        return maxLen;
    }
}
// @lc code=end

