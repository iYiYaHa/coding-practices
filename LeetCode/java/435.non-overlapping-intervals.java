/*
 * @lc app=leetcode id=435 lang=java
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals == null || intervals.length <= 0 || intervals[0].length<=0)
            return 0;
        Arrays.sort(intervals,(a,b)->a[0]-b[0]);
        int curLeft = intervals[0][0];
        int curRight = intervals[0][1];
        int cnt = 0;
        for(int i = 1;i<intervals.length;++i){
            int[] pair = intervals[i];
            if(pair[0]<curRight){//collapse
                ++cnt;
                curRight = Math.min(curRight,pair[1]);
            }else{
                curLeft = pair[0];
                curRight = pair[1];
            }
        }
        return cnt;
    }
}
// @lc code=end

