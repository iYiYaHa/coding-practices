/*
 * @lc app=leetcode id=69 lang=java
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
    public int mySqrt(int x) {
        double ans = x / 2.0;
        while (Math.abs(x - ans * ans) >= 1e-5) {
            ans = (ans + x / ans) / 2;
        }
        return (int) ans;
    }
}

// @Deprecated
// Failed for the case like 36 !!! since the answer may approximate as 5.99999999 and produce the answer as 5.

class Solution {

    public int mySqrt(int x) {
        double low = 1, high = x;
        while (low <= high) {
            double mid = (low + high) / 2;
            System.out.println(low + " " + mid + " " + high);
            if (Math.abs(x - mid * mid) < 1e-5)
                return (int) mid;
            if (x - mid * mid > 1e-5) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return 0;
    }
}

// Note the difference between the commented line and the uncommented line.
class Solution {
    public int mySqrt(int x) {
        int low = 1, high = x;
        while (low <= high) {
            // int mid = (low + high) / 2;

            int mid = low + (high - low) / 2;

            // if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
            if (mid <= x / mid && (mid + 1) > (x / (mid + 1)))
                return mid;
            // if (x - mid * mid > 0) {
            if (mid < x / mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return 0;
    }
}

// @lc code=end
