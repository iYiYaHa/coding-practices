/*
 * @lc app=leetcode id=1189 lang=java
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
    public int maxNumberOfBalloons(String text) {
        int bCnt = 0,aCnt = 0,lCnt = 0,oCnt = 0,nCnt = 0;
        for(int i = 0;i<text.length();++i){
            char ch = text.charAt(i);
            if(ch == 'b')++bCnt;
            else if(ch == 'a') ++aCnt;
            else if(ch == 'l') ++lCnt;
            else if(ch == 'o') ++oCnt;
            else if(ch == 'n') ++nCnt;
            else{}
        }
        lCnt/=2;
        oCnt/=2;
        int[] nums = new int[]{bCnt,aCnt,lCnt,oCnt,nCnt};
        int minVal = bCnt;
        for(int num:nums)
            minVal = Math.min(num,minVal);
        return minVal;
    }
}
// @lc code=end

