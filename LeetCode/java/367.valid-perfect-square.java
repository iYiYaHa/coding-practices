/*
 * @lc app=leetcode id=367 lang=java
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
    public boolean isPerfectSquare(int num) {
        if (num < 0)
            return false;
        double sqrt = num;
        while (Math.abs(num - sqrt * sqrt) > 1e-5) {
            sqrt = (sqrt + num / sqrt) / 2;
        }
        int truncatedSqrt = (int) sqrt;
        return num == truncatedSqrt * truncatedSqrt;
    }
}

class Solution {
    public boolean isPerfectSquare(int num) {
        if (num < 0)
            return false;
        int sqrt = truncatedSqrt(num);
        return num == sqrt * sqrt;
    }

    private int truncatedSqrt(int num) {
        int low = 1, high = num;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid <= num / mid && (mid + 1) > (num / (mid + 1)))
                return mid;
            if (mid < num / mid) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    }
}
// @lc code=end
