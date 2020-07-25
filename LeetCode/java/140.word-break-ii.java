/*
 * @lc app=leetcode id=140 lang=java
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> result = new LinkedList<>();
        Map<Integer, List<String>> cache = new HashMap<>();
        return dfs(s,wordDict, 0,cache);
    }

    private List<String> dfs(String s, List<String> wordDict, int pos, Map<Integer, List<String>> cache){
        if(cache.containsKey(pos)){
            return cache.get(pos);
        }
        List<String> result = new LinkedList<>();
        if(pos == s.length()){
            result.add("");
            return result;
        }
        for(String word:wordDict){
            if(pos+word.length()<=s.length() && s.substring(pos,pos+word.length()).equals(word)){
                List<String> subStrAns = dfs(s,wordDict,pos+word.length(),cache);
                for(String ans:subStrAns){
                    result.add(word+(ans.length()==0?"":" "+ans));
                }
            }
        }
        cache.put(pos,result);
        return result;
    }
}
// @lc code=end

