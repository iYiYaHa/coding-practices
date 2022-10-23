//Given n pairs of parentheses, write a function to generate all combinations 
//of well-formed parentheses. 
//
// 
// Example 1: 
// Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
// 
// Example 2: 
// Input: n = 1
//Output: ["()"]
// 
// 
// Constraints: 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 2923 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    public List<String> generateParenthesis(int n) {
        if (n <= 0) {
            return new ArrayList<>();
        }
        List<String> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        dfs(res, sb, 0, n, n);
        return res;
    }

    private void dfs(List<String> res, StringBuilder sb, int unmatchedLeftBrace, int unusedLeftBrace, int unusedRightBrace) {
        if (unusedLeftBrace == 0 && unusedRightBrace == 0) {
            res.add(sb.toString());
            return;
        }
        if (unusedLeftBrace > 0) {
            sb.append("(");
            dfs(res, sb, unmatchedLeftBrace + 1, unusedLeftBrace - 1, unusedRightBrace);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (unmatchedLeftBrace > 0 && unusedRightBrace > 0) {
            sb.append(")");
            dfs(res, sb, unmatchedLeftBrace - 1, unusedLeftBrace, unusedRightBrace - 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}

class Solution {

    private ArrayList[] cache;

    public List<String> generateParenthesis(int n) {
        if (n < 0) {
            return new ArrayList<>();
        }
        if (cache == null) {
            cache = new ArrayList[n + 1];
        }
        if (cache[n] != null) {
            return cache[n];
        }
        if (n == 0) {
            return Arrays.asList("");
        }
        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (String left : generateParenthesis(i)) {
                for (String right : generateParenthesis(n - i - 1)) {
                    String res = "(" + left + ")" + right;
                    ans.add(res);
                }
            }
        }
        cache[n] = ans;
        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
