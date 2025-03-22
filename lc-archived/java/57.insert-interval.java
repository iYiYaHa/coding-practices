/*
 * @lc app=leetcode id=57 lang=java
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (33.34%)
 * Likes:    2481
 * Dislikes: 229
 * Total Accepted:    317.6K
 * Total Submissions: 911.7K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * Example 3:
 * 
 * 
 * Input: intervals = [], newInterval = [5,7]
 * Output: [[5,7]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: intervals = [[1,5]], newInterval = [2,3]
 * Output: [[1,5]]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: intervals = [[1,5]], newInterval = [2,7]
 * Output: [[1,7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= intervals[i][0] <= intervals[i][1] <= 10^5
 * intervals is sorted by intervals[i][0] in ascending order.
 * newInterval.length == 2
 * 0 <= newInterval[0] <= newInterval[1] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals == null || newInterval == null || newInterval.length <= 0)
            return intervals;

        LinkedList<int[]> res = new LinkedList<>();
        int ind = 0;

        // 左半部分未相交的
        while (ind < intervals.length && intervals[ind][1] < newInterval[0]) {
            res.add(intervals[ind]);
            ++ind;
        }

        res.add(newInterval);
        // 相交的
        while (ind < intervals.length && intervals[ind][0] <= res.getLast()[1]) {
            res.getLast()[0] = Math.min(res.getLast()[0], intervals[ind][0]);
            res.getLast()[1] = Math.max(res.getLast()[1], intervals[ind][1]);
            ++ind;
        }

        // 右半部分未相交的
        while (ind < intervals.length) {
            res.add(intervals[ind]);
            ++ind;
        }
        return res.toArray(new int[res.size()][]);
    }
}
// @lc code=end
