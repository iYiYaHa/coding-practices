/*
 * @lc app=leetcode id=295 lang=java
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (43.73%)
 * Likes:    3140
 * Dislikes: 58
 * Total Accepted:    233.3K
 * Total Submissions: 515.7K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */

// @lc code=start
class MedianFinder {
    PriorityQueue<Integer> lessHeap;
    PriorityQueue<Integer> largerHeap;

    /** initialize your data structure here. */
    public MedianFinder() {
        lessHeap = new PriorityQueue<>((a, b) -> {
            if (a < b)
                return 1;
            else
                return -1;
        });
        largerHeap = new PriorityQueue<>();
    }

    public void addNum(int num) {
        if (lessHeap.size() > largerHeap.size()) {
            largerHeap.add(num);
        } else {
            lessHeap.add(num);
        }
        if (!lessHeap.isEmpty() && !largerHeap.isEmpty() && lessHeap.peek() > largerHeap.peek()) {
            int less = lessHeap.remove();
            int larger = largerHeap.remove();
            lessHeap.add(larger);
            largerHeap.add(less);
        }
    }

    public double findMedian() {
        int numCnt = lessHeap.size() + largerHeap.size();
        if ((numCnt & 1) == 0) {
            return (lessHeap.peek() + largerHeap.peek()) / 2.0;
        } else {
            return lessHeap.peek();
        }
    }
}

class MedianFinder {

    private PriorityQueue<Integer> leftPart;
    private PriorityQueue<Integer> rightPart;

    /** initialize your data structure here. */
    public MedianFinder() {
        leftPart = new PriorityQueue<Integer>((a, b) -> b - a);
        rightPart = new PriorityQueue<Integer>();
    }

    public void addNum(int num) {
        if (!rightPart.isEmpty() && rightPart.peek() < num) {
            int tmp = rightPart.poll();
            rightPart.offer(num);
            num = tmp;
        }
        leftPart.offer(num);
        if (leftPart.size() - rightPart.size() > 1) {
            int move = leftPart.poll();
            rightPart.offer(move);
        }
    }

    public double findMedian() {
        int n = leftPart.size() + rightPart.size();
        if (n == 0) {
            return 0;
        }
        if ((n & 1) == 0) {
            return (leftPart.peek() + rightPart.peek()) * 1.0 / 2;
        } else {
            return leftPart.peek();
        }
    }
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder(); obj.addNum(num); double param_2 =
 * obj.findMedian();
 */
// @lc code=end
