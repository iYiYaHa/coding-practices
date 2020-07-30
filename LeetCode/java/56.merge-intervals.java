/*
 * @lc app=leetcode id=56 lang=java
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {

    private class Pair<A,B>{
        A first;
        B second;

        Pair(A first, B second){
            this.first = first;
            this.second = second;
        }

        A getFirst(){
            return first;
        }

        B getSecond(){
            return second;
        }
    }

    public int[][] merge(int[][] intervals) {
        if(intervals == null || intervals.length <= 0 || intervals[0].length<=0)
            return intervals;
        List<Pair<Integer,Integer>> result = new LinkedList<>();
        Arrays.sort(intervals, (a,b)->a[0]-b[0]);
        Integer curLeft = intervals[0][0], curRight = intervals[0][1];
        for(int i = 1;i<intervals.length;++i){
            int[] pair = intervals[i]; 
            if(curRight>=pair[0]){
                curRight = Math.max(pair[1],curRight);
                curLeft = Math.min(pair[0],curLeft);
            }else{
                result.add(new Pair(curLeft,curRight));
                curLeft = pair[0];
                curRight = pair[1];
            }
        }
        result.add(new Pair(curLeft,curRight));

        int[][] ans = new int[result.size()][2];
        int ind = 0;
        for(Pair<Integer,Integer> pair:result){
            ans[ind][0] = pair.getFirst();
            ans[ind][1] = pair.getSecond();
            ++ind;
        }
        return ans;
    }
}

class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals == null||intervals.length <= 0)
            return new int[0][0];
        Arrays.sort(intervals, (a,b)->a[0]-b[0]);
        LinkedList<int[]> res = new LinkedList<>();
        for(int[] pair:intervals){
            if(res.isEmpty() || res.getLast()[1]<pair[0]){
                res.addLast(pair);
            }else{
                res.getLast()[1] = Math.max(res.getLast()[1],pair[1]);
            }
        }

        return res.toArray(new int[res.size()][2]);
    }  
}
// @lc code=end

