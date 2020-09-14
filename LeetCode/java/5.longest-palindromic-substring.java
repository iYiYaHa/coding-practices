import java.util.Map;

/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.32%)
 * Likes:    7897
 * Dislikes: 569
 * Total Accepted:    1M
 * Total Submissions: 3.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
// class Solution {
//     public String longestPalindrome(String s) {
//         int n = s.length();
//         boolean[][] dp = new boolean[n + 1][n + 1];
//         String ans = "";
//         dp[0][0] = true;
//         for (int i = n; i >= 1; --i) {
//             for (int j = i; j <= n; ++j) {
//                 if (i == j)
//                     dp[i][j] = true;
//                 else if (i + 1 == j) {
//                     dp[i][j] = s.charAt(i - 1) == s.charAt(j - 1);
//                 } else {

//                     dp[i][j] = s.charAt(i - 1) == s.charAt(j - 1) && dp[i + 1][j - 1];
//                 }
//                 if (dp[i][j]) {
//                     if (j - i + 1 >= ans.length()) {
//                         ans = s.substring(i - 1, j);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// }

// class Solution {
//     public String longestPalindrome(String s) {
//         int n = s.length();
//         String ans = "";
//         for (int i = 0; i < n; ++i) {
//             // odd length
//             String oddPalidromeStr = findPalindromeWithCenter(s, i, i);
//             // even length
//             String evenPalindromStr = findPalindromeWithCenter(s, i, i + 1);

//             if (oddPalidromeStr.length() > ans.length())
//                 ans = oddPalidromeStr;
//             if (evenPalindromStr.length() > ans.length())
//                 ans = evenPalindromStr;
//         }
//         return ans;
//     }

//     private String findPalindromeWithCenter(String s, int left, int right) {
//         while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
//             --left;
//             ++right;
//         }
//         return s.substring(left + 1, right);
//     }
// }


class Solution {
    public String longestPalindrome(String s) {
        String preStr = preprocess(s);
        String ans = "";
        int maxRight = -1;
        int maxLen = 1;
        int center = 0;
        int[] centerLen = new int[preStr.length()];
        for (int i = 0; i < preStr.length(); ++i) {
            if (maxRight > i) {
                centerLen[i] = Math.min(maxRight - i, centerLen[2 * center - i]);
            }
            // 左右展开
            while (i - centerLen[i] >= 0 &&
                    i + centerLen[i] < preStr.length() &&
                    preStr.charAt(i - centerLen[i]) == preStr.charAt(i + centerLen[i])) {
                ++centerLen[i];
            }

            // 更新最右侧
            if (i + centerLen[i] > maxRight) {
                center = i;
                maxRight = i + centerLen[i];
            }

            // 更新 answer
            if (centerLen[i] > maxLen) {
                maxLen = centerLen[i];
                int ind = (i - maxLen + 1) / 2;
                ans = s.substring(ind, ind + maxLen - 1);
            }
        }
        return ans;
    }

    private String preprocess(String str) {
        StringBuilder sb = new StringBuilder();
        sb.append("#");
        for (int i = 0; i < str.length(); ++i) {
            sb.append(str.charAt(i));
            sb.append("#");
        }
        return sb.toString();
    }
}

// @lc code=end
