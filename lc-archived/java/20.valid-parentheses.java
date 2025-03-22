import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
    Map<Character,Character> pair;
    List<Character> leftBrackets;
    List<Character> rightBrackets;
    public Solution(){
        pair = new HashMap<>();
        pair.put('}','{');
        pair.put(')','(');
        pair.put(']','[');
        leftBrackets = new LinkedList<>(Arrays.asList('[','{','('));
        rightBrackets = new LinkedList<>(Arrays.asList(')','}',']'));

    }
    public boolean isValid(String s) {
        LinkedList<Character> stack = new LinkedList<>();

        for (Character ch : s.toCharArray()) {
            if(leftBrackets.contains(ch)){
                stack.addLast(ch);
            }
            if(rightBrackets.contains(ch)){
                if(!stack.isEmpty() && stack.peekLast().equals(pair.get(ch))){
                    stack.removeLast();
                }else{
                    return false;
                }
            }
            
        }
        return stack.isEmpty();
    }
}
// @lc code=end
