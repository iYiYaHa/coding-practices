/*
 * @lc app=leetcode id=452 lang=java
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points == null || points.length <=0 || points[0].length<=0)
            return 0;
        Arrays.sort(points, (a,b)->a[1]-b[1]);
        int cnt = 1;
        int boundary = points[0][1];

        int ind = 1;
        while(ind<points.length){
            int[] pair = points[ind];
            if(boundary>=pair[0]){
                ++ind;
                continue;
            }else{
                ++cnt;
                boundary = pair[1];
            }
        }
        return cnt;
    }
}
// @lc code=end

