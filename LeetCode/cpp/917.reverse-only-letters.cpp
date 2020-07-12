/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (57.19%)
 * Likes:    457
 * Dislikes: 32
 * Total Accepted:    49.3K
 * Total Submissions: 85.8K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string S, return the "reversed" string where all characters that are
 * not a letter stay in the same place, and all letters reverse their
 * positions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "ab-cd"
 * Output: "dc-ba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S doesn't contain \ or "
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string str) {
        int left = 0, right = str.size()-1;
        while(left<=right){
            while(left<=right && !isChar(str[left]))++left;
            while(left<=right && !isChar(str[right]))--right;
            if(left<=right){swap(str[left],str[right]);++left;--right;
            }
        }
        return str;
    }

private:
    bool isChar(char ch){
        return (ch>='a' && ch<='z')||(ch>='A' && ch<='Z');
    }
};
// @lc code=end

