/*
 * @lc app=leetcode id=1047 lang=java
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
    public String removeDuplicates(String s) {
        LinkedList<Character> stack = new LinkedList<>();
        for(int i = 0;i<s.length();++i){
            if(stack.isEmpty()||stack.getLast() != s.charAt(i)){
                stack.addLast(s.charAt(i));
            }else{
                stack.removeLast();
            }
        }
        StringBuilder sb = new StringBuilder();
        for(Character ch:stack){
            sb.append(ch);
        }
        return sb.toString();
    }
}
class Solution {
    public String removeDuplicates(String s) {
        int i = 0, n = s.length();
        char[] ch = s.toCharArray();
        for(int j = 0;j<n;++i,++j){
            ch[i] = ch[j];
            if(i>0 &&ch[i] == ch[i-1])
                i -= 2;
        }
        return new String(ch,0,i);
    }
}
// @lc code=end

