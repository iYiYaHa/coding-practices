/*
 * @lc app=leetcode id=139 lang=java
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>(wordDict);
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        dp[n] = true;
        for(int i = n-1;i>=0;--i){
            for(int j = i+1;j<=n;++j){
                dp[i] = words.contains(s.substring(i,j)) && dp[j];
                if(dp[i])break;
            }
        }
        return dp[0];
    }
}

// DFS with memorization
class Solution{
    public boolean wordBreak(String s, List<String> wordDict) {
        if(s.length() == 0)  
            return false;
            Map<String, Boolean> cache = new HashMap<>();
        return dfs(s,new HashSet<>(wordDict), cache);
    }

    private boolean dfs(String s, Set<String> wordDict, Map<String, Boolean> cache){
        if(s.length() == 0)
            return true;
        if(cache.containsKey(s)) return cache.get(s);
        for(String word: wordDict){
            int i = word.length();
            if(s.length()>=i
            &&s.substring(0,i).equals(word) 
            && dfs(s.substring(i),wordDict,cache)){
                cache.put(s,true);
                return true;
            }
        }
        cache.put(s,false);
        return false;
    }
}

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>(wordDict);
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        while(!queue.isEmpty()){
            Integer start = queue.remove();
            if(visited.contains(start))
                continue;
            if(start >= s.length())
                return true;
            for(String word:words){
                if((start+word.length()<=s.length())&&s.substring(start, start+word.length()).equals(word))
                    queue.add(start+word.length());
            }
            visited.add(start);
        }
        return false;
    }
}
// @lc code=end

