//Given booleantwo stringsjava.util.Map<java.lang.Character,java.lang.Integer> s java.util.Map<java.lang.Character,java.lang.Integer>and t of lengths m and n respectively, return the minimum
//window substring of s such that every character in t (including duplicates) is 
//included in the window. If there is no such substring, return the empty string 
//"". 
//
// The testcases will be generated such that the answer is unique. 
//
// A substring is a contiguous sequence of characters within the string. 
//
// 
// Example 1: 
//
// 
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' 
//from string t.
// 
//
// Example 2: 
//
// 
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
// 
//
// Example 3: 
//
// 
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
// 
//
// 
// Constraints: 
//
// 
// m == s.length 
// n == t.length 
// 1 <= m, n <= 10⁵ 
// s and t consist of uppercase and lowercase English letters. 
// 
//
// 
//Follow up: Could you find an algorithm that runs in O(m + n) time? Related 
//Topics Hash Table String Sliding Window 👍 8107 👎 489


import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> chCntInTarget = new HashMap<>();
        for (Character ch : t.toCharArray()) {
            Integer cnt = chCntInTarget.getOrDefault(ch, 0);
            chCntInTarget.put(ch, cnt + 1);
        }

        String ans = "";

        Map<Character, Integer> chCntInWindow = new HashMap<>();
        for(int beg = 0, end = 0; end < s.length(); ++end) {
            Character chAtEnd = s.charAt(end);
            chCntInWindow.merge(chAtEnd, 1, Integer::sum);

            // trim from left
            while (beg < end && (chCntInWindow.get(s.charAt(beg)) > chCntInTarget.getOrDefault(s.charAt(beg), 0))) {
                chCntInWindow.merge(s.charAt(beg), -1, Integer::sum);
                ++beg;
            }

            // check if the current window between beg and end
            // covers the target string.
            int windowSize = end - beg + 1;
            if (windowSize >= t.length() && isCovered(chCntInWindow, chCntInTarget)) {
                if (ans.isEmpty() || ans.length() > windowSize) {
                    ans = s.substring(beg, end + 1);
                }
            }
        }
        return ans;
    }

    private boolean isCovered(Map<Character, Integer> window, Map<Character, Integer> target) {
        for(Map.Entry<Character,Integer> chAndCnt: target.entrySet()){
            if(window.getOrDefault(chAndCnt.getKey(), 0) < chAndCnt.getValue())
                return false;
        }
        return true;
    }
}

class Solution {
    public String minWindow(String s, String t) {
        if(s.isEmpty() || t.isEmpty()){
            return "";
        }
        Map<Character, Integer> chCntOfTarget = new HashMap<>();
        for (Character ch : t.toCharArray()) {
            Integer cnt = chCntOfTarget.getOrDefault(ch, 0);
            chCntOfTarget.put(ch, cnt + 1);
        }

        int requiredChar = chCntOfTarget.size();
        int satisfiedChar = 0;

        int ansLeft = -1, ansRight = s.length();

        Map<Character, Integer> chCntOfWindow = new HashMap<>();
        for (int beg = 0, end = 0; end < s.length(); ++end) {
            Character chAtEnd = s.charAt(end);
            chCntOfWindow.merge(chAtEnd, 1, Integer::sum);

            if(chCntOfTarget.containsKey(chAtEnd) && Objects.equals(chCntOfWindow.get(chAtEnd), chCntOfTarget.get(chAtEnd))){
                ++satisfiedChar;
            }

            // trim from left
            while (beg < end && (chCntOfWindow.get(s.charAt(beg)) > chCntOfTarget.getOrDefault(s.charAt(beg), 0))) {
                Character chAtBeg = s.charAt(beg);
                chCntOfWindow.merge(chAtBeg, -1, Integer::sum);
                if (chCntOfTarget.containsKey(chAtBeg) && chCntOfWindow.getOrDefault(chAtBeg, 0) < chCntOfTarget.get(chAtBeg)) {
                    --satisfiedChar;
                }
                ++beg;
            }

            // If the current window between beg and end covers the target string.
            // Update the answer if necessary.
            int windowSize = end - beg + 1;
            if (requiredChar == satisfiedChar && ansRight - ansLeft + 1 > windowSize) {
                ansLeft = beg;
                ansRight = end;
            }
        }
        return ansRight != s.length() ? s.substring(ansLeft, ansRight + 1):"";
    }
}
class Solution {
    public String minWindow(String s, String t) {
        if(s.isEmpty() || t.isEmpty()){
            return "";
        }

        Map<Character, Integer> chCntInTarget = new HashMap<>();
        for (Character ch : t.toCharArray()) {
            chCntInTarget.merge(ch, 1, Integer::sum);
        }
        int requiredChar = chCntInTarget.size();

        int satisfiedChar = 0;
        int ansLeft = -1, ansRight = s.length();

        Map<Character, Integer> chCntInWindow = new HashMap<>();
        for (int beg = 0, end = 0; end < s.length(); ++end) {
            Character chAtEnd = s.charAt(end);
            chCntInWindow.merge(chAtEnd, 1, Integer::sum);

            if(chCntInTarget.containsKey(chAtEnd) && Objects.equals(chCntInWindow.get(chAtEnd), chCntInTarget.get(chAtEnd))){
                ++satisfiedChar;
            }

            while(beg <= end && satisfiedChar == requiredChar){
                // If the current window between beg and end covers the target string.
                // Update the answer if necessary.
                if (ansRight - ansLeft + 1 >  end - beg + 1) {
                    ansLeft = beg;
                    ansRight = end;
                }

                Character chAtBeg = s.charAt(beg);
                chCntInWindow.merge(chAtBeg, -1, Integer::sum);
                if (chCntInTarget.containsKey(chAtBeg) && chCntInWindow.getOrDefault(chAtBeg, 0) < chCntInTarget.get(chAtBeg)) {
                    --satisfiedChar;
                }
                ++beg;

            }
        }
        return ansRight != s.length() ? s.substring(ansLeft, ansRight + 1):"";
    }
}
//leetcode submit region end(Prohibit modification and deletion)
