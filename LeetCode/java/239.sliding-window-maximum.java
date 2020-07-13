import java.util.Deque;
import java.util.LinkedList;

/*
 * @lc app=leetcode id=239 lang=java
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
    private class Pair {
        int pos;
        int val;

        public Pair(int pos, int val) {
            this.pos = pos;
            this.val = val;
        }

        public int getPos() {
            return this.pos;
        }

        public int getVal() {
            return this.val;
        }
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k < 0 || k > nums.length)
            return null;
        Deque<Pair> deque = new LinkedList<>();
        int[] result = new int[nums.length - k + 1];
        for (int i = 0; i < nums.length; ++i) {
            // Pop out the first;
            if (!deque.isEmpty() && deque.getFirst().getPos() < i - k + 1) {
                deque.removeFirst();
            }

            // Remove useless elements.
            while (!deque.isEmpty() && deque.getLast().getVal() <= nums[i]) {
                deque.removeLast();
            }
            deque.addLast(new Pair(i, nums[i]));
            if (i >= k - 1) {
                result[i - k + 1] = deque.peek().getVal();
            }
        }
        return result;
    }
}


class Solution{
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k < 0 || k > nums.length)
            return null;
        int[] result = new int[nums.length - k + 1];
        int[] leftMax = new int[nums.length + 1];
        int[] rightMax = new int[nums.length + 1];
        for (int i = 0; i < nums.length; ++i) {
            final int j = nums.length - i - 1;
            leftMax[i] = i % k == 0 ? nums[i] : Math.max(nums[i], leftMax[i - 1]);
            rightMax[j] = j % k == 0 ? nums[j] : Math.max(nums[j], rightMax[j + 1]);
        }
        for (int i = 0; i < nums.length - k + 1; ++i) {
            result[i] = Math.max(rightMax[i], leftMax[i + k - 1]);
        }
        return result;
    }
}
// @lc code=end
