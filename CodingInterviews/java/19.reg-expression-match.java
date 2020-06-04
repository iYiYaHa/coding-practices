class SolutionA {
    public boolean isMatch(String s, String p) {
        if(s == null || p == null)
            return false;
        int lenS = s.length(), lenP = p.length();
        boolean[][] dp = new boolean[lenS+1][lenP+1];
        dp[0][0] = true;
        for(int i = 0;i <= lenS;++i){
            for(int j = 1;j <= lenP;++j){
                if(p.charAt(j-1) == '*'){
                    if(i > 0 && (p.charAt(j-2) == '.' || p.charAt(j-2) == s.charAt(i-1))){
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-2] || dp[i][j-2];
                    }else{
                        dp[i][j] = dp[i][j-2];
                    }
                }else{
                    if(i > 0 && (p.charAt(j-1) == '.' || p.charAt(j-1) == s.charAt(i-1))){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[lenS][lenP];
    }
}

class SolutionB {
    public boolean isMatch(String s, String p) {
        if(s == null || p == null)
            return false;
        return helper(s, 0, p, 0);
    }

    private boolean helper(String s, int indS, String p, int indP){
        if(indS == s.length() && indP == p.length())
            return true;
        if(indS < s.length() && indP == p.length())
            return false;
        if(indP+1 < p.length() && p.charAt(indP+1) == '*'){
            if(indS < s.length() && (p.charAt(indP) == '.' || s.charAt(indS) == p.charAt(indP))){
                return helper(s, indS+1, p, indP+2) || helper(s, indS, p, indP+2) || helper(s, indS+1, p, indP);
            }else{
                return helper(s, indS, p, indP+2);
            }
        }else{
            if(indS < s.length() && (p.charAt(indP) == '.' || s.charAt(indS) == p.charAt(indP))){
                return helper(s, indS+1, p, indP+1);
            }else{
                return false;
            }

        }
    }
}

class SolutionC {

    private int[][] dp;

    Solution(){
    }
    public boolean isMatch(String s, String p) {
        if(s == null || p == null)
            return false;
        dp = new int[s.length()+1][p.length()+1];
        return helper(s, 0, p, 0);
    }

    private boolean helper(String s, int indS, String p, int indP){
        if(dp[indS][indP]!=0){
            return dp[indS][indP] == 2?true:false;
        }
        boolean res = false;
        if(indS == s.length() && indP == p.length()){
            dp[indS][indP] = 2;
            return true;
        }
        if(indS < s.length() && indP == p.length()){
            dp[indS][indP] = 1;
            return false;
        }
        if(indP+1 < p.length() && p.charAt(indP+1) == '*'){
            if(indS < s.length() && (p.charAt(indP) == '.' || s.charAt(indS) == p.charAt(indP))){
                res = helper(s, indS+1, p, indP+2) || helper(s, indS, p, indP+2) || helper(s, indS+1, p, indP);
            }else{
                res = helper(s, indS, p, indP+2);
            }
            dp[indS][indP] = res?2:1;
            return res;
        }else{
            if(indS < s.length() && (p.charAt(indP) == '.' || s.charAt(indS) == p.charAt(indP))){
                res = helper(s, indS+1, p, indP+1);
            }else{
                res =  false;
            }
            dp[indS][indP] = res?2:1;
            return res;
        }
    }
}

